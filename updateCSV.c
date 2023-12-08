#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void updateCSV(const char *file_path, int row_index, int col_index, const char *new_value) {
    if (row_index == 0) {
        printf("Warning: Updating header values may affect the interpretation of the CSV file.\n");
        return;
    }

    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Create a temporary file to store the modified content
    FILE *temp_file = fopen("temp.csv", "w");
    if (temp_file == NULL) {
        perror("Error creating temporary file");
        fclose(file);
        return;
    }

    char buffer[1024];
    int current_row = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (current_row == row_index) {
            // Modify the specified cell in the current row
            char *token = strtok(buffer, ",");
            for (int col = 0; col < col_index; col++) {
                fprintf(temp_file, "%s,", token);
                token = strtok(NULL, ",");
            }
            fprintf(temp_file, "%s", new_value);
            token = strtok(NULL, ",");
            while (token != NULL) {
                fprintf(temp_file, ",%s", token);
                token = strtok(NULL, ",");
            }
        } else {
            // Copy the unchanged row to the temporary file
            fprintf(temp_file, "%s", buffer);
        }

        current_row++;
    }

    fclose(file);
    fclose(temp_file);

    // Replace the original file with the temporary file
    remove(file_path);
    rename("temp.csv", file_path);

    printf("Value at row %d and column %d updated successfully.\n", row_index, col_index);
}