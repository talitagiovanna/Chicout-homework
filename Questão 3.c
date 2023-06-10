#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 20

typedef struct {
    char nome[80];
    float preco;
} PROD;

// Função para atualizar o preço do produto
void atualizarPreco(PROD *produto) {
    if (produto->preco < 100) {
        produto->preco *= 1.05;  // Inflacionar em 5%
    }
}

// Função para ler os dados do produto
void lerDados(PROD *produto) {
    printf("Digite o nome do produto: ");
    scanf("%s", produto->nome);
    
    printf("Digite o preco do produto: ");
    scanf("%f", &produto->preco);
}

// Função para imprimir os dados do produto
void imprimirDados(PROD *produtos, int quantidade) {
    printf("\nProdutos:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: %.2f\n", produtos[i].preco);
        printf("-----------------\n");
    }
}

// Função de comparação para a ordenação dos produtos
int compararProdutos(const void *a, const void *b) {
    PROD *prod1 = (PROD *)a;
    PROD *prod2 = (PROD *)b;
    
    return strcmp(prod1->nome, prod2->nome);
}

int main() {
    PROD produtos[MAX_PRODUTOS];
    
    printf("=== Cadastro de Produtos ===\n");
    
    // Loop para ler os dados dos produtos
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        printf("\nProduto %d:\n", i+1);
        lerDados(&produtos[i]);
    }
    
    // Ordena os produtos em ordem alfabética de nome
    qsort(produtos, MAX_PRODUTOS, sizeof(PROD), compararProdutos);
    
    // Atualiza os preços dos produtos conforme necessário
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        atualizarPreco(&produtos[i]);
    }
    
    // Imprime os dados dos produtos
    imprimirDados(produtos, MAX_PRODUTOS);
    
    return 0;
}



