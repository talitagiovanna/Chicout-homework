#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int countWords(char* text) {
    int count = 0;
    int isWord = 0;

    while (*text != '\0') {
        if (isalpha(*text)) {
            if (!isWord) {
                count++;
                isWord = 1;
            }
        } else {
            isWord = 0;
        }
        text++;
    }

    return count;
}

int main() {
    char text[1000];
    printf("Digite um texto longo: ");
    fgets(text, sizeof(text), stdin);

    int numWords = countWords(text);
    printf("Número de palavras: %d\n", numWords);

    return 0;
}

// Questão 11 B. //

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char word[100];
    struct Node* next;
} Node;

int countDistinctWords(Node* head) {
    int count = 0;
    Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, char* word) {
    Node* newNode = createNode(word);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s ", temp->word);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int isWordExists(Node* head, char* word) {
    Node* current = head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0)
            return 1;
        current = current->next;
    }

    return 0;
}

int main() {
    char text[1000];
    printf("Digite um texto longo: ");
    fgets(text, sizeof(text), stdin);

    Node* wordList = NULL;
    char* token = strtok(text, " \t\n\r");
    while (token != NULL) {
        if (!isWordExists(wordList, token))
            insert(&wordList, token);
        token = strtok(NULL, " \t\n\r");
    }

    printf("Número de palavras distintas: %d\n", countDistinctWords(wordList));

    printf("Lista de palavras: ");
    display(wordList);

    freeList(wordList);

    return 0;
} */


// Questão 11 C 


/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char word[100];
    struct Node* next;
} Node;

float calculateAverageLength(Node* head) {
    int totalLetters = 0;
    int wordCount = 0;
    Node* current = head;

    while (current != NULL) {
        totalLetters += strlen(current->word);
        wordCount++;
        current = current->next;
    }

    if (wordCount > 0)
        return (float)totalLetters / wordCount;
    else
        return 0.0;
}

Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, char* word) {
    Node* newNode = createNode(word);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s ", temp->word);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char text[1000];
    printf("Digite um texto longo: ");
    fgets(text, sizeof(text), stdin);

    Node* wordList = NULL;
    char* token = strtok(text, " \t\n\r");
    while (token != NULL) {
        insert(&wordList, token);
        token = strtok(NULL, " \t\n\r");
    }

    float averageLength = calculateAverageLength(wordList);
    printf("Quantidade média de letras das palavras: %.2f\n", averageLength);

    printf("Lista de palavras: ");
    display(wordList);

    freeList(wordList);

    return 0;
} */


// Questão 11 D


/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char word[100];
    struct Node* next;
} Node;

char* findLongestWord(Node* head) {
    char* longestWord = NULL;
    int maxLength = 0;
    Node* current = head;

    while (current != NULL) {
        int length = strlen(current->word);
        if (length > maxLength) {
            maxLength = length;
            longestWord = current->word;
        }
        current = current->next;
    }

    return longestWord;
}

Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, char* word) {
    Node* newNode = createNode(word);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s ", temp->word);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char text[1000];
    printf("Digite um texto longo: ");
    fgets(text, sizeof(text), stdin);

    Node* wordList = NULL;
    char* token = strtok(text, " \t\n\r");
    while (token != NULL) {
        insert(&wordList, token);
        token = strtok(NULL, " \t\n\r");
    }

    char* longestWord = findLongestWord(wordList);
    if (longestWord != NULL)
        printf("Maior palavra: %s\n", longestWord);
    else
        printf("Nenhuma palavra encontrada.\n");

    printf("Lista de palavras: ");
    display(wordList);

    freeList(wordList);

    return 0;
} */



// Questão 11 E 

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char word[100];
    struct Node* next;
} Node;

