#include <stdlib.h>
#include <stdio.h>
#include "recursivo.h"

int soma(int *vet, int tam){
    if(tam == 0) return 0;
    return vet[tam-1] + soma(vet, tam-1);
}

void mostraPares(int n){
    if(n == 0){
        printf("\t%d", n);
    }
    else {
        mostraPares(n-1);
        if (n % 2 ==  0) {
            printf("\t%d", n);
        }

    }
}

int fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int encontra_vet(int *vet, int tam, int n){
    if(vet[tam-1] == n) return tam-1;
    if(vet[tam-1] != n && !tam) return -1;
    encontra_vet(vet, tam-1, n);
}

void mostra_tabuada(int n, int tam){
    if(tam == 0) printf("\t%d * %d = %d\n", n, tam, 0);
    else{
        mostra_tabuada(n, tam-1);
        printf("\t%d * %d = %d\n", n, tam, n * tam);
    }

}

//--------------------------------------------------------------
// Recursão de cauda
//--------------------------------------------------------------

int somaAux(int *vet, int tam, int somaNum){
    if(!tam) return somaNum;
    return somaAux(vet, tam-1, somaNum+=vet[tam-1]);
}

int somaCauda(int *vet, int tam){
    return somaAux(vet, tam, 0);
}

int fatorialAux(int num, int result){
    if((num == 1) || num == 0) return result;
    return fatorialAux(num-1, result *= num);
}

int fatorialCauda(int num){
    return fatorialAux(num, 1);
}

//-------------------------------------------------
//Exercicios 23/10/2023
//-------------------------------------------------

int multiplica(int num1, int num2){
    if(!num2) return 0;
    return num1 + multiplica(num1, num2-1);
}

int multiplicaAux(int num1, int num2, int result){
    if(!num2) return result;
    return multiplicaAux(num1, num2-1, result+=num1);
}

int multiplicaCauda(int num1, int num2){
    return multiplicaAux(num1, num2, 0);
}

int encontraPosicao(int *vet, int tam, int valor){
    if(vet[tam-1] == valor) return 1;
    if(!tam) return 0;
    return encontraPosicao(vet, tam-1, valor);
}

int maxiAux(int *vet, int tam, int maior){
    if(!tam) return maior;
    maior = (maior >= vet[tam-2]) ? maior : vet[tam-2];
    return maxiAux(vet, tam-1, maior);
}

int maxi(int *vet, int tam){
    return maxiAux(vet, tam, vet[tam-1]);
}

//------------------------------------------------------
//Funções para praticar
//------------------------------------------------------
float somatorioFatAux(int num, float R){
    if(!num) return R;
    R+=(1.0 / fatorialCauda(num));
    return somatorioFatAux(num-1, R);

}

float somatorioFat(int num){
    return somatorioFatAux(num, 0);
}

int* inverteVetorAux(int *vet, int tam, int ini){
    int aux;
    if(ini >= tam) return vet;
    aux = vet[tam-1];
    vet[tam-1] = vet[ini];
    vet[ini] = aux;
    return inverteVetorAux(vet, tam-1, ini+1);
}

int* inverteVetor(int *vet, int tam){
    return inverteVetorAux(vet, tam, 0);
}

