/*QUESTAO 5.

5. Vamos montar um programa de gestão de contatos;

a. Crie um tipo novo, baseado em uma struct, que guardará os dados do contato 
(nome, telefone, email). Use os tipos primitivos que você considerar adequados 
para os campos dessa struct;

b. Instancie o container de dados usando esse seu novo tipo;

c. Implemente as funcionalidades básicas, no estilo das listas, para inserir, 
remover, buscar e detectar o fim da lista de contatos

d. Implemente as funcionalidades clássicas de uma agenda de contatos, em 
funções individuais:

i. Atualizar Nome do contato;
ii. Atualizar Telefone do contato;
iii. Atualizar email do contato;

e. Construa um fluxo de interface em texto, para atuar como front-end para as 
funcionalidades já construídas;
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[50];
    char telefone[15];
    char email[50];
} Contato;

typedef struct {
    Contato contatos[50];
    int tamanho;
} ListaContatos;

void inicializarLista(ListaContatos* lista) {
    lista->tamanho = 0;
}

void inserirContato(ListaContatos* lista, Contato contato) {
    if (lista->tamanho >= 50) {
        printf("A lista de contatos esta cheia.\n");
        return;
    }

    lista->contatos[lista->tamanho] = contato;
    lista->tamanho++;
    printf("Contato inserido com sucesso.\n");
}

void removerContato(ListaContatos* lista, char* nome) {
    int i, encontrado = 0;

    for (i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->contatos[i].nome, nome) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        for (; i < lista->tamanho - 1; i++) {
            lista->contatos[i] = lista->contatos[i + 1];
        }
        lista->tamanho--;
        printf("Contato removido com sucesso.\n");
    } else {
        printf("Contato nao encontrado na lista.\n");
    }
}

Contato* buscarContato(ListaContatos* lista, char* nome) {
    int i;

    for (i = 0; i < lista->tamanho; i++) {
        if (strcmp(lista->contatos[i].nome, nome) == 0) {
            return &(lista->contatos[i]);
        }
    }

    return NULL;
}

void imprimirLista(ListaContatos* lista) {
    if (lista->tamanho == 0) {
        printf("A lista esta vazia.\n");
        return;
    }

    printf("Contatos na lista:\n");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("Nome: %s\n", lista->contatos[i].nome);
        printf("Telefone: %s\n", lista->contatos[i].telefone);
        printf("Email: %s\n", lista->contatos[i].email);
        printf("\n");
    }
}

int main() {
    ListaContatos lista;
    inicializarLista(&lista);

    int opcao = -1;
    char nome[50];

    while (opcao != 0) {

        printf("1. Inserir contato\n");
        printf("2. Remover contato\n");
        printf("3. Buscar contato\n");
        printf("4. Imprimir lista de contatos\n");
        printf("0. Sair\n");
        printf("\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o caractere '\n' do buffer de entrada

        switch (opcao) {
            case 1: {
                Contato novoContato;
                printf("Digite o nome do contato: ");
                fgets(novoContato.nome, 50, stdin);
                novoContato.nome[strcspn(novoContato.nome, "\n")] = '\0'; // Remove o '\n' da string
                printf("Digite o telefone do contato: ");
                fgets(novoContato.telefone, 15, stdin);
                novoContato.telefone[strcspn(novoContato.telefone, "\n")] = '\0'; // Remove o '\n' da string
                printf("Digite o email do contato: ");
                fgets(novoContato.email, 50, stdin);
                novoContato.email[strcspn(novoContato.email, "\n")] = '\0'; // Remove o '\n' da string

                inserirContato(&lista, novoContato);
                break;
            }
            case 2: {
                printf("Digite o nome do contato a ser removido: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n' da string

                removerContato(&lista, nome);
                break;
            }
            case 3: {
                printf("Digite o nome do contato a ser buscado: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Remove o '\n' da string

                Contato* contato = buscarContato(&lista, nome);
                if (contato != NULL) {
                    printf("Contato encontrado:\n");
                    printf("Nome: %s\n", contato->nome);
                    printf("Telefone: %s\n", contato->telefone);
                    printf("Email: %s\n", contato->email);
                } else {
                    printf("Contato nao encontrado na lista.\n");
                }
                break;
            }
            case 4: {
                imprimirLista(&lista);
                break;
            }
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção invalida. Por favor, tente novamente.\n");
                break;
        }
    }

    return 0;
}
