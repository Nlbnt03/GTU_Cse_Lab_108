#include <stdio.h>

int countLetter(char *arr, char c)
{
    int i = 0;
    int counter  = 0;
    while (arr[i] != '\0')
    {
        if (c >= 'a' && c <= 'z')
        {
            if (arr[i] == c || arr[i] == c - 32)
            {
                counter++;
            }
        }
        else if (c >= 'A' && c <= 'Z')
        {
            if (arr[i] == c || arr[i] == c + 32)
            {
                counter++;
            }
        }
        i++;
    }
    return (counter);
}

void mostCountedLetter(char *arr, char *alph, int *num)
{
    int i = 0;
    int result = 0;
    while (alph[i] != '\0')
    {
        result = countLetter(arr, alph[i]);
        num[i] = result;
        i++;
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 25 - i; j++)
        {
            if (num[j] < num[j + 1])
            {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;

    
                char temp_char = alph[j];
                alph[j] = alph[j + 1];
                alph[j + 1] = temp_char;
            }
        }
    }
}

int main() {
    int num[27];
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int result;
    char exp[] = "aaabbccccn";
    result = countLetter(exp, 't');
    printf("%d\n", result);
    mostCountedLetter(exp, alphabet, num);
    int j = 0;
    while (j < 26) {
        printf("%d. letter: %c - %d times, ", (j+1), alphabet[j], num[j]);
        j++;
    }
    return 0;
}