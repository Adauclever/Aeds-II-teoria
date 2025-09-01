#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chave;
    int valor;
    struct no *prox;
}No;

void BuscaEnc(No *lista, int x, No **ant, No **pont){
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

    No *remove(No *lista, int x){
        No  *retorno = NULL;
        No *ant; No *pont;
        buscaenec(lista, x, &ant, &pont);
        if(pont !=NULL){
            ant->prox = pont->prox;
            retorno = pont;
        }
        return retorno;
    }

    No *criaNo(int x){
        No *nonoNo = (No *) malloc(sizeof(No));
        
        if(nonoNo == NULL){
            printf("\nErro ao alocar memoria\n"); 
        return NULL; 
        }
        nonoNo->chave = x;
        nonoNo->prox = NULL;

        return nonoNo;
    }


    void imprimeLista(No *lista){
        No *aux = lista->prox;

        while(aux != NULL){
            printf("%d -> ", aux->chave);
        aux = aux->prox;
        }
            printf("NULL\n");
    }

    void liberaLista(No *lista){
    No *aux = lista->prox; 

    while(aux != NULL){ 
       No *aux2 = aux->prox; 
        free(aux); 
        aux = aux2; 
        printf("\nLimpou no");
    }
    free(lista); 
    printf("\n\nLimpou ptlista"); 
}

    