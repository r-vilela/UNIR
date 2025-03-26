#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
		float a, b, c, delta, x1, x2;
		scanf("%f%f%f", &a, &b, &c);
		
		delta = b*b-4*a*c;

		if(delta >= 0){
				x1 = (-b+sqrt(delta))/2*a;
				x2 = (-b-sqrt(delta))/2*a;
				printf("x1=%.2f, x2 = %.2f", x1, x2);
		} else {
				printf("Nao ha raixes");
		}

		return 0;
}
