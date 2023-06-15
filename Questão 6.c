#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int isListInAscendingOrder(Node* head) {
    if (head == NULL || head->next == NULL) {
        // Lista vazia ou com apenas um elemento esta sempre em ordem crescente
        return 1;
    }

    Node* current = head;
    while (current->next != NULL) {
        if (current->data > current->next->data) {
            // Elemento atual e maior do que o proximo, lista nao esta em ordem crescente
            return 0;
        }
        current = current->next;
    }

    // Percorreu toda a lista e nao encontrou nenhum par de elementos fora de ordem
    return 1;
}

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 9);

    printf("Lista: ");
    display(head);

    int result = isListInAscendingOrder(head);
    if (result) {
        printf("A lista esta em ordem crescente.\n");
    } else {
        printf("A lista nao esta em ordem crescente.\n");
    }

    return 0;
}

