#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int cont_dig(int n, int k){
    return cont_digAux(n, k, 0);
}
int cont_digAux(int n, int k, int quant){
    if(!n) return quant;
    if(n%10 == k) quant++;
    return cont_digAux(n/10, k, quant);
}

int mdc(int x, int y){
    if(x == y) return x;
    if(x > y ) return mdc(x-y, y);
    return mdc(y, x);
}

int mod(int x, int y){
    if(x == y) return 0;
    if(x > y) return mod(x-y, y);
    return x;
}

int tetranacci(int n){
    if(n == 0 || n == 1 || n == 2) return 0;
    if(n == 3) return 1;
    return tetranacci(n-4) + tetranacci(n-3) + tetranacci(n-2)+tetranacci(n-1);
}

int somaN(int n){
    if(!n) return 0;
    return n + somaN(n-1);
}

int prim_alg(int n){
    if(n/10 == 0) return n;
    return prim_alg(n/10);
}

int comtemPar(int *vet, int tam){
    if(!tam) return 0;
    if(vet[tam-1] % 2 == 0) return 1;
    return comtemPar(vet, tam-1);
}

int* inverteVet(int *vet, int tam){
    return inverteVetAux(vet, tam, 0);
}
int* inverteVetAux(int *vet, int tam, int ini){
    if(ini >= tam) return vet;
    int aux = vet[tam-1];
    vet[tam-1] = vet[ini];
    vet[ini] = aux;
    return inverteVetAux(vet, tam-1, ini+1);
}

int* intercala(int *vet1, int tam1, int *vet2, int tam2, int *vet3){
    return intercalaAux(vet1, tam1, vet2, tam2, vet3, 0, 0, 0);
}

int *intercalaAux(int *vet1, int tam1, int *vet2, int tam2, int *vet3, int i, int j, int p){
    if(i >= tam1 && j >= tam2) return vet3;
    if(i < tam1) vet3[p++] = vet1[i];
    if(j < tam2) vet3[p++] = vet2[j];
    return intercalaAux(vet1, tam1, vet2, tam2, vet3, i+1, j+1, p);
}

float mediaVet(int *vet, int tam){
    return mediaVetAux(vet, tam, (float)tam, 0.0);
}
float mediaVetAux(int *vet, int tam, float n, float soma){
    if(!tam) return soma/n;
    return mediaVetAux(vet, tam-1, n, soma+vet[tam-1]);
}

int inverter(int n){
    int pot = 1;
    pot = potencia(n, pot);
    return inverterNaux(n, pot, 0);
}
int potencia(int n, int p){
    if(!n) return p;
    return potencia(n/10, p*10);
}
int inverterNaux(int n, int p, int R){
    if(!n) return R;
    return inverterNaux(n/10, p/10, (R + (n%10) * p));
}

int menorE(int *vet, int tam){
    return menorEaux(vet, tam-1, vet[tam-1]);
}
int menorEaux(int *vet, int tam, int menor){
    if(!tam) return menor;
    if(menor > vet[tam-1]) menor = vet[tam-1];
    return menorEaux(vet, tam-1, menor);
}

int somaDig(int n){
    return somaDigAux(n, 0);
}
int somaDigAux(int n, int S){
    if(!n) return S;
    return somaDigAux(n/10, S+(n%10));
}

float somatorio(int n){
    return somatorioAux(n, 0.0);
}
float somatorioAux(int n, float S){
    if(!n) return S;
    return somatorioAux(n-1, S+(1/n));
}












