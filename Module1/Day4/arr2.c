#include <stdio.h>

int main() {
    int len, i;
    
    printf("Enter the len of the array: ");
    scanf("%d", &len);
    
    int arr[len];
    
    printf("Enter elements of the array:\n");
    for (i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    
    int mini = arr[0];  // Initialize min with the first element
    int maxi= arr[0];  // Initialize max with the first element
    
    // Traverse the array to find the minimum and maximum values
    for (i = 1; i < len; i++) {
        if (arr[i] < mini) {
            mini = arr[i];
        }
        
        if (arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    
    printf("Minimum value: %d\n", mini);
    printf("Maximum value: %d\n", maxi);
    
    return 0;
}
