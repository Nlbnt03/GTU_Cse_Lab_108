#include <stdio.h>
#define PI 3.14

int main()
{
    double diameter;
    double area;

    printf("Enter a diameter :");
    scanf("%lf",&diameter);
    
    area = 4 * PI * (diameter * diameter);
    printf("r = %.2lf\n",diameter);
    printf("Area of sphere : %.2lf\n",area);
}