char* findShortestWord(Node* head) {
    if (head == NULL)
        return NULL;

    Node* current = head;
    char* shortestWord = current->word;

    while (current != NULL) {
        if (strlen(current->word) < strlen(shortestWord))
            shortestWord = current->word;
        current = current->next;
    }

    return shortestWord;
}

Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, char* word) {
    Node* newNode = createNode(word);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s ", temp->word);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char text[1000];
    printf("Digite um texto longo: ");
    fgets(text, sizeof(text), stdin);

    Node* wordList = NULL;
    char* token = strtok(text, " \t\n\r");
    while (token != NULL) {
        insert(&wordList, token);
        token = strtok(NULL, " \t\n\r");
    }

    char* shortestWord = findShortestWord(wordList);
    if (shortestWord != NULL)
        printf("Menor palavra: %s\n", shortestWord);
    else
        printf("Nenhuma palavra encontrada.\n");

    printf("Lista de palavras: ");
    display(wordList);

    freeList(wordList);

    return 0;
} */


// Questão 11 F


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char word[100];
    int frequency;
    struct Node* next;
} Node;

char* findMostFrequentWord(Node* head) {
    if (head == NULL)
        return NULL;

    Node* current = head;
    char* mostFrequentWord = current->word;
    int maxFrequency = current->frequency;

    while (current != NULL) {
        if (current->frequency > maxFrequency) {
            mostFrequentWord = current->word;
            maxFrequency = current->frequency;
        }
        current = current->next;
    }

    return mostFrequentWord;
}

Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->frequency = 1;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, char* word) {
    if (*head == NULL) {
        *head = createNode(word);
    } else {
        Node* current = *head;
        while (current != NULL) {
            if (strcmp(current->word, word) == 0) {
                current->frequency++;
                return;
            }
            current = current->next;
        }
        Node* newNode = createNode(word);
        newNode->next = *head;
        *head = newNode;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s (%d) ", temp->word, temp->frequency);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char text[1000];
    printf("Digite um texto longo: ");
    fgets(text, sizeof(text), stdin);

    Node* wordList = NULL;
    char* token = strtok(text, " \t\n\r");
    while (token != NULL) {
        insert(&wordList, token);
        token = strtok(NULL, " \t\n\r");
    }

    char* mostFrequentWord = findMostFrequentWord(wordList);
    if (mostFrequentWord != NULL)
        printf("Palavra mais frequente: %s\n", mostFrequentWord);
    else
        printf("Nenhuma palavra encontrada.\n");

    printf("Lista de palavras: ");
    display(wordList);

    freeList(wordList);

    return 0;
} */


//  Questão 11 G


/*  #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char word[100];
    int frequency;
    struct Node* next;
} Node;

char* findRarestWord(Node* head) {
    if (head == NULL)
        return NULL;

    Node* current = head;
    char* rarestWord = current->word;
    int minFrequency = current->frequency;

    while (current != NULL) {
        if (current->frequency < minFrequency) {
            rarestWord = current->word;
            minFrequency = current->frequency;
        }
        current = current->next;
    }

    return rarestWord;
}

Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->frequency = 1;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, char* word) {
    if (*head == NULL) {
        *head = createNode(word);
    } else {
        Node* current = *head;
        while (current != NULL) {
            if (strcmp(current->word, word) == 0) {
                current->frequency++;
                return;
            }
            current = current->next;
        }
        Node* newNode = createNode(word);
        newNode->next = *head;
        *head = newNode;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s (%d) ", temp->word, temp->frequency);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char text[1000];
    printf("Digite um texto longo: ");
    fgets(text, sizeof(text), stdin);

    Node* wordList = NULL;
    char* token = strtok(text, " \t\n\r");
    while (token != NULL) {
        insert(&wordList, token);
        token = strtok(NULL, " \t\n\r");
    }

    char* rarestWord = findRarestWord(wordList);
    if (rarestWord != NULL)
        printf("Palavra mais rara: %s\n", rarestWord);
    else
        printf("Nenhuma palavra encontrada.\n");

    printf("Lista de palavras: ");
    display(wordList);

    freeList(wordList);

    return 0;
} */

