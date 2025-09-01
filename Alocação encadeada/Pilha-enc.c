#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    int valor;
    struct no *prox;
}No;

void InserePilha(int chave, int valor, No **topo){
    No *novo = (No*) malloc(sizeof(No));
        novo->chave = chave;
        novo->valor = valor;
        novo->prox = *topo;
        *topo = novo;
}

No *RemovePilha (No **topo){
     No *retorno = NULL;

        if(topo != NULL){
            retorno = topo;
            topo = (*topo)->prox;
            return retorno;
        }
        return NULL;
}