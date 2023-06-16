#include <stdio.h>

typedef struct {
    int conteudo;

} Celula;

Celula encontrarMinimoRecursivo(Celula* vetor, int tamanho, int indice) {
    if (indice == tamanho - 1) {
        return vetor[indice]; 
    }

    Celula proximoMinimo = encontrarMinimoRecursivo(vetor, tamanho, indice + 1);

    if (vetor[indice].conteudo < proximoMinimo.conteudo) {
        return vetor[indice];
    } else {
        return proximoMinimo;
    }
}

int main() {
    Celula vetor[] = { {5}, {2}, {10}, {1}, {8} };
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    Celula minimo = encontrarMinimoRecursivo(vetor, tamanho, 0);
    printf("O conteudo minimo e: %d\n", minimo.conteudo);

    return 0;
} 

/*
typedef struct {
    int conteudo;
} Celula;

Celula encontrarMinimoRecursivo(Celula* vetor, int tamanho, int indice) {
    if (indice == tamanho - 1) {
        return vetor[indice]; 
    }

    Celula proximoMinimo = encontrarMinimoRecursivo(vetor, tamanho, indice + 1);

    if (vetor[indice].conteudo < proximoMinimo.conteudo) {
        return vetor[indice];
    } else {
        return proximoMinimo;
    }
}

int main() {
    Celula vetor[] = { {5}, {2}, {10}, {1}, {8} };
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    Celula minimo = encontrarMinimoRecursivo(vetor, tamanho, 0);
    printf("O conteudo minimo e: %d\n", minimo.conteudo);

    return 0;
}

*/