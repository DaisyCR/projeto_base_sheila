#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createCSV();
void readCSV();
void addToCSV();
void updateCSV();

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

    createCSV(filename, header);
    readCSV(filename);
}

void userReadCsv() {
    char filename[100];

    printf("Digite o nome da planilha: ");
    if( fgets(filename, sizeof(filename), stdin) != NULL) {
        filename[strcspn(filename, "\n")] = '\0';
    }

    readCSV(filename);
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
    addToCSV(filename, data);
    // TODO add loop for multiple questions
    readCSV(filename);

}

int main() {
    //todo finish the delete and update functions
    //todo refactor the code after it
    //update and remove are the same thing, just update it to a empty cell
   // readCsv("teste.csv");
    char* file = "teste.csv";
    createCSV(file, "a, b, c, d");
    addToCSV(file, "1, 2, 3, 4");
    updateCSV(file,0,2,"3");
    readCSV(file);
    return 0;
}
