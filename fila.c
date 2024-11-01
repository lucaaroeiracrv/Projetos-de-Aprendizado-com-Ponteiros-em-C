#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void **dados;      // Ponteiro genérico para os elementos da fila
    int inicio;        // Índice do primeiro elemento
    int fim;           // Índice do último elemento
    int tamanho;       // Número de elementos atual da fila
    int capacidade;    // Capacidade total da fila
} Fila;

Fila* criarFila(int capacidadeInicial) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    if (fila == NULL) return NULL;

    fila->dados = (void *) malloc(sizeof(void) * capacidadeInicial);
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
    fila->capacidade = capacidadeInicial;

    return fila;
}

void limparFila(Fila *fila) {
    if (fila != NULL) {
        free(fila->dados);
        free(fila);
    }
}

void dobrarCapacidade(Fila *fila) {
    int newCapacidade = fila->capacidade * 2;
    void *a = (void *) malloc(sizeof(void*) * newCapacidade);

    for (int i = 0; i < fila->tamanho; i++) {
        a[i] = fila->dados[(fila->inicio + i) % fila->capacidade];
    }

    free(fila->dados);
    fila->dados = a;
    fila->capacidade = newCapacidade;
    fila->inicio = 0;
    fila->fim = fila->tamanho - 1;
}

void inserirNaFila(Fila *fila, void *e) {
    if (fila->tamanho == fila->capacidade) {
        dobrarCapacidade(fila);
    }

    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->dados[fila->fim] = e;
    fila->tamanho++;
}

void* removerDaFila(Fila *fila) {
    if (fila->tamanho == 0) {
        return NULL;
    }

    void *e = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
    return e;
}

void mostrarFila(Fila *fila) {
    printf("Elementos na fila: ");
    for (int i = 0; i < fila->tamanho; i++) {
        int valor = (int) fila->dados[(fila->inicio + i) % fila->capacidade];
        printf("%d ", *valor);
    }
    printf("\n");
}

int main (){
    Fila* fila = criarFila(2);

    int a = 1, b = 2, c = 3;
    inserirNaFila(fila, &a);
    inserirNaFila(fila, &b);
    printf("Capacidade antes de dobrar: %d\n", fila->capacidade);
    mostrarFila(fila);

    inserirNaFila(fila, &c);

    printf("Capacidade depois de dobrar: %d\n", fila->capacidade);
    mostrarFila(fila);

    int *removed = (int *)removerDaFila(fila);
    printf("Elemento removido: %d\n", *removed);
    mostrarFila(fila);
    limparFila(fila);
    return 0;
}
