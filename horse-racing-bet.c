#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // use _sleep no Windows (ou comente se necessário)

#define NUM_CAVALOS 3
#define DISTANCIA 30

void mostrarCorrida(int posicoes[]) {
    system("clear"); // use "cls" no Windows

    for (int i = 0; i < NUM_CAVALOS; i++) {
        printf("Cavalo %d: ", i + 1);
        for (int j = 0; j < posicoes[i]; j++) {
            printf(" ");
        }
        printf(">>'\n"); // desenho simples do cavalo
    }
}

int main() {
    int posicoes[NUM_CAVALOS] = {0};
    int vencedor = -1;
    int cavalo_escolhido;

    printf("Escolha um cavalo de 1 a 3:");
    scanf("%d", &cavalo_escolhido);

    srand(time(0));

    while (vencedor == -1) {
        for (int i = 0; i < NUM_CAVALOS; i++) {
            if (posicoes[i] < DISTANCIA) {
                posicoes[i] += rand() % 3; // avanço aleatório (0 a 2)
                if (posicoes[i] >= DISTANCIA && vencedor == -1) {
                    vencedor = i + 1;
                }
            }
        }

        mostrarCorrida(posicoes);
        usleep(200000); // 200ms
    }

    printf("\nO cavalo %d venceu a corrida!\n", vencedor);
    if(cavalo_escolhido == vencedor) {
        printf("Parabéns! Você ganhou!");
    }else{
        printf("Hahahah você perdeu, passa o dinheiro");
    }
    return 0;
}
