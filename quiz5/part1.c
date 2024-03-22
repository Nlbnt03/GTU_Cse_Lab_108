#include <stdio.h>
#include "degree.h"

void print_temperatures(double celsius, double fahrenheit, double kelvin)
{
    printf("The degree in Celsius : %.2lf\n", celsius);
    printf("The degree in Fahrenheit : %.2lf\n", fahrenheit);
    printf("The degree in Kelvin : %.2lf\n", kelvin);
}

int main()
{
    int choice;
    double celsius = 0.0;
    double fahrenheit = 0.0;
    double kelvin = 0.0;
    int flag = 1;
    printf("1. Convert to fahrenheit (enter celcius degree)\n2. convert to celsius (enter fahrenheit degree)\n3. convert to kelvin (enter celcius degre)\n0. Choose if you want to exit\n");
    while (flag)
    {
        printf("choose an option (1, 2, 3, or 0 to exit) :");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter Celsius degree : ");
            scanf("%lf",&celsius);
            celsius_to_fah_kel(celsius, &fahrenheit, &kelvin);
            print_temperatures(celsius, fahrenheit, kelvin);
            break;
        case 2:
            printf("Enter fahrenheit degree : ");
            scanf("%lf",&fahrenheit);
            fahrenheit_to_cel_kel(fahrenheit,&celsius,&kelvin);
            print_temperatures(celsius, fahrenheit, kelvin);
            break;
        case 3:
            printf("Enter kelvin degree : ");
            scanf("%lf",&kelvin);
            kelvin_to_cel_fah(kelvin,&celsius,&fahrenheit);
            print_temperatures(celsius, fahrenheit, kelvin);
            break;
        case 0:
            printf("exiting program.\n");
            flag = 0;
            break;            
        default:
            printf("invalid option!!!\n");
            break;
        }   
    }
}