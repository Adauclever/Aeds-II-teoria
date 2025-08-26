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

procura *removeLista(int x, procura L[], int n){
    int indice = -1; 
    procura *retorno = NULL;
    if(n != 0){
        indice = busca(x, L, n);
        if(indice != -1){
            retorno = &L[indice];
            for(int i = indice; i < n; i++){
                L[i] = L[i + 1];
            }
            n--;
        }
        }
    return retorno;
    }

 int main() {
    procura L[10] = { {1,10}, {2,20}, {3,30}, {4,40} };
    int n = 4; // quantidade de elementos

    procura *removido = removeLista(2, L, n);

    if (removido != NULL) {
        printf("Elemento removido: %p\n", removido->chave);
        printf("Lista apos a remocao:\n");
        for (int i = 0; i < n; i++) {
            printf("chave=%d valor=%d\n", L[i].chave, L[i].valor);
        }
    } else {
        printf("Elemento nao encontrado!\n");
    }

    return 0;
}
