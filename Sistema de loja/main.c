#include <stdlib.h>
#include <stdio.h>

typedef struct produto{
    int codigo;
    char descricao[300];
    float valor;
    int quantidade;
    struct produto *prox;
}Produto;

typedef struct cliente{
    int codigo;
    char nome[200];
    struct cliente *prox;
}Cliente;

void menu(char opcoes[][50], int quant){
    for(int i = 0; i < quant; i++){    
        printf("\n\t%d - %s\n", i+1, opcoes[i]);
    }
}

void erro(char tipo[]){
    printf("\n\tERRO: %s", tipo);
    exit(1);
}

void mensagem_final(char mensagem[]){
    printf("\n\t\t============================================================\n");
    printf("\n");
    printf("\t\t                Operação %s                       \n", mensagem);
    printf("\t\t                Aperte ENTER para continuar....             \n");
    printf("\n");
    printf("\t\t============================================================\n\n");
    scanf("%*c");
    system("clear || cls");
}

void validacao_menu(){
    system("clear || cls");
    printf("\n\t\t============================================================\n");
    printf("\t\t|                                                          |\n");
    printf("\t\t|               ERRO: OPÇÃO INEXISTENTE!                   |\n");
    printf("\t\t|                     Tente Novamente                      |\n");
    printf("\t\t|               Aperte ENTER para continuar....            |\n");
    printf("\t\t|                                                          |\n");
    printf("\t\t============================================================\n\n");
    scanf("%*c");
    system("clear || cls");
}

//Encontra o ultimo Produto
Produto* encontra_ultimo_p(Produto* p){
    Produto *ult = p;
    if(p == NULL) return NULL;

    while(ult->prox != NULL){
        ult = ult->prox;
    }

    return ult;
}

//Encontra o ultimo Cliente
Cliente* encontra_ultimo_c(Cliente* c){
    Cliente *ult = c;
    if(c == NULL) return NULL;

    while(ult->prox != NULL){
        ult = ult->prox;
    }

    return ult;
}

//Buscar produto
Produto* buscar_p(Produto *p, int codigo){
    Produto *aux = p;
    if(p){
        if(aux->codigo == codigo){
            return p;
        }else{
            while(aux->prox && aux->prox->codigo != codigo)
                aux = aux->prox;
            if(aux->prox){
                return aux->prox;
            }
        }
    }
    return NULL;
}

//Bucar Cliente
Cliente* buscar_c(Cliente *c, int codigo){
    Cliente *aux = c;

    if(c){
        if(aux->codigo == codigo) 
            return c;
    }else{
        while(aux->prox && aux->prox->codigo != codigo)
            aux = aux->prox;
        if(aux->prox){
            return aux->prox;
        }
    }

    return NULL;
}

//Inserir produtos
Produto* inserir_no_fim_p(Produto* p){
    Produto *novo = (Produto *)malloc(sizeof(Produto));
    Produto *ult, *procurar;
    char aux[50];

    if(novo == NULL){
        erro("Memória insuficiente");
    }else{
        printf("\n\tCodigo: "); 
        scanf("%d%*c", &novo->codigo);

        /*Verificar se o código já está em uso*/
        procurar = buscar_p(p, novo->codigo);
        do{
            if(procurar != NULL){
                    printf("\n\tO código já está sendo utilizado. Tente novamente\n");
                    printf("\n\tNovo código: "); scanf("%d%*c", &novo->codigo);
                    procurar = buscar_p(p, novo->codigo);
                }
        }while(procurar != NULL && procurar->codigo == novo->codigo);
        
        printf("\n\tDescrição: ");
        scanf("%299[^\n]%*c", novo->descricao);

        printf("\n\tPreço: ");
        scanf("%f%*c", &novo->valor);

        printf("\n\tQuantidade: ");
        scanf("%d%*c", &novo->quantidade);

        novo->prox = NULL;

        if(p == NULL) return novo;

        ult = encontra_ultimo_p(p);
        ult->prox = novo;
    }

    return p;
}

//Inserir cliente
Cliente* inserir_no_fim_c(Cliente* c){
    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    Cliente *ult, *procurar;

    char aux[50];

    if(novo == NULL){
        erro("Memoria Insuficiente");
    }else{
        
        printf("\n\tCodigo: ");
        scanf("%d%*c", &novo->codigo);
        
        /*Verificar se o código já está em uso*/
        procurar = buscar_c(c, novo->codigo);
        do{
            if(procurar != NULL){
                printf("\n\tO código já está sendo utilizado. Tente novamente\n");
                printf("\n\tNovo código: "); scanf("%d%*c", &novo->codigo);
                procurar = buscar_c(c, novo->codigo);
            }
        }while(procurar != NULL && procurar->codigo == novo->codigo);
        

        printf("\n\tNome: ");
        scanf("%[^\n]%*c", novo->nome);

        novo->prox = NULL;

        if(c == NULL) return novo;

        ult = encontra_ultimo_c(c);
        ult->prox = novo;
    }

    return c;
}

