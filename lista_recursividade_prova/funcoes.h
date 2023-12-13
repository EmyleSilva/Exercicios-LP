#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

// Ocorrencia de um digito k, em um numero n
int cont_dig(int n, int k);
int cont_digAux(int n, int k, int quant);

//Calculo de MDC entre x e y
int mdc(int x, int y);

//Calculo de mod entre x e y
int mod(int x, int y);

//N-esimo numero de tetrabonacci
int tetranacci(int n);

//soma dos n primeiros numeros inteiros
int somaN(int n);
int somaNCauda(int n);
int somaNaux(int n, int S);

//Retorna o algaritmo mais significativo
int prim_alg(int n);

//Verificar se existem numeros pares no vetor
int comtemPar(int *vet, int tam);

//Inverte um vetor
int* inverteVet(int *vet, int tam);
int* inverteVetAux(int *vet, int tam, int ini);

//Intercala valores de 2 vetores
int* intercala(int *vet1, int tam1, int *vet2, int tam2, int *vet3);
int *intercalaAux(int *vet1, int tam1, int *vet2, int tam2, int *vet3, int i, int j, int p);

//Media dos elementos de um vetor
float mediaVet(int *vet, int tam);
float mediaVetAux(int *vet, int tam, float n,float soma);

//Inverte um numero inteiro
int inverter(int n);
int potencia(int n, int p);
int inverterNaux(int n, int p, int R);

//encontra o menor elemento de um vetor
int menorE(int *vet, int tam);
int menorEaux(int *vet, int tam, int menor);

//Soma os digitos de um numero n
int somaDig(int n);
int somaDigAux(int n, int S);

//Faz o somatorio de 1 + 1/2 + 1/3 + ... + 1/n
float somatorio(int n);
float somatorioAux(int n, float S);


#endif // FUNCOES_H_INCLUDED
