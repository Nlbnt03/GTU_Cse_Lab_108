#include <stdio.h>
int str_len(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

int isPalindrome(char *str) {
    int length = str_len(str);
    for (int i = 0; i < length / 2; i++) 
    {
        if (str[i] != str[length - i - 1]) 
        {
            return 0;
        }
    }
    return 1;
}

int isPalindromeRecursive(char *str, int start, int end) {
    if (start >= end) 
    {
        return 1;
    }
    if (str[start] != str[end]) 
    {
        return 0;
    }
    return isPalindromeRecursive(str, start + 1, end - 1);
}

int main(int argc,char **argv)
{
    int result ;
    int i = 1;
    while (i < argc)
    {
        result = isPalindromeRecursive(argv[i], -1, str_len(argv[i]));
        if (result == 1)
        {
            printf("It is polindrome\n");
        }
        else if (result == 0)
        {
           printf("It is not polindrome\n");
        }
        else
        {
            printf("Error!\n");
        }
        i++;
    }


}