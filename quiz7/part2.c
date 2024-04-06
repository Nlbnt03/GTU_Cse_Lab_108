#include <stdio.h>
#define max_size 100

void insert_ordered(int a[], int *n, int x);
void get_max_n(const int a[], int n, int max);

int main() {
    int arr[max_size]; 
    int size = 0;
    int num;

    printf("Enter numbers (press q to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (getchar() == 'q') 
        {
            break;
        } 
        else if (size == max_size)
        {
            printf("invalid size!\n");
        }
        else
        {
            insert_ordered(arr, &size, num); 
        }
        printf("Top 5 items:\n");
        get_max_n(arr, size, max_size);
    }

    return 0;
}

void insert_ordered(int a[], int *n, int x) 
{
    int i, j;
    for (i = 0; i < *n; i++) 
    {
        if (x < a[i]) 
        {
            for (j = *n; j > i; j--) 
            {
                a[j] = a[j - 1];
            }
            a[i] = x;
            (*n)++; 
            return;
        }
    }
    a[*n] = x;
    (*n)++;
}

void get_max_n(const int a[], int n, int max) 
{
    int i;
    for (i = n - 1; i >= (n >= 5 ? n - 5 : 0); i--) 
    {
        printf("%d\n", a[i]);
    }
}