#include <stdio.h>

void fillArray(double *arr, int size)
{
    int flagSize = size;
    int i = 0;
    while (i < size)
    {
        printf("enter a double number :");
        scanf("%lf", &arr[i]);
        i++;   
    }
}

int main()
{
    double arr[5];
    fillArray(arr, 5);
    int i = 0;
    while (i < 5)
    {
        printf("%.2lf,",arr[i]);
        i++;
    }
    
}