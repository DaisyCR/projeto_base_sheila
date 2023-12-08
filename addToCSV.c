#include <stdio.h>
#include <stdlib.h>

void addToCSV(const char *filename, const char *value) {
    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s\n", value);
    fclose(file);

    printf("Dados foram adicionados ao arquivo %s corretamente.\n", filename);
}
