#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        printf("%s\n", line);
    }

    fclose(file);
}
