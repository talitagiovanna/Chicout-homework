#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct No {
    char* dado;
    struct No* proximo;
} No;


No* criarNo(char* dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = strdup(dado);
    novoNo->proximo = NULL;
    return novoNo;
}


void inserir(No** inicio, char* dado) {
    No* novoNo = criarNo(dado);
    if (*inicio == NULL) {
        *inicio = novoNo;
    } else {
        novoNo->proximo = *inicio;
        *inicio = novoNo;
    }
}


void removerElemento(No** inicio, char* dado) {
    if (*inicio == NULL) {
        return;
    }

    No* noAtual = *inicio;
    No* noAnterior = NULL;

 
    if (strcmp(noAtual->dado, dado) == 0) {
        *inicio = noAtual->proximo;
        free(noAtual->dado);
        free(noAtual);
        return;
    }

  
    while (noAtual != NULL && strcmp(noAtual->dado, dado) != 0) {
        noAnterior = noAtual;
        noAtual = noAtual->proximo;
    }


    if (noAtual != NULL) {
        noAnterior->proximo = noAtual->proximo;
        free(noAtual->dado);
        free(noAtual);
    }
}


int buscar(No* inicio, char* dado) {
    No* noAtual = inicio;

    
    while (noAtual != NULL) {
        if (strcmp(noAtual->dado, dado) == 0) {
            return 1; 
        }
        noAtual = noAtual->proximo;
    }

    return 0; 
}


int listaVazia(No* inicio) {
    return inicio == NULL;
}


int tamanhoLista(No* inicio) {
    int tamanho = 0;
    No* noAtual = inicio;

   
    while (noAtual != NULL) {
        tamanho++;
        noAtual = noAtual->proximo;
    }

    return tamanho;
}


int calcularPerdaMemoria(No* inicio) {
    int perdaMemoria = 0;
    No* noAtual = inicio;

    
    while (noAtual != NULL) {
        if (noAtual->dado == NULL) {
            perdaMemoria++;
        }
        noAtual = noAtual->proximo;
    }

    return perdaMemoria;
}


void liberarLista(No* inicio) {
    No* noAtual = inicio;
    No* proximoNo = NULL;


    while (noAtual != NULL) {
        proximoNo = noAtual->proximo;
        free(noAtual->dado);
        free(noAtual);
        noAtual = proximoNo;
    }
}

int main() {
    No* minhaLista = NULL;

   
    inserir(&minhaLista, "Oi");
    inserir(&minhaLista, "Teste");
    inserir(&minhaLista, "Sete");
    inserir(&minhaLista, "Sete Sete");
    inserir(&minhaLista, "Sete Sete Sete");

 
    if (listaVazia(minhaLista)) {
        printf("\n\tA lista esta vazia.\n");
    } else {
        printf("\n\tA lista nao esta vazia.\n");
    }


    if (buscar(minhaLista, "Teste")) {
        printf("\n\tO elemento 'Teste' foi encontrado na lista.\n");
    } else {
        printf("\n\tO elemento 'Teste' não foi encontrado na lista.\n");
    }

    if (buscar(minhaLista, "Iago")) {
        printf("\n\tO elemento 'Iago' foi encontrado na lista.\n");
    } else {
        printf("\n\tO elemento 'Iago' nao foi encontrado na lista.\n");
    }

    
    removerElemento(&minhaLista, "Sete");

   
    int tamanho = tamanhoLista(minhaLista);
    printf("\n\tTamanho da lista: %d\n", tamanho);


    int perdaMemoria = calcularPerdaMemoria(minhaLista);
    printf("\n\tPerda de memoria: %d\n", perdaMemoria);


    liberarLista(minhaLista);

    return 0;
}
