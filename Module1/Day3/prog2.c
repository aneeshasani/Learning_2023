#include <stdio.h>

void printBits(unsigned int num) {
    int bitPosition;
    unsigned int mask = 1 << 31;

    for (bitPosition = 0; bitPosition < 32; bitPosition++) {
        if (num & (mask >> bitPosition)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

int main() {
    unsigned int num;

    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Bits: ");
    printBits(num);

    return 0;
}
