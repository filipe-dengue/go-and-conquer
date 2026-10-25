#pragma once

#include <stdint.h>
#include <stdlib.h>

// Serve para alocar uma arena com 1 kilobyte
#define SIZE_ARENA_PADRAO 1024

// Alocador de arena
typedef unsigned char byte;

typedef struct Arena{
    byte *dados;
    size_t tamanho_max;
    size_t tamanho_atual;

    struct Arena *prox;
}Arena;

Arena *arena_init(size_t tamanho);
byte *arena_alloc(Arena *a, size_t tamanho_desejado);
void arena_free(Arena *a);
