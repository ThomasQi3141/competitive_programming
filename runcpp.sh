#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 ]]; then
  echo "Usage: $0 path/to/program.cpp [program args...] [--debug|-d] [--san] [--valgrind|-v]" >&2
  exit 1
fi

DEBUG=0
SAN=0
VALGRIND=0

CPP_FILE="$1"
shift

PROG_ARGS=()
for arg in "$@"; do
  case "$arg" in
    --debug|-d)
      DEBUG=1
      ;;
    --san)
      SAN=1
      DEBUG=1
      ;;
    --valgrind|-v)
      VALGRIND=1
      DEBUG=1
      ;;
    *)
      PROG_ARGS+=("$arg")
      ;;
  esac
done

if [[ ! -f "$CPP_FILE" ]]; then
  echo "Error: file not found: $CPP_FILE" >&2
  exit 1
fi

GPP="$(command -v g++-15 || true)"
CLANGPP="$(command -v clang++ || true)"
VALGRIND_BIN="$(command -v valgrind || true)"

if [[ -z "$GPP" ]]; then
  echo "Error: g++-15 not found on PATH. Install with: brew install gcc" >&2
  exit 1
fi

if [[ -z "$CLANGPP" ]]; then
  echo "Error: clang++ not found on PATH." >&2
  exit 1
fi

if [[ $VALGRIND -eq 1 && -z "$VALGRIND_BIN" ]]; then
  echo "Error: valgrind not found on PATH." >&2
  exit 1
fi

if [[ $SAN -eq 1 && $VALGRIND -eq 1 ]]; then
  echo "Error: use either --san or --valgrind, not both." >&2
  exit 1
fi

OUT="a.out"
TMP_OUT="$(mktemp -t runcpp_out.XXXXXX)"
TMP_ERR="$(mktemp -t runcpp_err.XXXXXX)"

cleanup() {
  rm -f "$TMP_OUT" "$TMP_ERR"
}
trap cleanup EXIT

# Choose compiler + flags
if [[ $DEBUG -eq 1 ]]; then
  echo "----- COMPILING (DEBUG) -----" >&2

  if [[ $SAN -eq 1 ]]; then
    echo "----- (with SANITIZERS via clang++) -----" >&2
    COMPILER="$CLANGPP"
    CXXFLAGS=(
      -std=gnu++23
      -O0
      -g3
      -DLOCAL
      -fsanitize=address,undefined
      -fno-omit-frame-pointer
    )

  elif [[ $VALGRIND -eq 1 ]]; then
    echo "----- (Valgrind debug build via clang++) -----" >&2
    COMPILER="$CLANGPP"
    CXXFLAGS=(
      -std=gnu++23
      -O0
      -g3
      -DLOCAL
      -fno-omit-frame-pointer
      -fno-inline
    )

  else
    COMPILER="$GPP"
    CXXFLAGS=(
      -std=gnu++23
      -O0
      -g3
      -DLOCAL
      -fno-omit-frame-pointer
    )
  fi

else
  echo "----- COMPILING (RELEASE) -----" >&2
  COMPILER="$GPP"
  CXXFLAGS=(
    -std=gnu++23
    -O2
  )
fi

"$COMPILER" "${CXXFLAGS[@]}" "$CPP_FILE" -o "$OUT"

echo "------ RUNNING ------" >&2

if [[ $VALGRIND -eq 1 ]]; then
  RUN_CMD=(
    "$VALGRIND_BIN"
    --leak-check=full
    --show-leak-kinds=all
    --track-origins=yes
    --num-callers=30
    --error-exitcode=99
    "./$OUT"
    "${PROG_ARGS[@]}"
  )
else
  RUN_CMD=(
    "./$OUT"
    "${PROG_ARGS[@]}"
  )
fi

set +e
"${RUN_CMD[@]}" > "$TMP_OUT" 2> "$TMP_ERR"
STATUS=$?
set -e

# Only show stderr section in debug mode
if [[ $DEBUG -eq 1 ]]; then
  echo "========== STDERR (cerr / debug output) ==========" >&2
  if [[ -s "$TMP_ERR" ]]; then
    cat "$TMP_ERR" >&2
  else
    echo "(empty)" >&2
  fi
  echo "==================================================" >&2
fi

echo "========== STDOUT (cout) ==========" >&2
cat "$TMP_OUT"
echo "===================================" >&2

if [[ $STATUS -ne 0 ]]; then
  echo "Program exited with status $STATUS" >&2
fi

exit "$STATUS"