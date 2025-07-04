#include <stdio.h>
#include <math.h>

int main(){

    double p = 0.0f;
    double r = 0.0f;
    int t = 0;
    int n = 0;
    double total = 0.0;

    printf("Compound Interest Calculator\n");

    printf("Enter the principal (p): ");
    scanf("%lf", &p);

    printf("Enter the Interest Rate % (r): ");
    scanf("%lf", &r);
    r = r/100;

    printf("Enter the # of years (t): ");
    scanf("%d", &t);

    printf("Enter the # of times compounded per year (n): ");
    scanf("%d", &n);

    total = p*pow((1+(r/n)), (n*t));

    printf("After %d years, the total will be %.2lf", t, total);

}
