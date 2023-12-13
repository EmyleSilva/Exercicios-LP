#include <stdio.h>
#include <stdlib.h>
#include "recursivo.h"

int main()
{
    int tam = 5;
    int *vet = (int *)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++) vet[i] = i+1;
    printf("\n\tVetor original: ");
    for(int i = 0; i < tam; i++) printf("\t%d", vet[i]);
    vet = inverteVetor(vet, tam);
    printf("\n\tVetor invertido: ");
    for(int i = 0; i < tam; i++) printf("\t%d", vet[i]);
    vet[0] = 10;
    vet[1] = 20;
    vet[2] = 55;
    vet[3] = 0;
    int soma_cauda = somaCauda(vet, tam);
    printf("\nResultado da soma: %d\n\n", soma_cauda);

    int fatorial = fatorialCauda(5);
    printf("Resultado do fatorial: %d\n\n", fatorial);

    int soma_mult = multiplica(5, 10);
    printf("Resultado da soma 1: %d\n\n", soma_mult);

    soma_mult = multiplicaCauda(6, 2);
    printf("Resultado da soma 2: %d\n\n", soma_mult);

    int posicao = encontraPosicao(vet, tam, 10);
    printf("Existe? %s\n\n", (!posicao) ? "Não" : "Sim");

    int maiorValor = maxi(vet, tam);
    printf("Maior valor do vetor: %d\n\n", maiorValor);

    float somaFatorial = somatorioFat(2);
    printf("\n\tResultado: %.2f", somaFatorial);

    return 0;
}
