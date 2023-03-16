
#include <stdio.h>
#include <stdlib.h>

struct Clientes {
    int id;       
    char nome[30]; //Limite mamixo de carateres para o nome
    float saldo;
    char morada[30]; //Limite mamixo de carateres para a morada
    int nif;
};  

struct Gestores {
    int id;
    char nome[30]; //Limite mamixo de carateres para o nome
    };

struct Mobilidade {
    int id;
    char tipo[30]; //Tipo de veiculo eletrico
    float cargabateria;
    float preco;
    char localizacao[30]; //Limite mamixo de carateres para a localizacao
};

void registarcliente(struct Clientes* matriz_cliente, int* num_clientes) { 

    printf("Introduzir ID do Cliente:");
    scanf("%d", &matriz_clientes[*num_clientes].id); //Numero ID do Cliente

    printf("Introduzir Nome do Cliente:");
    scanf("%s", &matriz_clientes[*num_clientes].nome); //Letra Nome do Cliente

    printf("Introduzir Saldo do Cliente:");
    scanf("%lf", &matriz_clientes[*num_clientes].saldo); //Valor Decimal Saldo Cliente

    printf("Intoduzir Morada do Cliente:");
    scanf("%s", &matriz_clientes[*num_clientes].morada); //Letra Morada do Cliente

    printf("Intoduzir NIF do Cliente:");
    scanf("%d", &matriz_clientes[*num_clientes].nif); //Numero NIF do Cliente

    (*num_clientes)++; //Aumenta o Numero Total de Clientes na Matriz
}


void registogestor(struct Gestores* matriz_gestor, int* num_gestores) { //Função para Adicionar um novo Gestor na Matriz

    printf("Intoduzir ID do Gestor:");
    scanf("%d", &matriz_gestor[*num_gestores].id); //Numero ID do Gestor

    printf("Introduzir Nome do Gestor: ");
    scanf("%s", &matriz_gestor[*num_gestores].nome); //Letra Nome do Gestor

    (*num_gestores)++; //Aumenta o Numero Total de Gestores na Matriz
}

void gestaomobilidade(struct Mobilidade* matriz_mobilidade, int* num_mobilidade) {
    
    printf("Introduzir ID do Veiculo");
    scanf("%d", &matriz_mobilidade[*num_mobilidade].id); //Numero ID do Veiculo

    printf("Introduzir Tipo do Veiculo");
    scanf("%s", &matriz_mobilidade[*num_mobilidade].tipo); //Letra Tipo do Veiculo

    printf("Leitura da Carga da Bateria");
    scanf("%d", &matriz_mobilidade[*num_mobilidade].cargabateria); //Numero Carga da Bateria do Veiculo

    printf("Preco do Aluger");
    scanf("%lf", &matriz_mobilidade[*num_mobilidade].preco); //Valor Decimal Preco Aluguer

    printf("Localizacao do Veiculo");
    scanf("%s", &matriz_mobilidade[*num_mobilidade].localizacao); //Letra Localizacao do Veiculo

    (*num_mobilidade)++; //Aumenta Mobilidade na Matriz
}


void removermobilidade(struct Mobilidade* matriz_mobilidade, int* num_mobilidade, int id) {
    int i, j;
    for (i = 0; i < *num_mobilidade; i++) {
        if (matriz_mobilidade[i].id == id) {

            //Remove o elemento da matriz, Deslocando os Outros Elementos para Preencher o Espaço que ficou Vazio
            for (j = i; j < *num_mobilidade - 1; j++) {
                matriz_mobilidade[j] = matriz_mobilidade[j + 1];
            }
            (*num_mobilidade)--; //Decrementa o Numero de Mobilidades na Matriz
            return;
        }
    }
    printf("Mobilidade com o ID %d nao foi encontrada!\n", id);
}

