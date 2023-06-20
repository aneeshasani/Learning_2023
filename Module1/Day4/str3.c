#include <stdio.h>

int main() {
    char timeStr[9]; 
    int hour, minute, second, totalSeconds;
    
    printf("Enter the time (in hh:mm:ss format): ");
    scanf("%8s", timeStr);
    
    hour = (timeStr[0] - '0') * 10 + (timeStr[1] - '0');

    minute = (timeStr[3] - '0') * 10 + (timeStr[4] - '0');

    second = (timeStr[6] - '0') * 10 + (timeStr[7] - '0');

    totalSeconds = hour * 3600 + minute * 60 + second;
    
    printf("Total seconds: %d\n", totalSeconds);
    
    return 0;
}
