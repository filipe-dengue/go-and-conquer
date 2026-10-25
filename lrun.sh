#! /bin/bash

FLAGS='-Lraylib/raylib-linux/lib -lraylib -lm -lpthread -ldl -lrt'
INCLUDES='-Iincludes -Iraylib/raylib-linux/include -Iraylib/raygui/src'
RPATH='-Wl,-rpath,$ORIGIN/raylib/raylib-linux/lib' # Caminho biblioteca dinâmica
SRC="src/teste.c"

COMANDO="gcc $SRC $FLAGS $INCLUDES $RPATH -fsanitize=address -o teste.elf"

echo $COMANDO

gcc $SRC $FLAGS $INCLUDES $RPATH -fsanitize=address -o teste.elf
