#include <stdio.h>

void deciToBin(int decimal);
void deciToOcta(int decimal);
void deciToHexa(int decimal);

int main() {
    int decimal;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    printf("Binary representation: ");
    decimalToBin(decimal);
    
    printf("\nOctal representation: ");
    deciToOcta(decimal);
    
    printf("\nHexadecimal representation: ");
    deciToHexa(decimal);
    
    printf("\n");
    
    return 0;
}

void deciToBin(int decimal) {
    if (decimal > 0) {
        deciToBin(decimal / 2);
        printf("%d", decimal % 2);
    }
}

void deciToOcta(int decimal) {
    if (decimal > 0) {
        deciToOcta(decimal / 8);
        printf("%d", decimal % 8);
    }
}

void deciToHexa(int decimal) {
    if (decimal > 0) {
        deciToHexa(decimal / 16);
        int remainder = decimal % 16;
        if (remainder < 10) {
            printf("%d", remainder);
        } else {
            printf("%c", 'A' + remainder - 10);
        }
    }
}
