#include <stdio.h>

int main() {
    FILE *file;
    char filename[] = "example.txt";
    
    // Writing to a file
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file for writing.\n");
        return 1; // Exit with an error code
    }
    
    fprintf(file, "Hello, World!");
    fclose(file);

    // Reading from a file
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file for reading.\n");
        return 1; // Exit with an error code
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}
