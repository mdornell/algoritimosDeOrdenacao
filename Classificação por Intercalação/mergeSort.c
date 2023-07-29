#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1;
#define False 0;

typedef struct fabricante{
    char nome[100];
    char nacionalidade[100];
    int anoFundacao;
}fabr;

int compararStruct(fabr F1, fabr F2){ // Faz a comparação retorne apenas dois valores ao inves de 3 no caso do strcmp
    int i = 0;                        // sendo se deve trocar ou não o valor 
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

int min(int a, int b){
    if(a > b){
        return b;
    }else{
        return a;
    }

    // return (a > b) ? b : a;
}

void simpleMerge(fabr * v, int is1, int fs1, int is2, int fs2, fabr * vResultado, int r){
    int i;
    int iniSeg1 = is1;
    int fimSeg1 = fs1;
    int iniSeg2 = is2;
    int fimSeg2 = fs2;
    int k = r;
    while((iniSeg1 <= fs1)&&(iniSeg2 <= fs2)){
        if(compararStruct(v[iniSeg2], v[iniSeg1])){
            vResultado[k] = v[iniSeg1];
            iniSeg1++;
        }else{
            vResultado[k] = v[iniSeg2];
            iniSeg2++;
        }
        k++;
    } 
    if(iniSeg1 > fs1){
        for(i = iniSeg2; i <=fs2 ; i++){
            vResultado[k] = v[i];
            k++;
        }
    }else{
        for(i = iniSeg1; i <= fs1 ; i++){
            vResultado[k] = v[i];
            k++;
        }
    }
}

void mergePass(fabr * v,fabr * vResultado,int n, int L){
    int i;
    int p = 0;
    int q = p + L;
    int r = 0;
    while(q < n){
        simpleMerge(v, p, q-1, q, min(q+L-1,n-1), vResultado, r);
        r = r + 2 * L;
        p = q + L;
        q = p + L;
    }
    if(p < n){
        for(i = p; i < n; i++){
            vResultado[i] = v[i];
        }
    }
}

void mergeSort(fabr * v, int n){
    int i;
    fabr * vReusltado  = (fabr *)malloc(n * sizeof(fabr));
    int L = 1;
    int ehPar = True;
    while(L < n){
        if(ehPar){
            mergePass(v,vReusltado,n,L);
            ehPar = False;
        }else{
            mergePass(vReusltado,v,n,L);
            ehPar = True;
        }
        L = L * 2;
    }
    if(!ehPar){
        for(i = 0;i < n; i++){
            v[i] = vReusltado[i];
        }
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

    mergeSort(vetor,24);

    printf("//Nome//\t//Nacionalidade//\t//AnoFundacao//\n");
    for(i=0;i<qtFabr;i++){
        printf("//%s//\t",vetor[i].nome);
        printf("//%s//\t",vetor[i].nacionalidade);
        printf("\t//%d//\n",vetor[i].anoFundacao);
    }

    system("pause");
}