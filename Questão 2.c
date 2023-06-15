#include <stdio.h>

#define TAMANHO 50

int lista[TAMANHO];
int comprimento = 0;

void imprimirLista() {
    printf("Lista: ");
    for (int i = 0; i < comprimento; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void inserirCrescente(int x) {
    if (comprimento >= TAMANHO) {
        printf("Lista cheia. Não é possível inserir mais elementos.\n");
        return;
    }

    int i = comprimento - 1;
    while (i >= 0 && lista[i] > x) {
        lista[i + 1] = lista[i];
        i--;
    }

    lista[i + 1] = x;
    comprimento++;
}

void inserirDecrescente(int x) {
    if (comprimento >= TAMANHO) {
        printf("Lista cheia. Não é possível inserir mais elementos.\n");
        return;
    }

    int i = comprimento - 1;
    while (i >= 0 && lista[i] < x) {
        lista[i + 1] = lista[i];
        i--;
    }

    lista[i + 1] = x;
    comprimento++;
}

int main() {
    // Inserindo elementos em ordem crescente
    inserirCrescente(5);
    inserirCrescente(3);
    inserirCrescente(8);
    inserirCrescente(2);
    inserirCrescente(7);

    imprimirLista();

    // Inserindo elementos em ordem decrescente
    inserirDecrescente(10);
    inserirDecrescente(12);
    inserirDecrescente(6);
    inserirDecrescente(4);
    inserirDecrescente(9);

    imprimirLista();

    return 0;
}
