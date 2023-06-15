
#include <stdio.h>

int main() {
    float num1, num2;
    char operator;

    printf("Enter Number 1: ");
    scanf("%f", &num1);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter Number 2: ");
    scanf("%f", &num2);

    float result;

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("The sum is: %.2f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("The difference is: %.2f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("The product is: %.2f\n", result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("The division result is: %.2f\n", result);
            } else {
                printf("Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid operator.\n");
    }

    return 0;
}

