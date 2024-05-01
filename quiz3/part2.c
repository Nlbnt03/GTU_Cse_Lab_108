#include <stdio.h>
void drawStickman(int position, char armStatus)
{
    int line;
    int space;
    int switch_arms = 1;
    switch (armStatus)
    {
    case 's':
        switch_arms = !switch_arms;
        break;
    default:
        break;
    }
    for (line = 0; line <= 4; line++)
    {
        if (line == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                printf(" ");
            }
            printf("O\n");
        }
        else if(line == 1)
        {
            if (switch_arms == 1)
            {
                for (int i = 0; i <= 4 ; i++)
                {
                    if (i == 2)
                    {
                        printf("/");
                    }
                    else if (i == 3)
                    {
                        printf("l");
                    }
                    else if(i == 4)
                    {
                        printf("\\");
                        printf("\n");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
            else
            {
                for (int i = 0; i < 3; i++)
                {
                    printf(" ");
                }
                printf("l\n");
            }
        }
        else if(line == 2)
        {
             for (int i = 0; i < 3; i++)
                {
                    printf(" ");
                }
                printf("l\n");
        }
        else if(line == 3)
        {
            for (int i = 0; i < 5; i++)
                {
                    if(i == 2)
                    {
                        printf("/");
                    }
                    else if (i == 4)
                    {
                        printf("\\");
                        printf("\n");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
        }
    }
}
int moveStickman (int position, char move)
{
    if (move == 'a')
    {
        return (position - 1);
    }
    else if(move == 'd')
    {
        return (position + 1);
    }
    else if (move == 's')
    {
        return 3; //change arm status
    }
    else if(move == 'e')
    {
        return 1; //exit the program
    }
    else
    {
        return 2;
    }
}
int main()
{
 int position = 0;
 int new_position = 0;
 char armStatus = 'd';
 char move = 'n';

drawStickman(position,armStatus);
    
}