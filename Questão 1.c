#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

/*
                    ------ Atividade de Listas Encadeadas ------

    1. Dada uma lista sequencial ordenada est�tica L1, escreva m�todos em C que:
    a. Verifique se L1 est� ordenada ou n�o (a ordem pode ser crescente ou
    decrescente)
    b. Fa�a uma c�pia da lista L1 em uma outra lista L2;
    c. Fa�a uma c�pia da Lista L1 em L2, eliminando elementos repetidos;
    d. Inverta L1 colocando o resultado em L2;
    e. Inverta L1 colocando o resultado na pr�pria L1;
    f. Intercale L1 com a lista L2, gerando a lista L3. considere que L1, L2 e L3 s�o
    ordenadas.
    g. Gere uma lista L2 onde cada registro cont�m dois campos de informa��o: elem
    cont�m um elemento de L1, e count cont�m quantas vezes este elemento
    aparece em L1.
    h. Elimine de L1 todas as ocorr�ncias de um elemento dado, L1 ordenada.
    i. Assumindo que os elementos da lista L1 s�o inteiros positivos, forne�a os
    elementos que aparecem o maior e o menor n�mero de vezes (forne�a os
    elementos e o n�mero de vezes correspondente)

*/


/*
	Espa�o respons�vel pela letra a da quest�o 1.
*/

bool esta_ordenada(int L1[], int size) {
    // Verificar a ordem crescente
    bool ordem_crescente = true;
	
	for (int i = 1; i < size; i++) {
        if (L1[i] < L1[i-1]) {
            ordem_crescente = false;
            break;
        }
    }

    // Verificar a ordem decrescente
    bool ordem_decrescente = true;
    
    for (int i = 1; i < size; i++) {
        if (L1[i] > L1[i-1]) {
            ordem_decrescente = false;
            break;
        }
    }

    // Retornar o resultado
    return ordem_crescente || ordem_decrescente;
}

/*
	Espa�o respons�vel pela letra b da quest�o 1.
	
*/

void lista_copia(int L1[], int L2[], int size) {
    for (int i = 0; i < size; i++) {
        L2[i] = L1[i];
    }
}

/*
	Espa�o respons�vel pela letra c da quest�o 1.
	
*/

void copiar_lista_sem_repeticao(int L1[], int size1, int L2[], int *size2) {
    int i, j;
    int found;

    // Percorrer L1
    for (i = 0; i < size1; i++) {
        found = 0;

        // Verificar se o elemento j� est� presente em L2
        for (j = 0; j < *size2; j++) {
            if (L1[i] == L2[j]) {
                found = 1;
                break;
            }
        }

        // Adicionar o elemento em L2, se n�o estiver presente
        if (!found) {
            L2[*size2] = L1[i];
            (*size2)++;
        }
    }
}

/*
	Espa�o respons�vel pela letra d da quest�o 1.
	
*/

void lista_reversa(int L1[], int L2[], int size) {
    for (int i = size - 1, j = 0; i >= 0; i--, j++) {
        L2[j] = L1[i];
    }
}

/*
	Espa�o respons�vel pela letra e da quest�o 1.
*/

void reversa_lista(int L1[], int size) {
	
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // Trocar os elementos de posi��o
        int temp = L1[start];
        L1[start] = L1[end];
        L1[end] = temp;

        // Avan�ar para os pr�ximos elementos
        start++;
        end--;
    }
}

/*
	Espa�o respons�vel pela letra f da quest�o 1.
*/

void intercalar_listas(int L1[], int size1, int L2[], int size2, int L3[]) {
    int i = 0;  // �ndice para percorrer L1
    int j = 0;  // �ndice para percorrer L2
    int k = 0;  // �ndice para percorrer L3

    // Percorrer L1 e L2 enquanto houver elementos em ambas as listas
    while (i < size1 && j < size2) {
        L3[k++] = L1[i++];
        L3[k++] = L2[j++];
    }

    // Adicionar os elementos restantes de L1, se houver
    while (i < size1) {
        L3[k++] = L1[i++];
    }

    // Adicionar os elementos restantes de L2, se houver
    while (j < size2) {
        L3[k++] = L2[j++];
    }
}

