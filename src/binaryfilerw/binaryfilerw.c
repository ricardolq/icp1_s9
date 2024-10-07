#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void writeToFile(const char *filename, Employee *emp) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    fwrite(emp, sizeof(Employee), 1, file);
    fclose(file);
}

void readFromFile(const char *filename, Employee *emp) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    fread(emp, sizeof(Employee), 1, file);
    fclose(file);
}

int main() {
    const char *filename = "employee.dat";
    Employee emp1 = {1, "John Doe", 50000.0};
    Employee emp2;

    writeToFile(filename, &emp1);
    readFromFile(filename, &emp2);

    printf("ID: %d\n", emp2.id);
    printf("Name: %s\n", emp2.name);
    printf("Salary: %.2f\n", emp2.salary);

    return 0;
}