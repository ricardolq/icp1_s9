#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a temporary file
    FILE *tempFile = tmpfile();

    if (tempFile == NULL) {
        perror("Unable to create temporary file");
        return EXIT_FAILURE;
    }

    // Write some data to the temporary file
    fprintf(tempFile, "This is a temporary file.\n");
    fprintf(tempFile, "It will be automatically deleted.\n");

    // Rewind the file pointer to the beginning
    rewind(tempFile);

    // Read and display the data from the temporary file
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), tempFile) != NULL) {
        printf("%s", buffer);
    }

    // Close the temporary file
    fclose(tempFile);  // Temp file is automatically deleted here

    return EXIT_SUCCESS;
}