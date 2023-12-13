/*
** Proejto criado para desenvolver procedimentos de lista encadeada
**
** Criado por: Emyle Silva
** Última atualização: 04/10/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "lista.h"

int main()
{
    setlocale (LC_ALL, "");

    int tamVet = 5, opcao = 0, aux = 0, aux2 = 0, erro = 0;
    Lista *l = NULL;

    srand(time(NULL));

    //Cria um vetor e preenche os valores com números aleatórios.
    int *vet = (int *)malloc(tamVet * sizeof(int));
    for(int i = 0; i < tamVet; i++){
        vet[i] = gera_valor(100);
    }

    //Mostra o vetor preenchido
    printf("\n\tVetor original: ");
    for(int i = 0; i < tamVet; i++){
        printf("\t%d", vet[i]);
    }

    printf("\n\n");

    //Operações a serem realizadas na lista
    do{
        printf("\n\t1 - Adicionar valores no inicio.");
        printf("\n\t2 - Adicionar valores no fim.");
        printf("\n\t3 - Adicionar valores de forma ordenada.");
        printf("\n\t4 - Deletar valor do Inicio.");
        printf("\n\t5 - Deletar valor.");
        printf("\n\t6 - Mostrar Lista.");
        printf("\n\t7 - Editar número da lista.");
        printf("\n\t0 - Sair");
        printf("\n\tOPÇÃO: "); scanf("%d%*c", &opcao);

        switch(opcao){
            case 1:
                for(int i = 0; i < tamVet; i++)
                    l = insere_ini(l, vet[i]);
            break;

            case 2:
                for(int i = 0; i < tamVet; i++)
                    l = insere_fim(l, vet[i]);
            break;

            case 3:
                for(int i = 0; i < tamVet; i++)
                    l = insere_ord(l, vet[i]);
            break;

            case 4:
                l = retira_ini(l);

            break;

            case 5:
                printf("\n\tNumero a ser deletado: ");
                scanf("%d%*c", &aux);
                l = retira(l, aux, &erro);

                if(!erro) printf("\n\tO valor inserido não foi encontrado\n\n");

            break;

            case 6:
                printf("\n----------------- Lista encadeada -------------------- \n");
                mostra_lista(l);
            break;

            case 7:
                printf("\n\tNumero a ser editado: ");
                scanf("%d%*c", &aux);
                printf("\n\tNovo valor: ");
                scanf("%d%*c", &aux2);
                atualiza(l, aux, aux2, &erro);

                if(!erro) printf("\n\tO valor inserido não foi encontrado\n\n");
            break;

            case 0: break;

        }

    }while(opcao);

    //Mostra a lista na tela
    free(vet);

    return 0;
}
