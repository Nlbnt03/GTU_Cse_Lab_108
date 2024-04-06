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

void compareArrays(double *arr1, double *arr2, int size, int *result)
{
    int i = 0;
    while (i < size)
    {
        if (arr1[i] > arr2[i])
        {
            result[i] = 0;
        }
        else
        {
            result[i] = 1;
        }
        i++;
    }

    int j = 0; 
    while(j < size)
    {
        if(j == (size - 1))
        {
            printf("%d ",result[j]);
        }
        else
        {
            printf("%d, ",result[j]);
        }
        j++;
    }
    printf("\n");
}
int main()
{
    double arr1[5];
    double arr2[5];
    int result[5];
    fillArray(arr1,5);
    fillArray(arr2,5);
    compareArrays(arr1, arr2, 5, result);
}