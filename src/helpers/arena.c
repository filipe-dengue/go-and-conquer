#include "arena.h"
#include <stddef.h>
#include <stdio.h>

// Inicial uma arena
Arena *arena_init(size_t tamanho){
    Arena *a = malloc(sizeof(Arena));

    if(!a) return NULL;

    a->tamanho_atual = 0;
    a->tamanho_max = tamanho;
    a->dados = (byte *)malloc(tamanho);
    a->prox = NULL;

    return a;
}

// Aloca memória
byte *arena_alloc(Arena *a, size_t tamanho_desejado){
    if(tamanho_desejado >= a->tamanho_max || !a) return NULL;

    if(a->tamanho_atual + tamanho_desejado < a->tamanho_max){
        byte *p = a->dados + a->tamanho_atual;

        a->tamanho_atual += tamanho_desejado;

        return p;
    }

    if(!a->prox){
        a->prox = arena_init(a->tamanho_max);

        if(!a->prox) return NULL;
    }

    return arena_alloc(a->prox, tamanho_desejado);
}

// Limpa a arena
void arena_free(Arena *a){
    if(!a) return;

    free(a->dados);

    arena_free(a->prox);

    free(a);
}
