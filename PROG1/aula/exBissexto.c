#include <stdio.h>
#include <stdlib.h>

int main () {
		int ano;

		printf("Digite um ano: ");
		scanf("%d", &ano);

		if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)){
				printf("O ano %d eh bissexto", ano);
		} else {
				printf("O ano %d nao eh bissexto", ano);
		}

		return 0;
}
