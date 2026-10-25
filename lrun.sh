#! /bin/bash

FLAGS='-Lraylib/raylib-linux/lib -lraylib -lm -lpthread -ldl -lrt'
INCLUDES='-Iincludes -Iraylib/raylib-linux/include -Iraylib/raygui/src'
RPATH='-Wl,-rpath,$ORIGIN/raylib/raylib-linux/lib' # Caminho biblioteca dinâmica

COMANDO="gcc src/*.c $FLAGS $INCLUDES $RPATH -fsanitize=address -o go_and_conquer.elf"

echo $COMANDO

gcc src/*.c -fsanitize=address $FLAGS $INCLUDES $RPATH -o go_and_conquer.elf
