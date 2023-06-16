#include <stdio.h>

int findLargestNumber(int num) {
    int large = 0;
    int divisor = 1;

    while (divisor <= num) {
        int temp = (num / (divisor * 10)) * divisor + (num % divisor);

        if (temp > large) {
            large = temp;
        }

        divisor *= 10;
    }

    return large;
}

int main() {
    int number;

    printf("Enter a 4-digit number: ");
    scanf("%d", &number);

    int largestNumber = findLargestNumber(number);

    printf("The largest number by deleting a single digit: %d\n", largestNumber);

    return 0;
}
