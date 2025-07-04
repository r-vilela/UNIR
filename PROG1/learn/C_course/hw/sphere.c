#include <stdio.h>
#include <math.h>

int main(){

    double radius = 0.0;
    const double PI = 3.14159;
    double area = 0.0;
    double surfarce = 0.0;
    double volume = 0.0;

    printf("Sphere radius: ");
    scanf("%lf", &radius);

    area = PI * pow(radius, 2);
    surfarce = 4 * PI * pow(radius, 2);
    volume = (4.0/3.0) * PI * pow(radius, 3);


    printf("Area: %.3lf\n", area);
    printf("Surface Area: %.3lf\n", surfarce);
    printf("Volume: %.3lf\n", volume);


}
