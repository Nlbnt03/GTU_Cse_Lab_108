#include <stdio.h>
#include <math.h>

int main()
{
   //int x = pow(2,32);
   //int result = x - 1;
   //printf("%d\n",result);

   int number1 = 2147483647;
   int number2 = 2;
   double result3 = (double)number1 + (double)number2;
   int result2 = number1 + number2;
   printf("sum of %d and %d should be : %.0lf\n",number1, number2, result3);
   printf("but c says that %d + %d = %d\n",number1, number2, result2);
}