/*

	Espa�o respons�vel pela letra g da quest�o 1.
	
*/

typedef struct {
    int elem;
    int count;
} ListaItem;

void contar_lista(int source[], int size, ListaItem destination[], int* countSize) {
    int countIndex = 0;
    int currentElement = source[0];
    int currentCount = 1;

    for (int i = 1; i < size; i++) {
        if (source[i] == currentElement) {
            currentCount++;
        } else {
            destination[countIndex].elem = currentElement;
            destination[countIndex].count = currentCount;
            countIndex++;

            currentElement = source[i];
            currentCount = 1;
        }
    }

    destination[countIndex].elem = currentElement;
    destination[countIndex].count = currentCount;
    countIndex++;

    *countSize = countIndex;
}

/*

	Espa�o respons�vel pela letra h da quest�o 1.
	
*/

void remover_ocorrencias(int list[], int size, int element) {
    int i, j;
    int newLength = 0;

    for (i = 0, j = 0; i < size; i++) {
        if (list[i] != element) {
            list[j++] = list[i];
            newLength++;
        }
    }

    // Preenche o restante da lista com zeros
    for (i = newLength; i < size; i++) {
        list[i] = 0;
    }
}

/*

	Espa�o respons�vel pela letra i da quest�o 1.
	
*/

void encontrar_maior_menor_ocorrencia(int list[], int size) {
    int maxElement = INT_MIN;
    int minElement = INT_MAX;
    int maxCount = 0;
    int minCount = INT_MAX;
    int countMap[10] = {0};

    // Conta as ocorr�ncias de cada elemento
    for (int i = 0; i < size; i++) {
        countMap[list[i]]++;
    }

    // Encontra o elemento com a contagem m�xima e m�nima
    for (int i = 0; i < 10; i++) {
        if (countMap[i] > 0) {
            if (countMap[i] > maxCount) {
                maxCount = countMap[i];
                maxElement = i;
            }
            if (countMap[i] < minCount) {
                minCount = countMap[i];
                minElement = i;
            }
        }
    }

    // Imprime o resultado
    printf("Elemento com maior ocorr�ncia: %d (ocorr�ncias: %d)\n", maxElement, maxCount);
    printf("Elemento com menor ocorr�ncia: %d (ocorr�ncias: %d)\n", minElement, minCount);
}


