#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fabricante{
    char nome[100];
    char nacionalidade[100];
    int anoFundacao;
}fabr;

int compararStruct(fabr F1, fabr F2){
    int i = 0;
    int k = 0;
    i = strcmp(F1.nome,F2.nome);
    if (!i){// Condição se forem iguais
        k = strcmp(F1.nacionalidade,F2.nacionalidade);
        if (!k){// Condição se forem iguais
            if (F1.anoFundacao > F2.anoFundacao){
                return 1;
            }
        }
    }
    if ((i > 0) || (k > 0)){
        return 1;
    }
    return 0;
}

void troca(fabr * a,fabr *b){
    fabr aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int indeceValorMinimo(fabr * v,int ini, int fim){
    int min = ini;
    int i;
    for (i = ini; i < fim; i++){
        if(compararStruct(v[min],v[i])){
            min = i;
        }
    }
    return min;
}

void selectSort(fabr * v, int n){
    int min;
    int i;
    for(i = 0; i < n-1; i++){
        min = indeceValorMinimo(v,i,n);
        troca(&v[i],&v[min]);
    }
}

int main(){
    int qtFabr = 24;
    int i;

    fabr vetor[24] = {{"Toyota","Japonesa",1956},{"Honda","Inguesa",1990},
    {"Apple","Americana",1980},{"Ford","Inguesa",1950},
    {"Honda","Americana",1985},{"Yamaha","Japonesa",1974},
    {"Apple","Americana",1982},{"Microsoft","Americana",1954},
    {"Fiat","Inguesa",1955},{"Apple","Americana",1982},
    {"Umbro","Brasileira",1959},{"Nike","Americana",1963},
    {"Gucci","Americana",2002},{"Toyota","Chinesa",1956},
    {"Ford","Turca",1950},{"Ford","Turca",1940},
    {"Elgin","Mexicana",1980},{"Sansung","Japonesa",1930}, 
    {"Intel","Americana",1970}, {"Honda","Holandesa",1987},
    {"Bethesda","Irlandesa",2001},{"Honda","Chinesa",1998},
    {"RockStar","Americana",1989},{"Bethesda","Alema",2000},};

    selectSort(vetor,24);

    printf("//Nome//\t//Nacionalidade//\t//AnoFundacao//\n");
    for(i=0;i<qtFabr;i++){
        printf("//%s//\t",vetor[i].nome);
        printf("//%s//\t",vetor[i].nacionalidade);
        printf("\t//%d//\n",vetor[i].anoFundacao);
    }

    system("pause");
}