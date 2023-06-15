#include <stdio.h>

int findLargest(int num1, int num2) {
    int largest;
    
    if (num1 > num2) {
        largest = num1;
    } else {
        largest = num2;
    }

    // Using ternary operator
    // largest = (num1 > num2) ? num1 : num2;

    return largest;
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    int result = findLargest(num1, num2);
    printf("The largest number is: %d\n", result);

    return 0;
}
