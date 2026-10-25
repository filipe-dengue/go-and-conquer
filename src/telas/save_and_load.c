#include "save_and_load.h"
#include "utils.h"
#include <stdio.h>

bool salva_nacao(Nacao *n){
    char buffer[MAX_STRING * 2];
    sprintf(buffer, "data/nations/%d.txt", n->id);

    FILE *f = fopen(buffer, "w");

    if(!f) return false;

    fprintf(f, "%d\n", n->id);
    fprintf(f, "%s\n", n->nome);
    fprintf(f, "%s\n", n->nome_lider);
    fprintf(f, "%d\n%d\n%d\n%d\n", n->cor.r, n->cor.g, n->cor.b, n->cor.a);

    fclose(f);
    return true;
}
