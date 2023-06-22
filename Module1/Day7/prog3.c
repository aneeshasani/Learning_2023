#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 256

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
} LogEntry;

LogEntry logEntries[MAX_ENTRIES];
int numEntries = 0;

void readDataFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);  // Skip the header line

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL && numEntries < MAX_ENTRIES) {
        LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,\n]", &entry.entryNo, entry.sensorNo, &entry.temperature, &entry.humidity,
               &entry.light, entry.timestamp);
        logEntries[numEntries++] = entry;
    }

    fclose(file);
}

void displayData() {
    printf("EntryNo  SensorNo  Temperature  Humidity  Light  Timestamp\n");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        LogEntry entry = logEntries[i];
        printf("%-8d %-9s %-12.1f %-8d %-6d %-8s\n", entry.entryNo, entry.sensorNo, entry.temperature, entry.humidity,
               entry.light, entry.timestamp);
    }
}

int main() {
    readDataFromFile("data.csv");
    displayData();

    return 0;
}