void alterarmobilidade(struct Mobilidade* matriz_mobilidade, int * num_mobilidade, int id) {
    int i;
    for (i = 0; i < *num_mobilidade; i++) {
        if (matriz_mobilidade[i].id == id) {

            //Pedido ao Usuário para Inserir os Novos Valores da Mobilidade
            printf("Introduzir Tipo do Veiculo");
            scanf("%s", &matriz_mobilidade[i].tipo); //Letra Tipo do Veiculo

            printf("Leitura da Carga da Bateria");
            scanf("%d", &matriz_mobilidade[i].cargabateria); //Numero Carga da Bateria do Veiculo

            printf("Preco do Aluger");
            scanf("%lf", &matriz_mobilidade[i].preco); //Valor Decimal Preco Aluguer

            printf("Localizacao do Veiculo");
            scanf("%s", &matriz_mobilidade[i].localizacao); //Letra Localizacao do Veiculo

            return;
        }
    }
    printf("Mobilidade com o ID %d nao foi encontrada!\n", id);
}

//Função de comparação para qsort (Comparação de Funcoes)
int comparar_mobilidades(const void *a, const void *b) {
    const struct Mobilidade *mobilidade_a = (const struct Mobilidade *)a;
    const struct Mobilidade *mobilidade_b = (const struct Mobilidade *)b;

    //Ordena por Ordem Decrescente baseando-se na carga da bateria
    return mobilidade_b->cargabateria - mobilidade_a->cargabateria;
}


int main() {
    int num_clientes = 0;
    int num_gestores = 0;
    int num_mobilidade = 0;
    struct Clientes* matriz_cliente = (struct Clientes *) malloc(sizeof(struct Clientes) * 100);
    struct Gestores* matriz_gestor = (struct Gestores *) malloc(sizeof(struct Gestores) * 30);
    struct Mobilidade* matriz_mobilidade = (struct Mobilidade *) malloc(sizeof(struct Mobilidade) * 30);

    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Adicionar Cliente\n");
        printf("2. Adicionar Gestor\n");
        printf("3. Adicionar Mobilidade\n");
        printf("4. Remover Mobilidade\n");
        printf("5. Alterar Mobilidade\n");
        printf("6. Listar matriz_mobilidade Mobilidade por cargabateria\n");
        printf("7. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
    
        switch (opcao) {
            case 1:
                registarcliente(matriz_cliente, &num_clientes);
                printf("Cliente Adicionado com Sucesso!\n");
                break;
            case 2:
                registogestor(matriz_gestor, &num_gestores);
                printf("Gestor Adicionado com Sucesso!\n");
                break;
            case 3:
                gestaomobilidade(matriz_mobilidade, &num_mobilidade);
                printf("Mobilidade Adicionada com Sucesso!\n");
                break;
            case 4:
                printf("Introduzir ID da Mobilidade a Remover:");
                int id_remover;
                scanf("%d", &id_remover);
                removermobilidade(matriz_mobilidade, &num_mobilidade, id_remover);
                printf("Mobilidade Removida com sucesso!\n");
                break;
            case 5:
                printf("Introduzir ID da Mobilidade a Alterar:");
                int id_alterar;
                scanf("%d", &id_alterar);

                alterarmobilidade(matriz_mobilidade, &num_mobilidade, id_alterar);
                printf("Mobilidade Alterada com Sucesso!\n");
                break;
            case 6:
                printf("Listar Mobilidade por Autonomia\n");
                qsort(matriz_mobilidade, num_mobilidade, sizeof(struct Mobilidade), comparar_mobilidades);

                //Imprime a Matriz Ordenada
                for (int i = 0; i < num_mobilidade; i++) {
                    printf("id: %d, cargabateria: %d\n", matriz_mobilidade[i].id, matriz_mobilidade[i].cargabateria);
                }

                break;
            case 7:
                printf("A Fehar o Programa\n");
                break;
            default:
                printf("Opcao Invalida!\n");
                break;
        }
    } while (opcao != 7);

    free(matriz_cliente);
    free(matriz_gestor);

    return 0;
}
