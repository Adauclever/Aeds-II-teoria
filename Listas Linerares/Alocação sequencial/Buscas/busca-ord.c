#include <stdio.h>

    struct procura{
        int chave;
        int valor;
    };

    int buscaord(struct procura L[], int x, int n){
        L[n].chave = x; 
        int i = 0;
        while (L[i].chave < x){
            i++;
        } if(i == n || L[i].chave != x){
            return -1;
        } else {
            return i;
        }

    }

    int main (){
        struct procura L[] = {{1}, {3}, {5}, {7}, {9}, {0}};
        int n = 5;
        int x = 5;

        int resultado = buscaord(L, x, n);
        if (resultado == -1){
            printf ("resultado nao encontrado");
        }else{
            printf ("Elemento encontrado na posicao %d. \n", resultado);
        }
        return 0;
    }