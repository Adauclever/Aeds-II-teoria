#include <stdio.h>
int m = 10;
int P[10];
int topo = -1;

int InserePilha(int no){
    int retorno = -1;

    if(topo != m - 1){
        topo = topo + 1;
        P[topo] = no;
        retorno = topo;
    }else{
        printf("Erro: Pilha cheia! \n");
    }
    return retorno;
}

void ImprimePilha(){
    printf("Pilha: \n");
    for(int i = 0; i <= topo; i++){
        printf("%d \n", P[i]);
    }
    printf("\n");
}

int main(){

InserePilha (10);
InserePilha (4);
InserePilha (29);
InserePilha (13);
InserePilha (5);
InserePilha (92);

ImprimePilha ();


    return 0;
}