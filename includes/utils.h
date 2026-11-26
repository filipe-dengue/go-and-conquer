#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "raylib.h"

#define MAX_STRING 128

typedef enum{
    TELA_MENU,
    TELA_PREFERENCIAS,
    TELA_EDITOR_NACOES,
    TELA_JOGO,
    INIT_EDITOR_NACOES,
    SAIR_EDITOR_NACOES
}Tela;

typedef struct{
    Tela atual;
}EstadoGame;

