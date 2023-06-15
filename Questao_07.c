/*
7. Escreva uma função que faça uma busca em uma lista encadeada crescente. Faça
versões recursiva e iterativa.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Função para inserir um novo nó no final da lista encadeada
void insert(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Função de busca iterativa na lista encadeada
struct Node* search_iterative(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {  // Verifica se o nó atual contém a chave procurada
            return current;
        } else if (current->data > key) {  // Se o valor do nó atual for maior que a chave, interrompe a busca
            break;
        }
        current = current->next;  // Avança para o próximo nó
    }
    return NULL;  // Chave não encontrada
}

// Função de busca recursiva na lista encadeada
struct Node* search_recursive(struct Node* node, int key) {
    if (node == NULL || node->data == key) {  // Verifica se o nó atual é nulo ou contém a chave procurada
        return node;
    }
    if (node->data < key) {  // Se o valor do nó atual for menor que a chave, avança para o próximo nó
        return search_recursive(node->next, key);
    }
    return NULL;  // Chave não encontrada
}

int main() {
    struct Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    int key = 30;
    struct Node* result_iterative = search_iterative(head, key);
    if (result_iterative != NULL) {
        printf("Chave encontrada (iterativo): %d\n", result_iterative->data);
    } else {
        printf("Chave não encontrada (iterativo)\n");
    }

    struct Node* result_recursive = search_recursive(head, key);
    if (result_recursive != NULL) {
        printf("Chave encontrada (recursivo): %d\n", result_recursive->data);
    } else {
        printf("Chave não encontrada (recursivo)\n");
    }

    return 0;
}
