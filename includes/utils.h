#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum{
    TELA_MENU
}Tela;

typedef struct{
    Tela atual;
}EstadoGame;
