#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
java -Djna.library.path="$SCRIPT_DIR" \
     -jar "$SCRIPT_DIR/jna-bibliotecas-completo.jar"
