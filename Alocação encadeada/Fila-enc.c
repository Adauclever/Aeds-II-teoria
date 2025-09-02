#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da fila
typedef struct no {
    int chave;
    int valor;
    struct no *prox;
} No;

// ------------------- INSERE NA FILA -------------------
void InsereFila(No *x, No **inicio, No **fim) {
    if (*fim != NULL) {
        // se já existe fim, liga o último elemento ao novo
        (*fim)->prox = x;
    } else {
        // se a fila estava vazia, o novo é também o início
        *inicio = x;
    }
    *fim = x;      // atualiza o fim para o novo nó
    x->prox = NULL; // último elemento aponta para NULL
}

// ------------------- REMOVE DA FILA -------------------
No *removeFila(No **inicio, No **fim) {
    No *retorno = NULL;

    if (*inicio != NULL) {         // só remove se não estiver vazia
        retorno = *inicio;         // guarda o primeiro
        *inicio = (*inicio)->prox; // move o início para o próximo
        if (*inicio == NULL) {     // se ficou vazia
            *fim = NULL;           // fim também precisa virar NULL
        }
    }
    return retorno;
}

// ------------------- MAIN PARA TESTE -------------------
int main() {
    No *inicio = NULL; // fila começa vazia
    No *fim = NULL;
    No *removido;

    // Criando 3 nós manualmente
    No *n1 = (No*) malloc(sizeof(No));
    n1->chave = 1; n1->valor = 10;

    No *n2 = (No*) malloc(sizeof(No));
    n2->chave = 2; n2->valor = 20;

    No *n3 = (No*) malloc(sizeof(No));
    n3->chave = 3; n3->valor = 30;

    // Inserindo na fila
    InsereFila(n1, &inicio, &fim);
    InsereFila(n2, &inicio, &fim);
    InsereFila(n3, &inicio, &fim);

    printf("Fila criada: 1 -> 2 -> 3\n");

    // Removendo da fila (ordem FIFO)
    removido = removeFila(&inicio, &fim);
    if (removido != NULL) {
        printf("Removido: chave=%d, valor=%d\n", removido->chave, removido->valor);
        free(removido);
    }

    removido = removeFila(&inicio, &fim);
    if (removido != NULL) {
        printf("Removido: chave=%d, valor=%d\n", removido->chave, removido->valor);
        free(removido);
    }

    removido = removeFila(&inicio, &fim);
    if (removido != NULL) {
        printf("Removido: chave=%d, valor=%d\n", removido->chave, removido->valor);
        free(removido);
    }

    // Tentando remover de fila vazia
    removido = removeFila(&inicio, &fim);
    if (removido == NULL) {
        printf("Fila vazia, nada a remover!\n");
    }

    return 0;
}
