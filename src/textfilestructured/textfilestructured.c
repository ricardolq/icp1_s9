#include <stdio.h>

int main() {
    // File pointer
    FILE *file;

    // Open file for writing
    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    // Write formatted content to the file
    fprintf(file, "Name: %s\nAge: %d\nHeight: %.2f\n", "John Doe", 30, 5.9);

    // Close the file
    fclose(file);

    // Variables to read the content
    char name[50];
    int age;
    float height;

    // Open file for reading
    file = fopen("output.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    // Read formatted content from the file
    fscanf(file, "Name: %s\nAge: %d\nHeight: %f\n", name, &age, &height);

    // Close the file
    fclose(file);

    // Print the read content
    printf("Read from file:\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f\n", height);

    return 0;
}