#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


void insertionSort(fabr * vetor,int n){
    fabr valor;
    int i,j,k;

    for(i=0;i<n;i++){
        valor = vetor[i];
        k=0;
        j = i-1;
        while((j>=0)&&(k==0)){
            if(compararStruct(valor,vetor[j])){
                vetor[j+1] = vetor[j];
                j--;
            }else{
                k = j+1;
            }          
        }
        vetor[k]=  valor;
    }
}

int main(){
	system("color BF");
    int qtFabr = 24;
    int i;

    fabr vetor[24] = {
	{"Toyota","Japonesa",1956},{"Honda","Inguesa",1990},{"Toyota","Chinesa",1956},
    {"Apple","Americana",1980},{"Ford","Inguesa",1950},{"Honda","Americana",1985},
	{"Yamaha","Japonesa",1974},    {"Apple","Americana",1982},{"Microsoft","Americana",1954},
	{"Fiat","Inguesa",1955},{"Apple","Americana",1985},{"Honda","Chinesa",1998},
	{"RockStar","Americana",1989},{"Bethesda","Alema",2000},{"Umbro","Brasileira",1959},
    {"Nike","Americana",1963},{"Gucci","Americana",2002},{"Ford","Turca",1950},
	{"Ford","Turca",1940},{"Elgin","Mexicana",1980},{"Sansung","Japonesa",1930}, 
	{"Intel","Americana",1970}, {"Honda","Holandesa",1987},{"Bethesda","Irlandesa",2001}
	};

    insertionSort(vetor,qtFabr);
    
    printf("//Nome//\t//Nacionalidade//\t//AnoFundacao//\n");
    for(i=0;i<qtFabr;i++){
        printf("//%s//\t",vetor[i].nome);
        printf("//%s//\t",vetor[i].nacionalidade);
        printf("\t//%d//\n",vetor[i].anoFundacao);
    }

    system("pause");
}
