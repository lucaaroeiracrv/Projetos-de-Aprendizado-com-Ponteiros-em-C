#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, numerosGerados;

	printf("Quantos numeros vC#o ser gerados?: ");
	scanf("%d", &numerosGerados);

	int* ptr = (int*) malloc(numerosGerados * sizeof(int));
	if (ptr == NULL) {
		printf("Erro\n");
		return 1;
	}
	for (i = 0; i < numerosGerados; ++i) {
		ptr[i] = rand() % 100;
		printf("%d\n", ptr[i]);
	}
	free(ptr);

	return 0;
}
