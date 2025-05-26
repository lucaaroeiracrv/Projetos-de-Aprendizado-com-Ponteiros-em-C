#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define NUM_CAVALOS 3
#define DISTANCIA 30

const char* nomes_cavalos[NUM_CAVALOS] = {"Relâmpago", "Trovão", "Furacão"};
const char* emoji_cavalo = "🐎"; // ou ">"

void mostrarCorrida(int posicoes[]) {
    system("cls");
    printf("LARGADA ");
    for (int i = 0; i < DISTANCIA; i++) printf("-");
    printf(" CHEGADA\n");
    for (int i = 0; i < NUM_CAVALOS; i++) {
        printf("%-10s: |", nomes_cavalos[i]);
        for (int j = 0; j < DISTANCIA; j++) {
            if (j == posicoes[i])
                printf("%s", emoji_cavalo);
            else
                printf(" ");
        }
        printf("|\n");
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int saldo = 100;

    printf("Bem-vindo à Corrida Maluca de Cavalos!\n");

    while (saldo > 0) {
        int posicoes[NUM_CAVALOS] = {0};
        int vencedor = -1;
        int cavalo_escolhido, aposta;

        printf("\nSeu saldo: R$%d\n", saldo);
        printf("Escolha um cavalo:\n");
        for (int i = 0; i < NUM_CAVALOS; i++)
            printf("%d - %s\n", i + 1, nomes_cavalos[i]);

        // Garantir cavalo válido
        do {
            printf("Digite o número do cavalo: ");
            scanf("%d", &cavalo_escolhido);
            if (cavalo_escolhido < 1 || cavalo_escolhido > NUM_CAVALOS)
                printf("Escolha inválida! Tente novamente.\n");
        } while (cavalo_escolhido < 1 || cavalo_escolhido > NUM_CAVALOS);
        cavalo_escolhido--;

        // Garantir aposta válida
        do {
            printf("Quanto deseja apostar? R$");
            scanf("%d", &aposta);
            if (aposta <= 0 || aposta > saldo)
                printf("Aposta inválida! Tente novamente.\n");
        } while (aposta <= 0 || aposta > saldo);

        printf("\nPreparar...\n");
        Sleep(700);
        printf("Apontar...\n");
        Sleep(700);
        printf("Já!\n");
        Sleep(700);

        srand(time(0));
        while (vencedor == -1) {
            for (int i = 0; i < NUM_CAVALOS; i++) {
                if (posicoes[i] < DISTANCIA - 1) {
                    posicoes[i] += rand() % 3;
                    if (posicoes[i] >= DISTANCIA - 1 && vencedor == -1) {
                        vencedor = i;
                    }
                }
            }
            mostrarCorrida(posicoes);
            Sleep(200);
        }

        printf("\nO cavalo %s venceu a corrida!\n", nomes_cavalos[vencedor]);
        if (cavalo_escolhido == vencedor) {
            printf("Parabéns! Você ganhou R$%d!\n", aposta * 2);
            saldo += aposta;
        } else {
            printf("Que pena! Você perdeu R$%d!\n", aposta);
            saldo -= aposta;
        }
        printf("Saldo atual: R$%d\n", saldo);

        if (saldo <= 0) {
            printf("\nSeu saldo acabou! Fim de jogo.\n");
            break;
        }

        char jogar_novamente;
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogar_novamente);
        if (jogar_novamente != 's' && jogar_novamente != 'S') {
            break;
        }
    }

    printf("\nObrigado por jogar!\n");
    return 0;
}

//tem q entrar em cd horse-racing-bet
//para ficar assim: PS D:\Luca\Desktop\Projetos-de-Aprendizado-com-Ponteiros-em-C\horse-racing-bet>
//para salvar: gcc horse-racing-bet.c -o horse-racing-bet.exe
//para compilar: .\horse-racing-bet.exe