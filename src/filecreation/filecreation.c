#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char *filename = "example.txt";

    // Open file for writing
    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s for writing\n", filename);
        return 1;
    }

    // Write some text to the file
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is an example of file creation in C.\n");

    // Close the file
    fclose(file);

    printf("File %s created and written successfully.\n", filename);

    return 0;
}