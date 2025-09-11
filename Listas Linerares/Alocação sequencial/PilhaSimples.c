#include <stdio.h>
#include <stdlib.h>

// Estrutura que define um nó da pilha
typedef struct {
    int chave;
    int valor;
} pilha;

// Tamanho máximo da pilha
int m = 10;
// Vetor que representa a pilha
int P[10];
// Índice do topo da pilha (inicialmente vazia = -1)
int topo = -1;

// Função que insere um elemento na pilha
int InserePilha(int no){
    int retorno = -1;

    // Verifica se a pilha ainda não está cheia
    if(topo != m - 1){
        topo = topo + 1;   // Avança o topo
        P[topo] = no;      // Insere o elemento no topo
        retorno = topo;    // Retorna a posição onde foi inserido
    }else{
        printf("Erro: Pilha cheia! \n");
    }
    return retorno;
}

// Função que imprime todos os elementos da pilha
void ImprimePilha(){
    printf("Pilha: \n");
    for(int i = 0; i <= topo; i++){
        printf("%d \n", P[i]);
    }
    printf("\n");
}

// Função que remove o elemento do topo da pilha
int removePilha(){
    int retorno = -1;

    if(topo != -1){          // Verifica se a pilha não está vazia
        retorno = P[topo];   // Guarda o valor do topo
        topo = topo - 1;     // Move o topo para baixo
    } else {
        printf("Erro: Pilha vazia! \n");
    }

    return retorno;
}

// Função principal para testar a pilha
int main(){
    // Inserindo elementos na pilha
    InserePilha(10);
    InserePilha(20);
    InserePilha(30);

    // Imprime os elementos
    ImprimePilha();

    // Remove o topo
    int removido = removePilha();
    printf("Elemento removido: %d\n\n", removido);

    // Imprime de novo após remoção
    ImprimePilha();

    return 0;
}
