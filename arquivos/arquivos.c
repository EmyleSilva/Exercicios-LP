#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"


void relatorioCidade(char *arqE, char *arqS){
    FILE *fp_e, *fp_s;
    if((fp_e = fopen(arqE, "r")) == NULL){
        printf("Erro ao abrir arquivo.");
        exit(1);
    }

    if((fp_s = fopen(arqS, "w")) == NULL){
        printf("Erro ao abrir arquivo.");
        exit(1);
    }

    char *ptok;
    char linha[200];
    char cidade[2][40], maior[2][40];

    int i = 0;

    fgets(linha, sizeof(linha), fp_e);
    ptok = strtok(linha, ",");
    while(ptok){
        strcpy(maior[i], ptok);
        ptok = strtok(NULL, ",");
        i++;
    }
    rewind(fp_e);
    while(fgets(linha, sizeof(linha), fp_e)){
        i = 0;
        ptok = strtok(linha, ",");
        while(ptok){
            strcpy(cidade[i], ptok);
            i++;
            ptok = strtok(NULL, ",");
        }

        int m = atoi(maior[1]);
        int c = atoi(cidade[1]);
        if(c >= m){
            strcpy(maior[0], cidade[0]);
            strcpy(maior[1], cidade[1]);
        }
    }

    fprintf(fp_s, "%s, %s", maior[0], maior[1]);
    fclose(fp_s);
    fclose(fp_e);

}
