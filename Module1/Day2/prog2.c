#include <stdio.h>

void swap(void *a, void *b, size_t size) {
    char temp[size];
    char *ptrA = (char *)a;
    char *ptrB = (char *)b;
    
    for (size_t i = 0; i < size; i++) {
        temp[i] = ptrA[i];
        ptrA[i] = ptrB[i];
        ptrB[i] = temp[i];
    }
}

int main() {
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    
    swap(&x, &y, sizeof(int));
    
    printf("After swap: x = %d, y = %d\n", x, y);
    
    double a = 3.14, b = 2.71;
    printf("Before swap: a = %lf, b = %lf\n", a, b);
    
    swap(&a, &b, sizeof(double));
    
    printf("After swap: a = %lf, b = %lf\n", a, b);
    
    return 0;
}
