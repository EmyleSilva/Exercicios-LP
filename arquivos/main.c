#include <stdio.h>
#include <stdlib.h>
#include "arquivos.h"

typedef struct aluno{
    char nome[50];
    int matricula;
}Aluno;

int* showMenuBar(char opcoes[][50], int quantOpt){
    for(int i = 0; i < quantOpt; i++){
        printf("\t%d - %s\n", i+1, opcoes[i]);
    }
    printf("\tOPÇÃO: ");
}

void escreverFrase(char *nomeArq){
    FILE *fp;
    if((fp=fopen(nomeArq, "w"))==NULL){
        printf("erro ao abrir arquivo.");
        exit(1);
    }

    printf("\nDigite uma frase. Aperte 0 para encerrar.\n\n");
    char ch;
    do{
        ch = getchar();
        fputc(ch, fp);
    }while(ch != '\n');

    fclose(fp);
}

void mostrarFrase(char *nomeArq){
    FILE *fp;
    char ch;
    int vogais = 0;

    if((fp = fopen(nomeArq, "r")) == NULL){
        printf("Erro ao abrir arquivo.");
        exit(1);
    }

    ch = fgetc(fp);
    do{
        printf("%c", ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'e' || ch == 'I' || ch == 'O' || ch == 'U'){
                vogais++;
           }
        ch = fgetc(fp);
    }while(!feof(fp));

    printf("\n\tNeste arquivo existem %d vogais\n\n", vogais);
    printf("\n\n");

    fclose(fp);
}

void mostrarQuantLinhas(char *nomeArq){
    FILE *fp;

    if((fp = fopen(nomeArq, "r")) == NULL){
        printf("Erro ao abrir arquivo.");
        exit(1);
    }

    int quant = 0;
    char str[500];

    while(fgets(str, sizeof(str), fp)){
        quant++;
    }
    fclose(fp);

    printf("O arquivo tem %d linhas\n\n", quant);
}

void criarArqTres(char *arq1, char *arq2, char *arq3){
    FILE *p1, *p2, *p3;

    if((p1 = fopen(arq1, "r")) == NULL){
        printf("erro ao abrir arq1");
        exit(1);
    }

    if((p3 = fopen(arq1, "w")) == NULL){
        printf("erro ao abrir arq3");
        exit(1);
    }

    char linha[500];
    while(fgets(linha, sizeof(linha), p1)){
        fputs(linha, p3);
    }

    fclose(p1);
    fclose(p3);

    if((p2 = fopen(arq2, "r")) == NULL){
        printf("erro ao abrir arq2");
        exit(1);
    }

    if((p3 = fopen(arq3, "a")) == NULL){
        printf("erro ao abrir arq3");
        exit(1);
    }

    while(fgets(linha, sizeof(linha), p2)){
        fputs(linha, p3);
    }

    fclose(p2);
    fclose(p3);
}


void createStudent(Aluno a[], int* quant, int tam){
    if(*quant < tam){
        Aluno aux;
        printf("Informe o nome do aluno: ");
        scanf("%49[^\n]%*c", aux.nome);
        printf("Informe a matricula do aluno: ");
        scanf("%d%*c", &aux.matricula);

        a[*quant] = aux;
        (*quant)++;
    }else{
        printf("ERRO: Tamanho excedido");
    }

    return a;
}

void showStudents(Aluno a[], int quant){
    if(quant){
        int i;
        for(i = 0; i < quant; i++){
            printf("\tNome: %s", a[i].nome);
            printf("\tMatricula: %d", a[i].matricula);
            printf("\n--------------------------------\n\n");
        }
    }else{
        printf("\n\tNão existe aluno registrado no sistema\n\n");
    }

}

void saveStudents(Aluno a[], int quant){
    FILE *fp;
    if((fp = fopen("alunos.txt", "w")) == NULL){
        printf("Erro ao abrir arquivo");
    }else{
        fprintf(fp, "%d\n", quant);
        for(int i = 0; i < quant; i++){
            fprintf(fp, "%s\t", a[i].nome);
            fprintf(fp, "%d\n", a[i].matricula);
        }
    }
}

int main(int argc, char *argv[])
{
    int quant = 0, menuOpt = 0;
    int tam = 10;

    char mainMenu[][50] = {"Criar Estudante", "Listar Estudante", "Salvar Alunos" , "Salvar Frase","Sair"};
    Aluno a[10];

    do{
        showMenuBar(mainMenu, 5);
        scanf("%d%*c", &menuOpt);

        switch(menuOpt){
            case 1:
                createStudent(a, &quant, tam);
            break;

            case 2:
                showStudents(a, quant);
            break;

            case 3:
                saveStudents(a, quant);
            break;

            case 4:{
                /*char nomeArq[] = "frase.txt";
                //escreverFrase(nomeArq);
                mostrarFrase(nomeArq);
                //mostrarQuantLinhas(nomeArq);*/
                char arq1[] = "arq1.txt";
                char arq2[] = "arq2.txt";
                //char arq3[] = "arq3.txt";
                relatorioCidade(arq1, arq2);
                /*criarArqTres(arq1, arq2, arq3);*/
            }
            break;

            case 5:
                menuOpt = 0;
                break;
        }

    }while(menuOpt);



    //fclose(fp);
    return 0;
}
