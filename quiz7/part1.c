#include <stdio.h>
#define max_size 100

void setArray(double arr[], int size)
{
    int i = 0;
    printf("Enter %d elements :\n", size);
    while (i < size)
    {
        scanf("%lf", &arr[i]);
        i++;
    }
    printf("worked setArray Function\n");
}

double getArrayElement(double arr[], int index)
{
    return (arr[index]);
}

void updateArray(double arr[], int size)
{
    int i = 0;
    double item;
    while (i < size)
    {   
        item = getArrayElement(arr, i);
        if (i % 2 == 0)
        {
            arr[i] = item / 2.0;
        }
        else
        {
            arr[i] = item * 2.0;
        }
        i++;
    }
    printf("\nworked updateArray Function\n");
}

void printArray(double arr[], int size)
{
    int i = 0;
    while (i < size)
    {
        printf("%.2lf\n",arr[i]);
        i++;
    }
    printf("worked printArray Function\n");
}

int main()
{
    double arr[max_size];
    int size;
    
    printf("Enter the size of the array (max 100) :");
    scanf("%d", &size);
    setArray(arr, size);
    printf("----------\n");
    updateArray(arr, size);
    printf("----------\n");
    printArray(arr, size);
    printf("----------\n");
}