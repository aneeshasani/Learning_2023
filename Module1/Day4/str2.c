#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[100];
    int num1, num2;
    
    printf("Enter a string: ");
    scanf("%s", str);

    num1 = atoi(str);
    printf("Converted integer: %d\n", num1);

    return 0;
}
