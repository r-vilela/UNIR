#include <stdio.h>
#include <stdlib.h>

int main()
{
		float salarioAtual, salarioNovo;

		printf("Digite o salario atual:");
		scanf("%f", &salarioAtual);
		salarioNovo = salarioAtual * 1.25;
		printf("O seu salario novo equivale a %.2f", salarioNovo);
}
