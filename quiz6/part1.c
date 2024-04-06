#include <stdio.h>
int	is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb == 0 || nb == 1)
		return (0);
	else if (nb == 2)
		return (1);
	else
	{
		while (i < nb)
		{
			if (nb % i == 0)
				return (0);
			i++;
		}
	}
	return (1);
}

void countPrimes(int *numbers)
{
    int counter = 0;
    int i = 0;
    while (numbers[i] != '\0')
    {
        if (is_prime(numbers[i]) == 1)
        {
            counter++;
        }
        i++;
    }
    printf("There are %d prime numbers in array\n",counter);
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    countPrimes(arr);   
}