//Excluir Produto
Produto* excluir_p(Produto *p, int codigo){
    Produto *remover = NULL;
    Produto *aux = p;

    if(p){
        if(p->codigo == codigo){
            remover = p;
            p = remover->prox;
        }else{
            while(aux->prox && aux->prox->codigo != codigo)
                aux = aux->prox;
            if(aux->prox){
                remover = aux->prox;
                aux->prox = remover->prox;
            }
        }

        free(remover);
    }
    return p;
}

//Excluir cliente
Cliente* excluir_c(Cliente *c, int codigo){
    Cliente *remover = NULL;
    Cliente *aux = c;

    if(c){
        if(c->codigo == codigo){
            remover = c;
            c = remover->prox;
        }else{
            while(aux->prox && aux->prox->codigo != codigo)
                aux = aux->prox;
            if(aux->prox){
                remover = aux->prox;
                aux->prox = remover->prox;
            }
        }
        free(remover);
    }
    return c;
}

Produto* atualiza_estoque(Produto* atualiza, int tipo){
    int quantidade;

    if(tipo == 1){
        printf("\n\tInforme a quantidade a ser adicionada: ");
        scanf("%d%*c", &quantidade);

        atualiza->quantidade+=quantidade;
        return atualiza;
    }else{
        printf("\n\tInforme a quantidade a ser removida do estoque");
        printf("\n\tOBS: Caso a quantia seja maior do que a quantia disponível em estoque,"
        "o valor final será zero.\n");
        printf("\n\tSaida: "); scanf("%d%*c", &quantidade);

        if(quantidade < atualiza->quantidade){
            atualiza->quantidade-=quantidade;
            return atualiza;
        }else{
            atualiza->quantidade = 0;
            return atualiza;
        }
    }
}

Produto* editar_produto(Produto *editar){
    char descricao[300], confirma;
    float preco;
    int opcao, i;
    char menu_op[][50] = {"Editar Descrição", "Editar Preço", "Editar Descrição e preço"};
    
    printf("\n\tSelecione a opção desejada: ");
    printf("\n\t----------------------------");
    menu(menu_op, 3);
    printf("\n\tOPÇÃO: "); scanf("%d%*c", &opcao);

    if(opcao == 1){
        printf("\n\tDigite a nova descrição do produto: ");
        scanf("%[^\n]%*c", descricao);

        printf("\n\tConfirma a alteração da descrição? ");
        scanf("%c%*c", &confirma);

        if(confirma == 's' || confirma == 'S'){
            for(i = 0; descricao[i]; i++)
                editar->descricao[i] = descricao[i];
            editar->descricao[i] = '\0';

            return editar;
        }
    }else if(opcao == 2){
        printf("\n\tDigite o novo preço do produto: ");
        scanf("%f%*c", &preco);
        
        printf("\n\tConfirma a alteração do preço? ");
        scanf("%c%*c", &confirma);

        if(confirma == 's' || confirma == 'S')
            editar->valor = preco;
        
        return editar;
    }else{
        printf("\n\tDigite a nova descrição do produto: ");
        scanf("%[^\n]%*c", descricao);

        printf("\n\tDigite o novo preço do produto: ");
        scanf("%f%*c", &preco);

        printf("\n\tConfirma a alteração do preço e descrição? ");
        scanf("%c%*c", &confirma);

        if(confirma == 's' || confirma == 'S'){
            for(i = 0; descricao[i]; i++)
                editar->descricao[i] = descricao[i];
            editar->descricao[i] = '\0';

            editar->valor = preco;

            return editar;
        }
    }

    return editar;
}

//Listar produtos
void mostra_produto(Produto *p){
    Produto *aux;
    int cont = 1;

    for(aux = p; aux!=NULL; aux = aux->prox){
        printf("\n\t---------------- Produto %d ----------------\n\n", cont);
        printf("\tCodigo: %d\n", aux->codigo);
        printf("\tDescrição: %s\n", aux->descricao);
        printf("\tPreço: %.2f\n", aux->valor);
        printf("\tQuantidade: %d\n", aux->quantidade);
        cont++;
    }

    printf("\n\n");

}

//Listar clientes
void mostra_cliente(Cliente *c){
    Cliente *aux;
    int cont = 1;

    for(aux = c; aux!=NULL; aux = aux->prox){
        printf("\n\t---------------- Produto %d ----------------\n\n", cont);
        printf("\tCodigo: %d\n", aux->codigo);
        printf("\tDescrição: %s\n", aux->nome);
        cont++;
    }

    printf("\n\n");

}

