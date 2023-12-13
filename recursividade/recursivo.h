#ifndef RECURSIVO_H_INCLUDED
#define RECURSIVO_H_INCLUDED

int soma(int *vet, int tam);

int fibonacci(int n);

void mostraPares(int n);

int encontra_vet(int *vet, int tam, int n);

void mostra_tabuada(int n, int tam);

//---------------------------------------------------
//Lista de funções com recursão de causa
//--------------------------------------------------
int somaAux(int *vet, int tam, int somaNum);

int somaCauda(int *vet, int tam);

int fatorialAux(int num, int result);

int fatorialCauda(int num);

//-------------------------------------------------
//Exercicios 23/10/2023
//-------------------------------------------------
int multiplica(int num1, int num2);
int multiplicaCauda(int num1, int num2);
int multiplicaAux(int num1, int num2, int result);

int encontraPosicao(int *vet, int tam, int valor);

int maxi(int *vet, int tam);
int maxiAux(int *vet, int tam, int maior);

float somatorioFatAux(int num, float R);
float somatorioFat(int num);

int* inverteVetorAux(int *vet, int tam, int ini);
int* inverteVetor(int *vet, int tam);

#endif // RECURSIVO_H_INCLUDED
