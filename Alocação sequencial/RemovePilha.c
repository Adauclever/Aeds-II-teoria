#include <stdio.h>
typedef struct{
    int chave;
    int valor;
}pilha;

pilha *removePilha(int topo, pilha P[]){
    pilha *retorno = NULL;

    if(topo != -1){
        retorno = &P[topo];
        topo = topo - 1;
    }
    return retorno;
}

int main() {
    pilha P[10];
    int topo = -1;

    P[++topo] = (pilha){1, 100};
    P[++topo] = (pilha){2, 200};
    P[++topo] = (pilha){3, 300};

    pilha *removido = removePilha(topo, P);
    if(removido != NULL) {
        printf("Removido -> chave: %d, valor: %d\n", removido->chave, removido->valor);
    }

    return 0;
}