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

cleanup() {
  rm -f "$TMP_OUT"
}
trap cleanup EXIT

echo "----- COMPILING -----" >&2
"$COMPILER" -std=gnu++23 -O2 "$CPP_FILE" -o "$OUT"

echo "------ RUNNING ------" >&2
# capture program stdout to temp file; keep stderr visible
./"$OUT" "$@" > "$TMP_OUT"

echo "========== OUTPUT ==========" >&2
cat "$TMP_OUT"
echo "============================" >&2