int main() {
	
    int L1[5] = {1, 2, 3, 4, 5};  // Exemplo de lista ordenada crescente
    //int L1[] = {5, 4, 3, 2, 1}; // Exemplo de lista ordenada descrescente
    //int L1[] = {1, 5, 4, 2, 3}; // Exemplo de lista n�o ordenada
    int L5[5];
    
    /*
    
	Espa�o respons�vel pela letra a da quest�o 1.
    
    */
    
    int size = sizeof(L1) / sizeof(L1[0]);
    
    if (esta_ordenada(L1, size)) {
    	printf("L1: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", L1[i]);
        }
        printf("\n");
        printf("A lista est� ordenada.\n");
    } else {
    	printf("L1: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", L1[i]);
        }
        printf("\n");
        printf("A lista n�o est� ordenada.\n");
    }
    
    /*
    
	Espa�o respons�vel pela letra b da quest�o 1.
	
    */  
    
    int L2[5];
    
    lista_copia(L1, L2, size);
    
    printf("\n");
    printf("Lista L2: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", L2[i]);
    }
    printf("\n");
    
    /*
    
	Espa�o respons�vel pela letra c da quest�o 1.
	
    */ 
    
    int L3[] = {1, 2, 3, 2, 4, 5, 3, 2, 2, 2};  // Lista L1
    int size1 = sizeof(L3) / sizeof(L3[0]);

    int L4[size1];  // Lista L2
    int size2 = 0;  // Tamanho de L2

    copiar_lista_sem_repeticao(L3, size1, L4, &size2);
    
    printf("\n");
    printf("L1: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", L3[i]);
    }
    printf("\n");
    // Exibir os elementos de L2
    printf("Lista L2 (sem repeti��o): ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", L4[i]);
    }
    printf("\n");
    
    /*
	Espa�o respons�vel pela letra d da quest�o 1.
	
    */
    
    lista_reversa(L1, L5, size);
    
    printf("\n");
    printf("L1: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", L1[i]);
    }
    printf("\n");
    printf("Lista L2 (invertida): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", L5[i]);
    }
    printf("\n");
    
    /*
    
	Espa�o respons�vel pela letra e da quest�o 1.
	
    */
    
    printf("\n");
    printf("L1: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", L1[i]);
    }
    printf("\n");
    
    reversa_lista(L1, size);
    
    // Exibir os elementos de L1 (agora invertida)
    printf("Lista L1 (invertida): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", L1[i]);
    }
    printf("\n");
    
    /*
    
	Espa�o respons�vel pela letra f da quest�o 1.
	
    */
    
    int L6[5] = {1, 3, 5, 7, 9};      // Lista ordenada L1
    int size3 = sizeof(L6) / sizeof(L6[0]);

    int L7[5] = {2, 4, 6, 8, 10};      // Lista ordenada L2
    int size4 = sizeof(L7) / sizeof(L7[0]);

    int L8[size3 + size4];  // Lista L3 para a intercala��o

    intercalar_listas(L6, size3, L7, size4, L8);
    
    printf("\n");
    printf("Lista L1: ");
    for (int i = 0; i < size3; i++) {
        printf("%d ", L6[i]);
    }
    printf("\n");
    printf("Lista L2: ");
    for (int i = 0; i < size4; i++) {
        printf("%d ", L7[i]);
    }
    printf("\n");
    // Exibir os elementos de L5 (intercalada)
    printf("Lista L3 (intercalada): ");
    for (int i = 0; i < size3 + size4; i++) {
        printf("%d ", L8[i]);
    }
    printf("\n");
    
    /*
    
	Espa�o respons�vel pela letra g da quest�o 1.
	
    */
    
    int L9[10] = {1, 2, 2, 2, 3, 4, 4, 5, 5, 5};
    ListaItem L10[10];
    int countSize = 0;
    int size5 = sizeof(L9) / sizeof(L9[0]);
    
    contar_lista(L9, size5, L10, &countSize);
    
    printf("\n");
    printf("Lista L1: ");
    for (int i = 0; i < size5; i++) {
        printf("%d ", L9[i]);
    }
	printf("\n");
	
	printf("Lista L2 (elemento e quantidade de ocorr�ncias):\n");
    for (int i = 0; i < countSize; i++) {
        printf("Elemento: %d, Contagem: %d\n", L10[i].elem, L10[i].count);
    }
	
	/*

	Espa�o respons�vel pela letra h da quest�o 1.
	
	*/
	
	int L11[10] = {1, 2, 2, 3, 4, 4, 4, 5, 6, 7};
    int size6 = sizeof(L11) / sizeof(L11[0]);
    int elemento_para_remover = 4;
    
	printf("\n");
    printf("Lista L1 antes da remo��o: ");
    for (int i = 0; i < size6; i++) {
        printf("%d ", L11[i]);
    }
    printf("\n");
    
    remover_ocorrencias(L11, size6, elemento_para_remover);

    printf("Lista L1 ap�s a remo��o das ocorr�ncias de %d: ", elemento_para_remover);
    for (int i = 0; i < size6; i++) {
        printf("%d ", L11[i]);
    }
    printf("\n");
    
    /*

	Espa�o respons�vel pela letra i da quest�o 1.
	
	*/
	
	int L12[10] = {1, 2, 2, 3, 3, 3, 4, 4, 5, 5};
	
	printf("\n");
    printf("Lista L1: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", L12[i]);
    }
    printf("\n");

    encontrar_maior_menor_ocorrencia(L12, 10);

    return 0;
}
