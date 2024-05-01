#include <stdio.h>
#define MAXIT 100
int hs(int nums[], int *cn, int maxit)
{
    if (nums[*cn - 1] == 1)
    {
        return *cn;
    }
    else if(nums[*cn - 1] % 2 == 0)
    {
        nums[*cn ] = nums[*cn - 1] / 2;
        (*cn) ++;
        return hs(nums, cn, MAXIT);
    }
    else if(nums[*cn - 1] % 2 != 0)
    {
        nums[*cn ] = (nums[*cn - 1] * 3) + 1;
        (*cn) ++;
        return hs(nums, cn, MAXIT);
    }
    
}

int main()
{
    int a[MAXIT] = {5};
    int n = 1;
    n = hs(a, &n, MAXIT);
    printf("n = %d\n",n);
    int i;
    while (a[i] != NULL)
    {
        printf("%d ",a[i]);
        i++;
    }
    printf("\n");
}