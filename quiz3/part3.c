#include <stdio.h>

int switch_arms = 1;
int stickman_position = 0;

void drawStickman(int position, char armStatus) {
    if (position != -1) {
        stickman_position = position;
    }
    if (armStatus == 's') {
        switch_arms = !switch_arms;
    }

    for (int line = 0; line <= 4; line++) {
        for (int p = 0; p < stickman_position; p++) {
            printf(" ");
        }

        if (line == 0) {
            printf("   O\n");
        } else if (line == 1) {
            printf("  ");
            if (switch_arms == 1) {
                printf("/");
            } else {
                printf(" ");
            }
            printf("|");
            if (switch_arms == 1) {
                printf("\\\n");
            } else {
                printf("\n");
            }
        } else if (line == 2) {
            printf("   |\n");
        } else if (line == 3) {
            printf("  ");
            if (switch_arms == 1) {
                printf("/");
            } else {
                printf(" ");
            }
            printf(" \\\n");
        }
    }
}

int main() {
    drawStickman(stickman_position, ' '); // Draw stickman initially

    char input;
    do {
        printf("enter your move :");
        scanf(" %c", &input);
        switch (input) {
            case 'a':
                drawStickman(stickman_position - 1, ' ');
                break;
            case 'd':
                drawStickman(stickman_position + 1, ' ');
                break;
            case 's':
                drawStickman(stickman_position, 's');
                break;
            default:
                break;
        }
    } while (input != 'e'); 

    return 0;
}