void main(void){
    Produto *p = NULL;
    Produto *remover_p, *procurar_p;
    Cliente *c = NULL;
    Cliente *remover_c, *procurar_c;

    char menu_principal[][50]={"Produtos", "Clientes", "Venda", "Encerrar"};//quant = 4
    char menu_produtos[][50] ={"Adicionar Produto", "Atualizar Estoque", "Editar Produto", "Excluir Produto", "Listar Produtos", "Retornar"};//quant = 6
    char menu_clientes[][50] ={"Adicionar Cliente", "Editar Cliente", "Excluir Cliente", "Listar Clientes", "Retornar"}; //quant =  5
    char menu_entrada_saida[][50] = {"Entrada", "Saida"};
    int opcao, opcao_c, opcao_p, opcao_es, auxCodigo;
    char confirma;

    do{
        menu(menu_principal, 4);
        printf("\n\tOPÇÃO: "); scanf("%d%*c", &opcao);

        switch(opcao){
            case 1://Produtos

                do{
                    system("clear || cls");
                    menu(menu_produtos, 6);
                    printf("\n\tOPÇÃO: "); scanf("%d%*c", &opcao_p);

                    switch(opcao_p){
                        case 1://Adicionar 
                            system("clear || cls");
                            printf("\n\t============================= Adicionar Produto =============================\n\n");
                            p = inserir_no_fim_p(p);
                            mensagem_final("Finalizada");
                        break;
                        case 2://Atualizar Estoque
                            system("clear || cls");
                            printf("\n\t============================= Atualizar Estoque =============================\n\n");
                            
                            printf("\n\tDigite o código do produto: ");
                            printf("\n\tCódigo: "); scanf("%d%*c", &auxCodigo);
                            procurar_p = buscar_p(p, auxCodigo);

                            if(procurar_p){
                                printf("\n\tProduto selecionado: %d- %s", procurar_p->codigo, procurar_p->descricao);
                                printf("\n\n\tSelecione uma opção: ");
                                printf("\n\t-----------------------\n");
                                menu(menu_entrada_saida, 2);
                                printf("\n\tOPÇÃO: "); scanf("%d%*c", &opcao_es);

                                printf("\n\tConfirma a atualização do estoque? <s/n>: ");
                                scanf("%c%*c", &confirma);

                                if(opcao_es == 1 && (confirma == 's' || confirma == 'S')) {
                                    p = atualiza_estoque(procurar_p, 1);
                                    mensagem_final("Finalizada");

                                }else if(opcao_es == 2 && (confirma == 's' || confirma == 'S')){ 
                                        p = atualiza_estoque(procurar_p, 2);
                                        mensagem_final("Finalizada");

                                    }else if(opcao_es > 2 || opcao_es < 1){
                                            printf("\n\tOpção inválida");
                                            mensagem_final("Falhou");
                                        }else{
                                            mensagem_final("Cancelada");
                                        }
                            }else{
                                printf("\n\tO produto buscado não existe no sistema.");
                                mensagem_final("Falhou");
                            }
                        break;
                        case 3://Editar Produto
                            system("clear || cls");
                            printf("\n\t============================= Editar Produto =============================\n\n");

                            printf("\n\tDigite o código do produto: ");
                            scanf("%d%*c", &auxCodigo);

                            procurar_p = buscar_p(p, auxCodigo);
                            if(procurar_p){
                                printf("\n\tProduto selecionado: %d- %s", procurar_p->codigo, procurar_p->descricao);
                                p = editar_produto(procurar_p);
                                mensagem_final("Finalizada");
                            }else{
                                printf("\n\tO produto buscado não existe no sistema.");
                                mensagem_final("Falhou");
                            }
                        break;
                        case 4://Excluir Produto
                            system("clear || cls");
                            printf("\n\t============================= Excluir Produto =============================\n\n");

                            printf("\n\tDigite o código do produto que deseja excluir.");
                            printf("\n\tCódigo: "); scanf("%d%*c", &auxCodigo);
                            procurar_p = buscar_p(p, auxCodigo);

                            if(procurar_p){
                                printf("\n\tConfirma a exclusão do produto: '%d - %s'?", procurar_p->codigo, procurar_p->descricao);
                                printf("\n\t<s/n>: "); scanf("%c%*c", &confirma);

                                if(confirma == 's' || confirma == 'S'){
                                    p = excluir_p(p,auxCodigo);
                                    mensagem_final("finalizada");
                                }else{
                                    mensagem_final("cancelada");
                                }
                            }else{
                                printf("\n\tATENÇÃO: Produto inexistente.");
                                mensagem_final("cancelada");
                            }
                            
                        break;
                        case 5://Listar Produto
                            system("clear || cls");
                            printf("\n\t============================= Listar Produto =============================\n\n");
                            mostra_produto(p);
                            mensagem_final("finalizada");
                        break;
                        case 6://Retornar
                            opcao_p = 0;
                            system("clear || cls");
                        break;
                        default:
                            validacao_menu();
                        break;
                    }
                }while(opcao_p);

            break;
            case 2://Clientes

                do{
                    system("clear || cls");
                    menu(menu_clientes, 5);
                    printf("\n\tOPÇÃO: "); scanf("%d%*c", &opcao_c);

                    switch(opcao_c){
                        case 1:
                        break;
                        case 2:
                        break;
                        case 3:
                        break;
                        case 4:
                        break;
                        case 5:
                        break;
                        default:
                        break;
                    }
                }while(opcao_c);

            break;
            case 3://Vendas
            break;
            case 4://Encerrar
                opcao = 0;
                system("clear || cls");
                printf("\n\t\tPrograma Finalizado!\n\n");
            break;
            default://Entrada inválida
                validacao_menu();
            break;
        }
    }while(opcao);
   
}
