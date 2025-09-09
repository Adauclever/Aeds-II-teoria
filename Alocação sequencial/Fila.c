#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chave;
    int valor;
} no;

// variáveis globais
int f = -1, r = -1;     // f = frente da fila, r = retaguarda da fila
const int M = 5;        // tamanho máximo da fila
no F[5];                // vetor que armazena os elementos da fila

// Função para inserir elemento na fila
int InsereFila(no x) {
    int prov = (r + 1) % M; // próxima posição circular
    if (prov != f) {        // só insere se a fila não estiver cheia
        r = prov;
        F[r] = x;           // armazena o elemento
        if (f == -1)        // se for o primeiro elemento, ajusta a frente
            f = 0;
        return r;           // retorna a posição inserida
    }
    return -1;              // erro (fila cheia)
}

// Função para remover elemento da fila
no *removeLista() {
    no *retorno = NULL;

    if (f != -1) {            // só remove se a fila não estiver vazia
        retorno = &F[f];      // pega endereço do elemento na frente
        if (f == r) {         // se só tinha um elemento
            f = -1;
            r = -1;
        } else {
            f = (f + 1) % M;  // avança circularmente
        }
    }
    return retorno;           // retorna ponteiro para o nó removido
}

// Função principal
int main() {
    no elemento;
    no *removido;

    // Inserindo elementos
    for (int i = 0; i < 6; i++) {   // tenta inserir 6 elementos (um a mais que a capacidade)
        elemento.chave = i;
        elemento.valor = i * 10;
        if (InsereFila(elemento) != -1)
            printf("Inserido: chave=%d, valor=%d\n", elemento.chave, elemento.valor);
        else
            printf("Fila cheia! Nao foi possivel inserir chave=%d\n", elemento.chave);
    }

    // Removendo elementos
    for (int i = 0; i < 6; i++) {   // tenta remover 6 vezes
        removido = removeLista();
        if (removido != NULL)
            printf("Removido: chave=%d, valor=%d\n", removido->chave, removido->valor);
        else
            printf("Fila vazia! Nada para remover.\n");
    }

    return 0;
}


