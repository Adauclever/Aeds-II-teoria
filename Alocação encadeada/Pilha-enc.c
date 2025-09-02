#include <stdio.h>
#include <stdlib.h>

// Definição de um nó da pilha
typedef struct no {
    int chave;          // chave de identificação
    int valor;          // valor armazenado
    struct no *prox;    // ponteiro para o próximo nó
} No;

// Função para empilhar (recebe um nó já criado com malloc)
void InserePilha(No *novo, No **topo) {
    novo->prox = *topo;   // novo aponta para o antigo topo
    *topo = novo;         // topo passa a ser o novo nó
}

// Função para desempilhar
No *RemovePilha(No **topo) {
    No *retorno = NULL;

    if (*topo != NULL) {
        retorno = *topo;          // guarda o nó do topo
        *topo = (*topo)->prox;    // move topo para o próximo
    }

    return retorno; // retorna o nó removido
}

int main() {
    No *topo = NULL;   // pilha inicialmente vazia
    No *removido;      // para guardar removidos

    // --- Inserindo nós com malloc ---
    No *n1 = (No*) malloc(sizeof(No));
    n1->chave = 1;
    n1->valor = 10;
    InserePilha(n1, &topo);

    No *n2 = (No*) malloc(sizeof(No));
    n2->chave = 2;
    n2->valor = 20;
    InserePilha(n2, &topo);

    No *n3 = (No*) malloc(sizeof(No));
    n3->chave = 3;
    n3->valor = 30;
    InserePilha(n3, &topo);

    printf("Elementos inseridos na pilha!\n");

    // --- Removendo nós ---
    removido = RemovePilha(&topo);
    if (removido != NULL) {
        printf("Removido -> chave: %d, valor: %d\n", removido->chave, removido->valor);
        free(removido); // libera memória
    }

    removido = RemovePilha(&topo);
    if (removido != NULL) {
        printf("Removido -> chave: %d, valor: %d\n", removido->chave, removido->valor);
        free(removido);
    }

    removido = RemovePilha(&topo);
    if (removido != NULL) {
        printf("Removido -> chave: %d, valor: %d\n", removido->chave, removido->valor);
        free(removido);
    }

    // Tentativa de remover de pilha vazia
    removido = RemovePilha(&topo);
    if (removido == NULL) {
        printf("Pilha vazia, nada a remover!\n");
    }

    return 0;
}
