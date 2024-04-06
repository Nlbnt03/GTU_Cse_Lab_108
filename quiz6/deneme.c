#include <stdio.h>
int searchQuery(char *inputArr, char *targetArr)
{
    int i = 0;
    int size = 0;
    int j = 0;
   while (inputArr[i] != '\0')
	{
		if (inputArr[i] == targetArr[j])
		{
			i++;
			j++;
		}
		else if (targetArr[j] == '\0')
		{
			return (i - j);
		}
		else
		{
			i++;
			j = 0;
		}
	}
}
int main ()
{
    char inputArr[] = "Many that live deserve death. And some that die deserve life. Can you give it to them?";
    char targetArr[] = "life";
    int result = searchQuery(inputArr,targetArr);
    printf("life is contained in target at position %d\n", result);
}