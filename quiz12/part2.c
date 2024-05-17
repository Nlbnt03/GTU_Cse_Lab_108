#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ft_strstr fonksiyonu
char *ft_strstr(char *str, char *to_find) {
    int i;
    int j;

    i = 0;
    j = 0;
    if (to_find[j] == '\0')
        return (str);
    while (str[i] != '\0') {
        if (str[i] == to_find[j]) {
            i++;
            j++;
        } else if (to_find[j] == '\0') {
            return (&str[i - j]);
        } else {
            i++;
            j = 0;
        }
    }
    return (0);
}

// searchWordInPuzzle fonksiyonu
void searchWordInPuzzle(char **puzzle, int row, int column, char *word) {
    int wordLen = strlen(word);
    int found = 0;

    // Search horizontally (left to right)
    for (int i = 0; i < row; i++) {
        char *result = ft_strstr(puzzle[i], word);
        if (result != NULL) {
            int position = result - puzzle[i];
            found = 1;
            printf("Word found horizontally (left to right) at row %d, column %d\n", i, position);
        }
    }

    // Search horizontally (right to left)
    for (int i = 0; i < row; i++) {
        char reversed[100];
        for (int j = 0; j < column; j++) {
            reversed[j] = puzzle[i][column - j - 1];
        }
        reversed[column] = '\0';
        char *result = ft_strstr(reversed, word);
        if (result != NULL) {
            int position = result - reversed;
            found = 1;
            printf("Word found horizontally (right to left) at row %d, column %d\n", i, column - position - 1);
        }
    }

    // Search vertically (top to bottom)
    for (int j = 0; j < column; j++) {
        for (int i = 0; i <= row - wordLen; i++) {
            int k;
            for (k = 0; k < wordLen; k++) {
                if (puzzle[i + k][j] != word[k]) {
                    break;
                }
            }
            if (k == wordLen) {
                found = 1;
                printf("Word found vertically (top to bottom) at row %d, column %d\n", i, j);
            }
        }
    }

    // Search vertically (bottom to top)
    for (int j = 0; j < column; j++) {
        for (int i = row - 1; i >= wordLen - 1; i--) {
            int k;
            for (k = 0; k < wordLen; k++) {
                if (puzzle[i - k][j] != word[k]) {
                    break;
                }
            }
            if (k == wordLen) {
                found = 1;
                printf("Word found vertically (bottom to top) at row %d, column %d\n", i - wordLen + 1, j);
            }
        }
    }

    if (!found) {
        printf("Word not found in the puzzle.\n");
    }
}

// Diğer fonksiyonlar

void fileManipulate() {
    FILE *fileI;
    FILE *fileO;
    fileI = fopen("input.txt", "r");
    fileO = fopen("output.txt", "w");
    char c;
    if (fileI == NULL) {
        printf("Error!\n");
    } else {
        while ((c = fgetc(fileI)) != EOF) {
            if (c >= 'A' && c <= 'Z') {
                c = c + 32; // Convert uppercase to lowercase
            }
            fputc(c, fileO);
        }
    }
    fclose(fileI);
    fclose(fileO);
}

void createPuzzle(int *row, int *column, char ***puzzle) {
    FILE *fileO;
    fileO = fopen("output.txt", "r");
    if (fileO == NULL) {
        printf("File Error!\n");
        return;
    }

    fscanf(fileO, "%d %d", row, column);
    fgetc(fileO); // Consume the newline character after the numbers

    *puzzle = (char **)malloc(*row * sizeof(char *));
    for (int i = 0; i < *row; i++) {
        (*puzzle)[i] = (char *)malloc((*column + 1) * sizeof(char)); // +1 for the null terminator
    }

    for (int i = 0; i < *row; i++) {
        fgets((*puzzle)[i], *column + 1, fileO);
        fgetc(fileO); // Consume the newline character
    }

    fclose(fileO);
}

void menu(char *arr, int *flag) {
    printf("Welcome to puzzle game\n");
    printf("Enter a string: ");
    scanf("%99s", arr);
    if (strcmp("exit", arr) == 0) {
        *flag = 0;
    }
}

int main() {
    char *arr = (char *)malloc(100 * sizeof(char));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int row, column;
    int flag = 1;

    fileManipulate();

    char **puzzle;
    createPuzzle(&row, &column, &puzzle);
    printf("row: %d, column: %d\n", row, column);

    while (flag) {
        menu(arr, &flag);
        if (flag) {
            searchWordInPuzzle(puzzle, row, column, arr);
        }
    }

    printf("%s\n", arr);

    // Free the allocated memory
    for (int i = 0; i < row; i++) {
        free(puzzle[i]);
    }
    free(puzzle);
    free(arr);

    return 0;
}