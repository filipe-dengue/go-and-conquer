#include "utils.h"
#include <stdio.h>

#include <string.h>

#include "game_struct.h"
#include "arena.h"
#include "strings.h"
#include "raylib.h"
#include "save_and_load.h"

int medir_tamanho_arq(FILE *arq){
    char buffer[10];

    int i = 0;

    while(fgets(buffer, 9, arq)) i++;

    rewind(arq);

    return i;
}

Nacao_vec carregar_nacao(){
    char buffer_entrada[KB], buffer[KB];

    FILE *arq = fopen("data/nacoes/nacoes.csv", "r");

    if(!arq){
        printf("Erro ao abrir arquivo nacoes.csv\n");
        return (Nacao_vec){0};
    }

    int tamanho = medir_tamanho_arq(arq);

    Nacao *nacoes = malloc(sizeof(tamanho + 1));

    if(!nacoes){
        printf("Erro ao alocar vetor de nações\n");
        return (Nacao_vec){0};
    }

    Nacao_vec nacao_vec = {
        .vec = nacoes,
        .tamanho = tamanho - 1,
        .texts = arena_init(10 * KB)
    };

    // Ignorando primeira linha
    fgets(buffer_entrada, KB, arq);

    int size_trin, size_original, comeco, color;
    Nacao atual;
    for(int i = 0; fgets(buffer_entrada, KB, arq); i++){
        if(buffer_entrada[0] == '\n') break;

        size_original = strlen(buffer_entrada);
        comeco = 0;

        // Ler id
        trin_antes_de(buffer_entrada, buffer, ';', &comeco, size_original);
        comeco++;
        atual.id = atoi(buffer);
        
        // Ler nome
        size_trin = medir_antes_trin(buffer_entrada, ';', comeco, size_original);
        atual.nome = (char *)arena_alloc(nacao_vec.texts, size_trin);
        trin_antes_de(buffer_entrada, buffer, ';', &comeco, size_original);
        comeco++;
        memcpy(atual.nome, buffer, size_trin);

        // Ler lider
        size_trin = medir_antes_trin(buffer_entrada, ';', comeco, size_original);
        atual.nome_lider = (char *)arena_alloc(nacao_vec.texts, size_trin);
        trin_antes_de(buffer_entrada, buffer, ';', &comeco, size_original);
        comeco++;
        memcpy(atual.nome_lider, buffer, size_trin);

        // Ler cor
        trin_antes_de(buffer_entrada, buffer, '\n', &comeco, size_original);
        comeco++;
        atual.cor = GetColor(atoi(buffer));

        nacao_vec.vec[i] = atual;
    }

    fclose(arq);

    return nacao_vec;
}

void printar_nacoes(Nacao_vec vec){
    Nacao atual;
    for(int i = 0; i < vec.tamanho; i++){
        atual = vec.vec[i];

        printf("%d, %s, %s\n", atual.id, atual.nome, atual.nome_lider);
    }
}

void limpar_vec_nacoes(Nacao_vec *vec){
    free(vec->vec);

    arena_free(vec->texts);

    vec->tamanho = 0;
}