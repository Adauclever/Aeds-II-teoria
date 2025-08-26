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

int insere (procura L[], int n, int m, procura no){
    if (n < m){ //ainda cabe no vetor
        if (busca(no.chave, L, n) == -1){ // nao encontrado
            L[n] = no; // insere no final
            n++;
            return n; //retorna o novo tamanho
        }else{
            return -1; // ja existe
        }
    }else{
        return -2; //nao cabe
    }
}

int main(){
    int tamanho = 6;
    int n = 0; // vetor começa vazio
    procura L[6];
    procura novo;

    novo.chave = 10;
    novo.valor = 50;

    n = insere(L, n, tamanho, novo);

    if (n > 0){
        printf("Inserido com sucesso! Agora n = %d\n", n);
    } else if (n == -1){
        printf("Elemento ja existe!\n");
    } else {
        printf("Nao ha espaco!\n");
    }

    return 0;
}