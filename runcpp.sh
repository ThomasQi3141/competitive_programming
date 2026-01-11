#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 ]]; then
  echo "Usage: $0 path/to/program.cpp [program args...]" >&2
  exit 1
fi

CPP_FILE="$1"
shift

if [[ ! -f "$CPP_FILE" ]]; then
  echo "Error: file not found: $CPP_FILE" >&2
  exit 1
fi

COMPILER="$(command -v g++-15 || true)"
if [[ -z "$COMPILER" ]]; then
  echo "Error: g++-15 not found on PATH." >&2
  echo "Install with: brew install gcc" >&2
  exit 1
fi

OUT="a.out"
TMP_OUT="$(mktemp -t runcpp_out.XXXXXX)"
TMP_ERR="$(mktemp -t runcpp_err.XXXXXX)"

cleanup() {
  rm -f "$TMP_OUT" "$TMP_ERR"
}
trap cleanup EXIT

echo "----- COMPILING -----" >&2
"$COMPILER" -std=gnu++23 -O2 "$CPP_FILE" -o "$OUT"

echo "------ RUNNING ------" >&2
# capture stdout and stderr separately
./"$OUT" "$@" > "$TMP_OUT" 2> "$TMP_ERR"

echo "========== STDERR (cerr) ==========" >&2
if [[ -s "$TMP_ERR" ]]; then
  cat "$TMP_ERR"
else
  echo "(empty)" >&2
fi
echo "===================================" >&2

echo "========== STDOUT (cout) ==========" >&2
cat "$TMP_OUT"
echo "===================================" >&2
