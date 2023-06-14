#include <stdio.h>

int main() {
    float op1, op2, res;
    char opr;

    printf("Enter Operand 1: ");
    scanf("%f", &op1);

    printf("Enter Oprator (+, -, *, /): ");
    scanf(" %c", &opr);

    printf("Enter Operand 2: ");
    scanf("%f", &op2);

    switch (opr) {
        case '+':
            res = op1 + op2;
            printf("Result: %.2f\n", res);
            break;
        case '-':
            res = op1 - op2;
            printf("Result: %.2f\n", res);
            break;
        case '*':
            res = op1 * op2;
            printf("Result: %.2f\n", res);
            break;
        case '/':
            if (op2 != 0) {
                res = op1 / op2;
                printf("Result: %.2f\n", res);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Error: Invalid Oprator.\n");
            break;
    }

    return 0;
}
