#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//------------------------------------------------------
//Insere os valores na primeira posição da lista.
//------------------------------------------------------
Lista* insere_ini(Lista *ini, int num){
    Lista *novo = (Lista *)malloc(sizeof(Lista));

    if(novo){
        novo->num = num;
        novo->prox = ini;
    }else{
        printf("ERRO! Memoria insuficiente");
        exit(1);
    }

    return novo;
}

//------------------------------------------------------
//Insere os valores na última posição da lista.
//------------------------------------------------------
Lista* insere_fim(Lista *ini, int num){
    Lista *novo = (Lista *)malloc(sizeof(Lista));

    if(novo){
        novo->num = num;
        novo->prox = NULL;

        if(ini == NULL) return novo;

        Lista *ult = encontra_ult(ini);
        ult->prox = novo;

    }else{
        printf("ERRO! Memoria Insuficiente");
        exit(1);
    }

    return ini;
}

//------------------------------------------------------
//Insere os valores na lista de forma ordenada crescente
//------------------------------------------------------
Lista* insere_ord(Lista *ini, int num){
    //Caso a lista esteja vazia, insere na primeira posição
    if(ini == NULL) return insere_ini(ini, num);

    //Se a lista não estiver vazia, mas contiver apenas um
    //elemento, insere na ultima posição caso num > que ini
    //e na primeira posição caso contrario.
    if(ini->prox == NULL){
        if(ini->num > num) return insere_ini(ini, num);
        else return insere_fim(ini, num);
    }
    //Quando possui mais de um elemento, verifica em qual
    //posição o elemento deve ser adicionado.
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    Lista *aux = ini;

    novo->num = num;

    //Se o numero inserido for menor que o primeiro da lista
    //ele é adicionado na primeira posição
    if(novo->num <= ini->num){
        novo->prox = ini;
        return novo;
    }

    while(aux->prox && novo->num > aux->prox->num){
        aux = aux->prox;
    }

    novo->prox = aux->prox;
    aux->prox = novo;

    return ini;
}

//------------------------------------------------------
//Encontra o último valor que a lista possui
//------------------------------------------------------
Lista* encontra_ult(Lista *ini){
    if(ini == NULL) return NULL;

    Lista *ult = ini;

    while(ult->prox != NULL){
        ult = ult->prox;
    }

    return ult;

}

//------------------------------------------------------
//Deleta o primeiro elemento da lista
//------------------------------------------------------
Lista* retira_ini(Lista *ini){
    Lista *p = ini;
    ini = ini->prox;
    free(p);

    return ini;
}

//------------------------------------------------------
//Deleta um elemento X da lista
//------------------------------------------------------
Lista* retira(Lista *ini, int num, int *erro){
    Lista *ant, *p;

    if(ini->num == num){
        (*erro) = 1;
        return retira_ini(ini);
    }

    if(ant = procura(ini, num)){
        p = ant->prox;
        ant->prox = p->prox;
        free(p);
        (*erro) = 1;
        return ini;
    }

    (*erro) = 0;
    return ini;
}

//------------------------------------------------------
//Procura um elemento X na lista e retorna o elemento
//anterior a ela.
//------------------------------------------------------
Lista* procura(Lista *ini, int num){
    Lista *ant = ini, *p = ini;

    while(p->num != num && p->prox){
        ant = p;
        p = p->prox;
    }

    if(p->num == num) return ant;
    else return NULL;
}

//------------------------------------------------------
//Atualiza o valor de um elemento na lista
//------------------------------------------------------
void atualiza(Lista *ini, int num, int nNum, int *erro){
    Lista *ant;

    if(ini->num == num){
        ini->num = nNum;
        (*erro) = 1;
    }else{
        if(ant = procura(ini, num)){
            ant->prox->num = nNum;
            (*erro) = 1;
        }else{
            (*erro) = 0;
        }
    }
}

//------------------------------------------------------
//Mostra na tela todos os valores registrados na lista
//------------------------------------------------------
void mostra_lista(Lista *ini){
    Lista *aux = ini;
    for(;aux; aux=aux->prox){
        printf("\t%d\n", aux->num);
    }
}

//------------------------------------------------------
//Gera um valor aleatório para um veto
//------------------------------------------------------
int gera_valor(int valMax){
    return rand() % valMax + 1;
}
