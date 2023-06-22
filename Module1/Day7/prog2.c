#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

void copyFile(FILE *sourceFile, FILE *destinationFile, int option) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        if (option == 1) { // Convert to upper case
            for (size_t i = 0; i < bytesRead; i++) {
                buffer[i] = toupper(buffer[i]);
            }
        } else if (option == 2) { // Convert to lower case
            for (size_t i = 0; i < bytesRead; i++) {
                buffer[i] = tolower(buffer[i]);
            }
        } else if (option == 3) { // Convert to sentence case
            int capitalize = 1;
            for (size_t i = 0; i < bytesRead; i++) {
                if (capitalize && isalpha(buffer[i])) {
                    buffer[i] = toupper(buffer[i]);
                    capitalize = 0;
                } else if (buffer[i] == '.' || buffer[i] == '?' || buffer[i] == '!') {
                    capitalize = 1;
                } else {
                    buffer[i] = tolower(buffer[i]);
                }
            }
        }

        fwrite(buffer, 1, bytesRead, destinationFile);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments. Usage: ./cp [option] <source file> <destination file>\n");
        return 1;
    }

    int option = 0; // 0: Normal copy, 1: Upper case, 2: Lower case, 3: Sentence case
    if (argc == 4) {
        if (argv[1][0] == '-' && argv[1][1] != '\0' && argv[1][2] == '\0') {
            switch (argv[1][1]) {
                case 'u':
                    option = 1;
                    break;
                case 'l':
                    option = 2;
                    break;
                case 's':
                    option = 3;
                    break;
                default:
                    printf("Invalid option.\n");
                    return 1;
            }
        } else {
            printf("Invalid option.\n");
            return 1;
        }
    }

    FILE *sourceFile, *destinationFile;

    // Open the source file in read mode
    sourceFile = fopen(argv[argc - 2], "r");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    // Open the destination file in write mode
    destinationFile = fopen(argv[argc - 1], "w");
    if (destinationFile == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    copyFile(sourceFile, destinationFile, option);

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully.\n");

    return 0;
}
