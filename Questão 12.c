/*#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da árvore
typedef struct no {
    int data;
    struct no* esquerda;
    struct no* direita;
} no;

// Função para criar um novo nó
no* criarNo(int data) {
    no* novoNo = (no*)malloc(sizeof(no));
    novoNo->data = data;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inverter o espelho da árvore
void inverterArvore(no* raiz) {
    if (raiz == NULL) {
        return;
    } else {
        // Troca as subárvores esquerda e direita
        no* temp;
        inverterArvore(raiz->esquerda);
        inverterArvore(raiz->direita);

        // Troca os ponteiros das subárvores esquerda e direita
        temp = raiz->esquerda;
        raiz->esquerda = raiz->direita;
        raiz->direita = temp;
    }
}

// Função para percorrer a árvore em ordem (para verificação)
void percorrerEmOrdem(no* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->data);
        percorrerEmOrdem(raiz->direita);
    }
}

int main() {
    // Criação da árvore de exemplo
    no* raiz = criarNo(1);
    raiz->esquerda = criarNo(2);
    raiz->direita = criarNo(3);
    raiz->esquerda->esquerda = criarNo(4);
    raiz->esquerda->direita = criarNo(5);

    printf("arvore original: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    // Obtém o espelho da árvore
    inverterArvore(raiz);

    printf("arvore espelho: ");
    percorrerEmOrdem(raiz);
    printf("\n");

    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para inserir um elemento no final da lista
void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// Função iterativa para verificar se duas listas são iguais
int areListsEqualIterative(Node* list1, Node* list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->data != list2->data) {
            return 0;
        }
        list1 = list1->next;
        list2 = list2->next;
    }

    // As duas listas devem ter o mesmo tamanho para serem iguais
    if (list1 == NULL && list2 == NULL) {
        return 1;
    }

    return 0;
}

// Função recursiva auxiliar para verificar se duas listas são iguais
int areListsEqualRecursiveHelper(Node* list1, Node* list2) {
    // Se ambos os nós chegaram ao final da lista, as listas são iguais
    if (list1 == NULL && list2 == NULL) {
        return 1;
    }

    // Se apenas um dos nós chegou ao final da lista, as listas são diferentes
    if (list1 == NULL || list2 == NULL) {
        return 0;
    }

    // Verifica se os valores dos nós atuais são iguais
    if (list1->data != list2->data) {
        return 0;
    }

    // Verifica recursivamente os nós restantes
    return areListsEqualRecursiveHelper(list1->next, list2->next);
}

// Função recursiva para verificar se duas listas são iguais
int areListsEqualRecursive(Node* list1, Node* list2) {
    return areListsEqualRecursiveHelper(list1, list2);
}

// Função para imprimir uma lista
void printList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Função para liberar a memória ocupada pela lista
void freeList(Node** head) {
    Node* curr = *head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    *head = NULL;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Exemplo de preenchimento das listas
    insert(&list1, 1);
    insert(&list1, 2);
    insert(&list1, 3);

    insert(&list2, 1);
    insert(&list2, 2);
    insert(&list2, 3);

    // Imprime as listas
    printf("Lista 1: ");
    printList(list1);

    printf("Lista 2: ");
    printList(list2);

    // Verifica se as listas são iguais (iterativo)
    if (areListsEqualIterative(list1, list2)) {
        printf("As listas sao iguais (iterativo)\n");
    } else {
        printf("As listas sao diferentes (iterativo)\n");
    }

    // Verifica se as listas são iguais (recursivo)
    if (areListsEqualRecursive(list1, list2)) {
        printf("As listas sao iguais (recursivo)\n");
    } else {
        printf("As listas sao diferentes (recursivo)\n");
    }

    // Libera a memória ocupada pelas listas
    freeList(&list1);
    freeList(&list2);

    return 0;
}


