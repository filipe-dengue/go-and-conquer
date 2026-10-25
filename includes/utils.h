#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "raylib.h"

typedef enum{
    TELA_MENU,
    TELA_PREFERENCIAS,
    TELA_EDITOR,
    TELA_JOGO
}Tela;

typedef struct{
    Tela atual;
}EstadoGame;
