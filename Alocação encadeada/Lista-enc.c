#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct no {
    int chave;          // valor armazenado
    int valor;          // não está sendo usado, mas pode ser útil
    struct no *prox;    // ponteiro para o próximo nó
} No;

// ------------------- BUSCA -------------------
void BuscaEnc(No *lista, int x, No **ant, No **pont) {
    *ant = lista;       // começa com "ant" no nó cabeça
    *pont = NULL;
    No *ptr = lista->prox;

    while (ptr != NULL) {
        if (ptr->chave < x) {
            *ant = ptr;        // avança o anterior
            ptr = ptr->prox;   // continua procurando
        } else if (ptr->chave == x) {
            *pont = ptr;       // achou o elemento
            ptr = NULL;        // para o loop
        } else {
            ptr = NULL;        // lista é ordenada, então pode parar
        }
    }
}

// ------------------- INSERÇÃO -------------------
int InsereEnc(No *lista, No *inserido) {
    int retorno = -1;
    No *ant, *pont;

    BuscaEnc(lista, inserido->chave, &ant, &pont);

    if (pont == NULL) { // só insere se não achou chave igual
        inserido->prox = ant->prox;
        ant->prox = inserido;
        retorno = 0; // sucesso
    }
    return retorno;
}

// ------------------- REMOÇÃO -------------------
No *RemoveEnc(No *lista, int x) {
    No *retorno = NULL;
    No *ant, *pont;

    BuscaEnc(lista, x, &ant, &pont);

    if (pont != NULL) {       // se achou
        ant->prox = pont->prox; // retira da lista
        retorno = pont;         // retorna o nó removido
    }
    return retorno;
}

// ------------------- CRIA NÓ -------------------
No *criaNo(int x) {
    No *novoNo = (No *) malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("\nErro ao alocar memoria\n");
        return NULL;
    }
    novoNo->chave = x;
    novoNo->valor = 0; // default
    novoNo->prox = NULL;
    return novoNo;
}

// ------------------- IMPRIME -------------------
void imprimeLista(No *lista) {
    No *aux = lista->prox; // ignora o nó cabeça

    while (aux != NULL) {
        printf("%d -> ", aux->chave);
        aux = aux->prox;
    }
    printf("NULL\n");
}

// ------------------- LIBERA -------------------
void liberaLista(No *lista) {
    No *aux = lista->prox;

    while (aux != NULL) {
        No *aux2 = aux->prox;
        free(aux);
        aux = aux2;
        printf("\nLimpou nó");
    }

    free(lista); // libera nó cabeça
    printf("\n\nLimpou nó cabeça\n");
}

// ------------------- MAIN -------------------
int main() {
    // Cria lista com nó cabeça
    No *lista = (No *) malloc(sizeof(No));
    lista->prox = NULL;

    printf("Lista criada!\n");

    // Inserindo elementos
    InsereEnc(lista, criaNo(10));
    InsereEnc(lista, criaNo(5));
    InsereEnc(lista, criaNo(20));
    InsereEnc(lista, criaNo(15));

    printf("\nLista apos insercoes:\n");
    imprimeLista(lista);

    // Removendo elemento
    No *removido = RemoveEnc(lista, 10);
    if (removido != NULL) {
        printf("\nRemovido: %d\n", removido->chave);
        free(removido); // libera memória do nó removido
    }

    printf("\nLista apos remocao:\n");
    imprimeLista(lista);

    // Liberando lista
    liberaLista(lista);

    return 0;
}    