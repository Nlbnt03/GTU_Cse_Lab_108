#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_column 15
#define max_row 20

void readFFloat(char *file_name, double output[][max_column], int *numrows, int *numcols) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) 
    {
        printf("error!");
        return;
    }

    char line[1000];
    *numrows = 0;
    *numcols = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, ",");
        int col = 0;
        while (token != NULL) {
            if (strcmp(token, "NaN") == 0) {
                output[*numrows][col] = 0.0;
            } else {
                output[*numrows][col] = atof(token);
            }
            col++;
            token = strtok(NULL, ",");
        }

        if (*numcols == 0) {
            *numcols = col; 
        }

        (*numrows)++;
    }
    fclose(file);
}

int main() {
    double output[max_row][max_column]; 
    int numrows, numcols;

    readFFloat("deneme.txt", output, &numrows, &numcols);

    for (int i = 0; i < numrows; i++) {
        for (int j = 0; j < numcols; j++) {
            printf("%.2lf ", output[i][j]);
        }
        printf("\n");
    }

    return 0;
}