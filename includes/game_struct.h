#pragma once

#include <stdint.h>
#include "raylib.h"
#include "arena.h"

typedef struct{
    char *nome;
    char *nome_lider;
    Color cor;
    uint32_t id;
}Nacao;

typedef struct
{
    Nacao *vec;
    size_t tamanho;
    Arena *texts;
}Nacao_vec;
