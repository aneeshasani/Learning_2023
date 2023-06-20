#include <stdio.h>

int main() {
    int len, i;
    int oddSum = 0, evenSum = 0;
    
    printf("Enter the size of the array: ");
    scanf("%d", &len);
    
    int arr[len];
    
    printf("Enter elements of the array:\n");
    for (i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
        
        if (arr[i] % 2 == 0) {
            evenSum += arr[i];
        } else {
            oddSum += arr[i];
        }
    }
    
    int difference = oddSum - evenSum;
    
    printf("Difference between odd and even elements: %d\n", difference);
    
    return 0;
}
