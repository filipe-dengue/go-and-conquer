#include "strings.h"

int medir_antes_trin(const char *origem, char quebra, int comeco, int n){
    int i = 0;
    for(i = 0; comeco < n; comeco++, i++){
        if(origem[comeco] == quebra) return i+1;
    }
}

int trin_antes_de(const char *origem, char *saida, char quebra, int *comeco, int n){
    for(int i = 0; *comeco < n; (*comeco)++, i++){
        if(origem[*comeco] == quebra){
            saida[i] = '\0';
            return i+1;
        }
        
        saida[i] = origem[*comeco];
    }
}