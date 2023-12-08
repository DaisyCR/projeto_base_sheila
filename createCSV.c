#include <stdio.h>
#include <stdlib.h>

void createCSV(const char *filename, const char *header) {
    FILE *file = fopen(filename, "w");

    if(file == NULL) {
        perror("Erro ao gerar o arquivo");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s\n", header);
    fclose(file);
    printf("%s foi criado\n", filename);
}
