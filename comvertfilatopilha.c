#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma fila
typedef struct {
    void **dados;      // Ponteiro genérico para armazenar os elementos da fila
    int inicio;        // Índice do primeiro elemento na fila
    int fim;           // Índice do último elemento na fila
    int tamanho;       // Número atual de elementos na fila
    int capacidade;    // Capacidade total da fila
} Pila;



void lenght(Pilha *pilha){ 
    lenght = sizeof(pilha)/sizeof(pilha[0]) ;
    return lenght; 
}



// Função para criar uma fila com capacidade inicial
Pila* criarPila(int capacidadeInicial) {
    Pila *pilha = (Pilha *) malloc(sizeof(Pilha)); // Aloca memória para a fila
    if (pilha == NULL) return NULL; // Verifica se a alocação falhou

    // Aloca memória para os dados da fila
    pilha->dados = (void **) malloc(sizeof(void *) * capacidadeInicial);
    pilha->inicio = 0; // Inicializa o índice de início
    pilha->fim = 0;   // Inicializa o índice de fim
    pilha->tamanho = lenght(Pilha); // Inicializa o tamanho da fila
    pilha->capacidade = capacidadeInicial; // Define a capacidade da fila

    return pilha; // Retorna a fila criada
}

// Função para limpar a fila e liberar a memória
void limparFila(Pilha *pilha) {
    if (pilha != NULL) {
        free(pilha->dados); // Libera a memória dos dados
        free(pilha); // Libera a memória da estrutura da fila
    }
}

// Função para dobrar a capacidade da fila
void dobrarCapacidade(Pilha *pilha) {
    int newCapacidade = pilha->capacidade * 2; // Nova capacidade
    void **a = (void **) malloc(sizeof(void*) * newCapacidade); // Aloca nova memória para os dados

    // Copia os elementos existentes para a nova estrutura
    for (int i = 0; i < pilha->tamanho; i++) {
        a[i] = pilha->dados[(pilha->inicio + i) % pilha->capacidade];
    }

    free(pilha->dados); // Libera a memória da antiga estrutura
    pilha->dados = a; // Atualiza o ponteiro para os novos dados
    pilha->capacidade = newCapacidade; // Atualiza a capacidade
    pilha->inicio = 0; // Reinicializa o índice de início
    pilha->fim = pilha->tamanho - 1; // Atualiza o índice de fim
}

// Função para inserir um elemento na fila
void inserirNaPilha(Pilha *pilha, void *e) {
    if (pilha->tamanho == pilha->capacidade) { // Verifica se a fila está cheia
        dobrarCapacidade(pilha); // Dobra a capacidade se necessário
    }

    pilha->fim = (pilha->fim + 1) % pilha->capacidade; // Move o índice de fim para a frente
    pilha->dados[pilha->fim] = e; // Insere o novo elemento
    pilha->tamanho++; // Incrementa o tamanho da fila
}

// Função para remover um elemento da fila
void* removerDaFila(Pilha *pilha) {
    if (pilha->tamanho == 0) {
        return NULL; // Retorna NULL se a fila estiver vazia
    }

    void *e = pilha->dados[pilha->inicio]; // Armazena o elemento a ser removido
    pilha->inicio = (pilha->inicio + 1) % pilha->capacidade; // Move o índice de início para a frente
    pilha->tamanho--; // Decrementa o tamanho da fila
    return e; // Retorna o elemento removido
}

// Função para mostrar os elementos na fila
void mostrarFila(Pilha *pilha) {
    printf("Elementos na pilha: ");
    for (int i = 0; i < pilha->tamanho; i++) {
        int valor = *(int *)pilha->dados[(pilha->inicio + i) % pilha->capacidade]; // Acessa o valor
        printf("%d ", valor); // Imprime o valor
    }
    printf("\n");
}

// Função principal para testar a fila
int main (){
    Pilha* pilha = criarPilha(2); // Cria uma fila com capacidade inicial de 2

    int a = 1, b = 2, c = 3; // Define alguns valores inteiros
    inserirNaPilha(pilha, &a); // Insere 'a' na fila
    inserirNaPilha(pilha, &b); // Insere 'b' na fila
    printf("Capacidade antes de dobrar: %d\n", pilha->capacidade); // Mostra a capacidade atual
    mostrarPilha(pilha); // Exibe os elementos na fila

    inserirNaPilha(pilha, &c); // Insere 'c', o que provoca a dobra da capacidade

    printf("Capacidade depois de dobrar: %d\n", pilha->capacidade); // Mostra a nova capacidade
    mostrarPilha(pilha); // Exibe os elementos na fila

    int *removed = (int *)removerDaPilha(pilha); // Remove um elemento da fila
    printf("Elemento removido: %d\n", *removed); // Mostra o elemento removido
    mostrarPilha(pilha); // Exibe os elementos restantes na fila
    limparPilha(pilha); // Limpa a fila e libera a memória
    return 0; // Retorna 0, indicando que o programa terminou com sucesso
}
