#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define max_size 100

int cx, cy;
int fx, fy;
int total_cost;

typedef struct block
{
    int cost;
    char type;
}block;

int generateRandom(int limit)
{
    return rand() % (limit + 1);
}

void initBoard(block board[10][10])
{
    int i;
    for ( i = 0; i < 10; i++)
    {
        int j;
        for (j = 0; j < 10; j++)
        {
            block block;
            block.cost = generateRandom(10);
            block.type = '.';
            board[i][j] = block;
        }
    }

    for (i = 0; i < 10; i++)
    {
        int j;
        for (j = 0; j < 10; j++)
        {
            printf("%c ",board[i][j].type);
        }
        printf("\n");
    }

    printf("\n");

    cx = generateRandom(9);
    cy = generateRandom(9);

    fx = generateRandom(9);
    fy = generateRandom(9);

    printf("ck (%d,%d)\n",cx,cy);
    printf("fk (%d,%d)\n",fx,fy);

    board[cx][cy].cost = 0;
    board[cx][cy].type = 'C';

    board[fx][fy].cost = 0;
    board[fx][fy].type = 'F';
}

void printBoard(block board[10][10])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        int j;
        for (j = 0; j < 10; j++)
        {
            printf("%c ",board[i][j].type);
        }
        printf("\n");
    }
}

void printMoves(char moves[])
{
    char choice;
    char choice2;

    int i = 0;
    while (choice != 'r')
    {
        printf("Enter next move (w, a, s, d) or 'r' run : ");
        scanf(" %c", &choice);
        if (choice == 'w' || choice == 'a' || choice == 's' || choice == 'd')
        {
            printf("Enter a choice 2 : ");
            scanf(" %c", &choice2);
            moves[i] = choice2;
            i++;
        }
        else if(choice == 'r')
        {
            moves[i+1] = "\0";
            break;
        }
        else
        {
            printf("Invalid Choice!\n");
        }
    }
    
}


void gameplay(block board[10][10], char moves[])
{
    int current_x, current_y;

    current_x = cx;
    current_y = cy;

    int i;
    printf("%d\n",strlen(moves));
    for (i = 0; i < strlen(moves); i++)
    {
        if (moves[i] == '^')
        {
            current_x -= 1;
            board[current_x][current_y].type = '-';
            total_cost += board[current_x][current_y].cost;
        }
        else if (moves[i] == '>')
        {
            current_y += 1;
            board[current_x][current_y].type = '-';
            total_cost += board[current_x][current_y].cost;
        }
        else if (moves[i] == '<')
        {
            current_y -= 1;
            board[current_x][current_y].type = '-';
            total_cost += board[current_x][current_y].cost;
        }
        else if (moves[i] == 'v')
        {
            current_x += 1;
            board[current_x][current_y].type = '-';
            total_cost += board[current_x][current_y].cost;
        }
        else
        {
            printf("Error!\n");
            break;
        }
    }

    if (current_x == fx && current_y == fy)
    {
        board[fx][fy].type = 'F';
        printBoard(board);
        printf("Congratulations! You readched the finish line.\n");
        printf("Total Cost Of Path : %d\n",total_cost);
    }
    else
    {
        printBoard(board);
        printf("Game Over!.\n");
    }
    
}

int main()
{
    block board[10][10];
    char moves[max_size];
    srand(time(NULL));
    initBoard(board);
    printBoard(board);
    printMoves(moves);
    gameplay(board,moves);
}


