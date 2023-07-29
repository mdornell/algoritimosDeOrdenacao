#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM 1000

typedef struct fabricante{
    char nome[100];
    char nacionalidade[100];
    int anoFundacao;
}fabr;


int compararStruct(fabr F1, fabr F2){
    int i = 0;
    int k = 0;
    i = strcmp(F2.nome,F1.nome);
    if (!i){// Condição se forem iguais
        k = strcmp(F2.nacionalidade,F1.nacionalidade);
        if (!k){// Condição se forem iguais
            if (F2.anoFundacao > F1.anoFundacao){
                return 1;
            }
        }
    }
    if ((i > 0) || (k > 0)){
        return 1;
    }
    return (0);
}

void insertionSortAdaptado(fabr * vetor,int n,int f, int h){
    fabr valor;
    int i,j,k;
    int troca;

    for( i = f+h; i < n; i = i+h){
        valor = vetor[i];
        k = f;
        j = i-h;
        while((j>=f)&&(k==f)){
            if(compararStruct(valor,vetor[j])){
                vetor[j+h] = vetor[j];
                j = j-h;
            }else{
                k = j+h;
            }                   
        }
        vetor[k]=  valor;
    }
}

void shellSort(fabr * vetor,int n, int np){
    int h;
    int p,j;

    for(p = np; p>0; p--){
        h = (int)pow(2.0, (int)p-1);
        for(j=0; j<h; j++){
            insertionSortAdaptado(vetor,n,j,h);
        }
    }
}


int main(){
    int qtFabr = 24;
    int i;

    fabr vetor[24] = {{"Toyota","Japonesa",1956},{"Honda","Inguesa",1990},{"Toyota","Chinesa",1956},
    {"Apple","Americana",1980},{"Ford","Inguesa",1950},{"Honda","Americana",1985},{"Yamaha","Japonesa",1974},
    {"Apple","Americana",1982},{"Microsoft","Americana",1954},{"Fiat","Inguesa",1955},{"Apple","Americana",1985},
    {"Honda","Chinesa",1998},{"RockStar","Americana",1989},{"Bethesda","Alema",2000},{"Umbro","Brasileira",1959},
    {"Nike","Americana",1963},{"Gucci","Americana",2002},{"Ford","Turca",1950},{"Ford","Turca",1940},
    {"Elgin","Mexicana",1980},{"Sansung","Japonesa",1930}, {"Intel","Americana",1970}, {"Honda","Holandesa",1987},
    {"Bethesda","Irlandesa",2001}};

    shellSort(vetor,qtFabr,24);
    
    printf("//Nome//\t//Nacionalidade//\t//AnoFundacao//\n");
    for(i=0;i<qtFabr;i++){
        printf("//%s//\t",vetor[i].nome);
        printf("//%s//\t",vetor[i].nacionalidade);
        printf("\t//%d//\n",vetor[i].anoFundacao);
    }

	system("pause");
}
