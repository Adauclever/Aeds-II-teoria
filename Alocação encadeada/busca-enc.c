#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chave;
    int valor;
    struct no *prox;
}No;

void buscaenc(No *lista, int x, No **ant, No **pont){
    *ant = lista;
    *pont = NULL;
    No *ptr = lista->prox;

    while(ptr != NULL){
        if (ptr->chave < x){
            *ant = ptr;
            ptr = ptr->prox;
        }else if (ptr->chave == x){
            *pont = ptr;
            ptr = NULL;
        }else{
             ptr = NULL;
        }
    }
}

    int InsereEnc(No *lista, No *inserido){
        int retorno = -1;
        No *ant; No *pont;
        buscaenc(lista, inserido->chave, &ant, &pont);

        if(pont == NULL){
            inserido->prox = ant->prox;
            ant->prox = inserido;
            retorno = 0;
        }
        return retorno;
    }

    No *remove(No *lista, No *removido){
        int retorno = NULL;
        buscaenec(lista, removido->chave, &ant, &pont)
    }

