#include <stdio.h>

int str_len(const char *str) 
{
    int i = 0;
    while (str[i] != '\0') 
    {
        i++;
    }
    return i;
}

void x(const char *str, int start, int end) 
{
    if (end - start + 1 < 2)
    {
        return;
    }
    if (str[start] == str[end]) 
    {
        int i = start;
        while(i <= end) 
        {
            printf("%c", str[i]);
            i++;
        }
        printf("\n");
    }
    if (end > start) 
    {
        x(str, start + 1, end);
        x(str, start, end - 1);
    }
}

void print(const char *str) 
{
    int length = str_len(str);
    x(str, 0, length - 1);
}

int main() 
{
    char str[100];
    printf("Enter an input:\n");
    scanf("%s", str); 
    print(str);
    return 0;
}