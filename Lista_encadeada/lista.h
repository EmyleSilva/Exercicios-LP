#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct lista{
    int num;
    struct lista *prox;
}Lista;

/*
**Insere valores no inicio da lista.
*/
Lista* insere_ini(Lista *ini, int num);

/*
**Insere valores no fim da lista.
*/
Lista* insere_fim(Lista *ini, int num);

/*
**Insere valores na lista de forma ordenada.
*/
Lista* insere_ord(Lista *ini, int num);

/*
**Busca o ultimo elemento da lista.
*/
Lista* encontra_ult(Lista *ini);

/*
**Deleta o ultimo elemento da lista.
*/
Lista* retira_ini(Lista *ini);

/*
**Busca um elemento anterior a algum elemento x.
*/
Lista* procura(Lista *ini, int num);

/*
**Deleta um elemento x da lista.
*/
Lista* retira(Lista *ini, int num, int *erro);

/*
**Atualiza o valor de uma lista
*/
void atualiza(Lista *ini, int num, int nNUm, int *erro);

/*
**Mostra todos os valores armazenados na lista
*/
void mostra_lista(Lista *ini);

/*
**Gera um valor aleatorio
*/
int gera_valor(int valMax);

#endif // LISTA_H_INCLUDED
