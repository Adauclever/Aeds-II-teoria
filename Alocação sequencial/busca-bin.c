#include <stdio.h>
#include <math.h>
    
struct procura{
        int chave;
        int valor;
    };

    int buscabin (struct procura L[], int n, int x){
        int inf = 0;
        int sup = n;
        int buscabin = -1;
        int meio;
        while (inf <= sup){
            meio = floor((inf + sup)/2);
        } if (L[meio].chave == x){
            buscabin = meio;
            inf = sup++;
        } else if( L[meio].chave < x){
                inf = meio++;
        } else {
            sup = meio--;
        }
        return buscabin;
    }
    