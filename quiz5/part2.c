#include <stdio.h>

typedef enum Operation {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
} optype;

void get_parameters(double *a, optype *op, double *b) {
    char operatorSymbol;
    
    printf("Enter the expression (e.g., 5 * 2): ");
    scanf("%lf %c %lf", a, &operatorSymbol, b);

    switch (operatorSymbol) {
        case '+':
            *op = ADDITION;
            break;
        case '-':
            *op = SUBTRACTION;
            break;
        case '*':
            *op = MULTIPLICATION;
            break;
        case '/':
            *op = DIVISION;
            break;
        default: 
            break;
    }
}

void print_result(double a, optype op, double b) {
    switch (op) {
        case ADDITION:
            printf("%.2f + %.2f = %.2f\n", a, b, a + b);
            break;
        case SUBTRACTION:
            printf("%.2f - %.2f = %.2f\n", a, b, a - b);
            break;
        case MULTIPLICATION:
            printf("%.2f * %.2f = %.2f\n", a, b, a * b);
            break;
        case DIVISION:
            if (b != 0) {
                printf("%.2f / %.2f = %.2f\n", a, b, a / b);
            } else {
                printf("Error: Division by zero\n");
            }
            break;
        default:
            printf("Error: Invalid operation\n");
            break;
    }
}

int main() {
    double num1, num2;
    optype operation;

    get_parameters(&num1, &operation, &num2);
    print_result(num1, operation, num2);

    return 0;
}