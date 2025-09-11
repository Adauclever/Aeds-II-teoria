#include <stdio.h>

// Estrutura de cada elemento da lista
typedef struct procura {
    int chave;
    int valor;
} procura;

// Função de busca sequencial com sentinela
int busca(int x, procura L[], int n){
    L[n].chave = x; // sentinela no final
    int i = 0;
    while(L[i].chave != x){
        i++;
    }
    if (i != n){
        return i; // posição encontrada
    } else {
        return -1; // não encontrado
    }
}

// Insere elemento no final da lista
int insere(procura L[], int n, int m, procura no){
    if (n < m){ // ainda cabe no vetor
        if (busca(no.chave, L, n) == -1){ // não encontrado
            L[n] = no; // insere no final
            n++;
            return n; // retorna o novo tamanho
        } else {
            return -1; // já existe
        }
    } else {
        return -2; // não cabe
    }
}

// Remove elemento da lista pela chave
int removeLista(int x, procura L[], int n){
    int indice = busca(x, L, n);
    if(indice != -1){ // encontrou o elemento
        for(int i = indice; i < n - 1; i++){
            L[i] = L[i + 1]; // desloca para esquerda
        }
        n--; // diminui o tamanho
    }
    return n; // retorna o novo tamanho da lista
}

// Imprime todos os elementos da lista
void imprimeLista(procura L[], int n){
    printf("Lista:\n");
    for(int i = 0; i < n; i++){
        printf("Chave: %d, Valor: %d\n", L[i].chave, L[i].valor);
    }
    printf("\n");
}

// Programa principal para testar
int main(){
    int m = 10;         // capacidade máxima
    procura L[11];      // vetor (11 para usar a sentinela em L[n])
    int n = 0;          // tamanho atual da lista

    // Criando alguns nós
    procura a = {1, 100};
    procura b = {2, 200};
    procura c = {3, 300};

    // Inserindo elementos
    n = insere(L, n, m, a);
    n = insere(L, n, m, b);
    n = insere(L, n, m, c);

    // Imprimindo a lista
    imprimeLista(L, n);

    // Removendo a chave 2
    n = removeLista(2, L, n);

    // Imprimindo após a remoção
    imprimeLista(L, n);

    // Buscando a chave 3
    int pos = busca(3, L, n);
    if(pos != -1){
        printf("Elemento chave=3 encontrado na posicao %d (valor=%d)\n", pos, L[pos].valor);
    } else {
        printf("Elemento chave=3 nao encontrado\n");
    }

    return 0;
}
