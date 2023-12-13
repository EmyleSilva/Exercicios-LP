/*
**  Resolução de lista de exercicios sobre questões recursivas
**  Autor: Emyle Silva
**  Ultima atualização: 31/10/2023
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam1 = 3;
    int tam2 = 2;

    int *vet1 = (int *)malloc(tam1 * sizeof(int));
    int *vet2 = (int *)malloc(tam2 * sizeof(int));
    int *vet3 = (int *)malloc((tam1+tam2) * sizeof(int));

    vet1[0] = 2;
    vet1[1] = 3;
    vet1[2] = 5;

    vet2[0] = 1;
    vet2[1] = 13;

    printf("O digito 2 ocorre %d vezes em 2525258\n\n", cont_dig(2525258, 2));//3
    printf("O MDC de 120 e 30 é: %d\n\n", mdc(120, 30));//30
    printf("O MOD de 35/10 eh: %d\n\n", mod(35, 10));//5
    printf("O digito tetranacci de 11 é: %d\n\n", tetranacci(11));//108
    printf("O resultado da soma dos 5 primeiros inteiros é: %d\n", somaN(5));//15
    printf("O algarismo mais significativo de 3456: %d\n\n", prim_alg(3456));//3
    printf("Tem par: %d\n\n", comtemPar(vet1, tam1));//sim
    printf("Tem par: %d\n\n", comtemPar(vet2, tam2));//Não

   /* vet1 = inverteVet(vet1, tam1);
    printf("Vetor 1 invertido: "); for(int i = 0; i < tam1; i++) printf("\t%d", vet1[i]);
    printf("\n\n"); //5, 3, 2

    vet3 = intercala(vet1, tam1, vet2, tam2, vet3); //5, 1, 3, 13, 2
    printf("Vetor intercalado: "); for(int i = 0; i < (tam1+tam2); i++) printf("\t%d", vet3[i]);
    printf("\n\n");
*/
    float media = mediaVet(vet1, tam1);
    printf("Media do vet1: %.2f\n\n", media);//3.33

    printf("Numero 1234 invertido: %d\n\n", inverter(1234));//4321

    printf("Menor elemento do vetor 1: %d\n\n", menorE(vet1, tam1));//2

    printf("Soma dos digitos 1234: %d\n\n", somaDig(1234));//10

    printf("Somatorio quando n = 3: %.2f\n\n", comtemPar(vet2, tam2));//1,83


    return 0;
}
