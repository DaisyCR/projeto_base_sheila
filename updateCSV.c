#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void updateCell(FILE *tmp, char *buffer, int colIndex, const char *newValue) {
    char *token = strtok(buffer, ",");

    for (int col = 0; col < colIndex; col++) {
        fprintf(tmp, "%s,", token);
        token = strtok(NULL, ",");
    }

    fprintf(tmp, "%s", newValue);
    token = strtok(NULL, ",");

    while (token != NULL) {
        fprintf(tmp, ",%s", token);
        token = strtok(NULL, ",");
    }
}

void updateCSV(const char *filename, int rowIndex, int colIndex, const char *newValue) {
    if (rowIndex == 0) {
        printf("Aviso! Alterar o valor do cabeçalho pode afetar a intepretação do arquivo.\n");
        return;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *tmp = fopen("tmp.csv", "w");
    if (tmp == NULL) {
        perror("Error ao criar o arquivo temporario");
        fclose(file);
        return;
    }

    char buffer[1024];
    int currentRow = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (currentRow == rowIndex) {
            updateCell(tmp, buffer, colIndex, newValue);
        } else {
            fprintf(tmp, "%s", buffer);
        }
        currentRow++;
    }

    fclose(file);
    fclose(tmp);

    remove(filename);
    rename("tmp.csv", filename);
    printf("Valor na linha %d e coluna %d atualizado com sucesso.\n", rowIndex, colIndex);
}
