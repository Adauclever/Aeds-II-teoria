#include <stdio.h>

typedef struct procura {
    int chave;
    int valor;
}procura;

int busca(int x, procura L[], int n){
    L[n].chave = x; //sentinela
    int i = 0;
    while(L[i].chave != x){
        i++;
    }
    if (i != n){
        return i; // posicao encontrada 
    } else {
        return -1; // nao encontrado
    }
}

