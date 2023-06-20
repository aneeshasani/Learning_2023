#include <stdio.h>

int main() {
    int length, i;
    float sum = 0, avg;
    
    printf("Enter the size of the array: ");
    scanf("%d", &length);
    
    int arr[length];
    
    printf("Enter elements of the array:\n");
    for (i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    avg = sum / length;
    
    printf("Sum of the array elements: %.2f\n", sum);
    printf("Average of the array elements: %.2f\n", avg);
    
    return 0;
}
