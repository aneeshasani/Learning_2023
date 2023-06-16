#include <stdio.h>

void printNums(int n);
void printSpaces(int n);
void printPattern(int n);

int main() {
    int n;
    printf("Value of n: ");
    scanf("%d", &n);
    printPattern(n);
    return 0;
}

void printNums(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d", i);
    }
}

void printNumbersReverse(int n){
	int i;
	for (i = n; i >= 1; i--) {
        printf("%d", i);
    }
}

void printSpaces(int n) {
    int i;

    for (i = 1; i <= n; i++) {
        printf(" ");
    }
}

void printPattern(int n) {
    int i;

    for (i = n; i >= 1; i--) {
        printNums(i);
        printSpaces(2 * (n - i));
        printNumbersReverse(i);
        printf("\n");
    }
}