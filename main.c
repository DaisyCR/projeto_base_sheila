#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ignorem a bagunça que ta isso aqui pelo amor de deus, eu to sobrecarregada de cafeina e com coisa do estagio pra fazer pra amanhã *dies*

void createCsv(const char *filename, const char *header) {
    FILE *file = fopen(filename, "w");

    if(file == NULL) {
        perror("Erro ao gerar o arquivo");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s\n", header);
    fclose(file);
    printf("%s foi criado\n", filename);
}

void readCsv(const char *filename) {
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

void addToCsv(const char *filename, const char *data) {
    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s\n", data);
    fclose(file);
    printf("Data added to CSV file successfully: %s\n", filename);
}


void userCreateCsv() {
    //TODO think of a better name
    char filename[100];
    char header[1024];

    printf("Digite o nome da planilha: ");
    if( fgets(filename, sizeof(filename), stdin) != NULL) {
        filename[strcspn(filename, "\n")] = '\0';
    }
    //TODO error handling if the user doesnt specify the format
    printf("Digite o cabeçalho da planilha separado por virgula EX: ID, NOME, IDADE: ");
    if( fgets(header, sizeof(header), stdin) != NULL) {
        header[strcspn(header, "\n")] = '\0';
    }

    createCsv(filename, header);
    readCsv(filename);
}

void userReadCsv() {
    char filename[100];

    printf("Digite o nome da planilha: ");
    if( fgets(filename, sizeof(filename), stdin) != NULL) {
        filename[strcspn(filename, "\n")] = '\0';
    }

    readCsv(filename);
}

void userAddtoCsv() {
    char filename[100];
    char data[1024];

    printf("Digite o nome da planilha: ");
    if( fgets(filename, sizeof(filename), stdin) != NULL) {
        filename[strcspn(filename, "\n")] = '\0';
    }

    printf("Digite os dados separados por virgula EX: ID, NOME, IDADE: ");
    if( fgets(data, sizeof(data), stdin) != NULL) {
        data[strcspn(data, "\n")] = '\0';
    }
    addToCsv(filename, data);
    // TODO add loop for multiple questions
    readCsv(filename);

}

int main() {
    //todo finish the delete and update functions
    //todo refactor the code after it
    //update and remove are the same thing, just update it to a empty cell
    readCsv("teste.csv");
    return 0;
}
