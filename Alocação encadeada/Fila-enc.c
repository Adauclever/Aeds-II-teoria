#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    int valor;
    struct no *prox;
}No;

void InsereFila(No *x, No **inicio, No **fim){
    if(*fim != NULL){
        (*fim)->prox = x;
    }else {
        *inicio = x;
    }
    *fim = x;
    (*x).prox = NULL;
}

No *removeFila(No **inicio, No **fim){
    No *retorno = NULL;

    if(*inicio != NULL){
        retorno = *inicio;
        *inicio = (*inicio)->prox;
        if(inicio = NULL){
            fim = NULL;
        }
    }
    return retorno;
}