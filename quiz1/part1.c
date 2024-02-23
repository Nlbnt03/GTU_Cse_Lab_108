#include <stdio.h>

int main()
{
    int i1, i2, i3, i4;

    printf("Enter a i1 :");
    scanf("%d",&i1);
     printf("Enter a i2 :");
    scanf("%d",&i2);
     printf("Enter a i3 :");
    scanf("%d",&i3);
     printf("Enter a i4 :");
    scanf("%d",&i4);

    double result1, result2, result3;
    result1 = ((i1 * i1) + (i3 * i4)) - i1;
    
    int tmp1 , tmp2 , tmp3, tmp4;
    tmp1 = i1;
    tmp1 = tmp1 * 3;

    tmp2 = i2;
    tmp2 = tmp2 * 5;

    tmp3 = i3;
    tmp3 = tmp3 * 7;
    
    tmp4 = i4;
    tmp4 = tmp4 * 9;


    result2 = tmp1 + tmp2 + tmp3 + tmp4;

    result3 = (double)(i1 + i2 + i3 + i4) / (double)(i1 * i2 * i3 * i4);

    printf("result 1 : %lf\n", result1);
    printf("result 2 : %lf\n",result2);
    printf("result 3 : %lf\n",result3);
}