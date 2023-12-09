/* Alunos:
 * Daisy Cerqueira Reis
 * Danilo Carneiro Ribeiro
 * Ludmilla Souza Dias de Abreu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createCSV();
void readCSV();
void addToCSV();
void updateCSV();

void userCreateCSV(const char *filename) {
    char header[1024];
    printf("Digite o cabeçalho da planilha separado por virgula EX: ID, NOME, IDADE: ");
    if( fgets(header, sizeof(header), stdin) != NULL) {
        header[strcspn(header, "\n")] = '\0';
    }

    createCSV(filename, header);
}

void userAddtoCSV(const char *filename) {
    int i;
    printf("Quantos dados deseja adicionar?: ");
    scanf("%d", &i);
    getchar();
    while(i > 0) {
        char data[1024];
        printf("Digite os dados separados por virgula EX: ID, NOME, IDADE: ");
        if( fgets(data, sizeof(data), stdin) != NULL) {
            data[strcspn(data, "\n")] = '\0';
        }
        addToCSV(filename, data);
        i--;
    }
    readCSV(filename);

}

void userUpdateCellCSV(const char* filename) {
    readCSV(filename);
    char input[1024];
    int row, col;
    printf("Insira a linha: ");
    scanf("%d", &row);
    printf("Insira a coluna: ");
    scanf("%d", &col);
    getchar();

    printf("Insira o valor: ");
    fgets(input, sizeof(input), stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    updateCSV(filename, row, col, input);
    printf("Dado atualizado com sucesso!\n");
    readCSV(filename);
}

void userDeleteCellCSV(const char* filename) {
    readCSV(filename);
    char data[1024];
    int row, col;
    printf("Insira a linha: ");
    scanf("%d", &row);
    printf("Insira a coluna: ");
    scanf("%d", &col);

    updateCSV(filename, row, col, "\n");
    printf("Dado apagado com sucesso!\n");
    readCSV(filename);
}

int displayMenu(const char *filename) {
    printf("Arquivo: %s\n", filename);
    printf("1 - Criar novo arquivo\n"
           "2 - Ler arquivo\n"
           "3 - Adicionar dados\n"
           "4 - Atualizar dados\n"
           "5 - Apagar dados\n"
           "6 - Sair\n");
    printf("Escolha uma das opções: ");
    int input = 0;
    scanf("%d", &input);
    getchar();
    switch (input) {
        case 1:
            userCreateCSV(filename);
            break;
        case 2:
            readCSV(filename);
            break;
        case 3:
            userAddtoCSV(filename);
            break;
        case 4:
            userUpdateCellCSV(filename);
            break;
        case 5:
            userDeleteCellCSV(filename);
            break;
        case 6:
            return 0;
        default:
            printf("Erro. Insira um valor válido!\n");
            displayMenu(filename);
            break;
    }
    return 1;
}

int main() {
    printf("Iniciando leitor de planilha\n");

    char filename[100];
    printf("Digite o nome da planilha: ");
    if( fgets(filename, sizeof(filename), stdin) != NULL) {
        filename[strcspn(filename, "\n")] = '\0';
    }

    if (strlen(filename) >= 4 && strcmp(filename + strlen(filename) - 4, ".csv") != 0) {
        printf("ERRO. Nome de arquivo precisa incluir .csv\n");
        main();
    }
    while(displayMenu(filename)) {
        continue;
    }
    return 0;
}
