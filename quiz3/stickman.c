#include <stdio.h>

void drawStickman(int position, char armStatus) {
    printf("\n");
    for (int i = 0; i < position+5; i++) {
        printf(" ");
    }
    printf("   o\n");
    if (armStatus == 'd') {
        for (int i = 0; i < position+5; i++) {
            printf(" ");
        }
        printf("   |  \n");
    } else {
        for (int i = 0; i < position+5; i++) {
            printf(" ");
        }
        printf("  /|\\\n");
    }

    for (int i = 0; i < position+5; i++) {
        printf(" ");
    }
    printf("   |  \n");

    for (int i = 0; i < position+5; i++) {
        printf(" ");
    }
    printf("  / \\\n");
}

int moveStickman(int position, char move) {
    switch (move)
    {
    case 'd':
        return ++position;

    case 'a':
        return --position;
    
    case 's':
        return -10;

    default:
        return 0;
        break;
    }
}

int main() {
    int position = 0, newPosition = 0;
    char armStatus = 'd', move;
    printf("Welcome to Stickman Animation!\nUse 'a' to move left, 'd' to move right,\n's' to switch arms, and 'e' to exit.\n");
    while (move != 'e') {
        printf("Enter your move: ");
        scanf("%c", &move);
        while (getchar() != '\n');
        newPosition = moveStickman(position, move);
        if (newPosition != -10) {
            position = newPosition;
        } else {
            if (armStatus == 'd') {
                armStatus = 'f';
            } else armStatus = 'd';
        }
        drawStickman(position, armStatus);
    }
    printf("Exiting Stickman Animation. Goodbye!\n\n");
    return 0;
}