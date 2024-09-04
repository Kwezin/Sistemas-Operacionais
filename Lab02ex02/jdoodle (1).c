#include <stdio.h>    // Para printf e perror
#include <fcntl.h>    // Para open e suas flags
#include <unistd.h>   // Para read e close

int main() {
    // Abra um arquivo de texto chamado 'lab2_ex2.txt' em modo leitura
    int file = open("/uploads/lab2_ex2.txt", O_RDONLY);
    
    // Verifique se o arquivo foi aberto com sucesso
    if (file == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;  // Encerra o programa com um código de erro
    }

    // Variável para contar o número de linhas
    int lineCount = 0;
    char buffer[128];  // Buffer de 128 bytes
    int ultimaline = 1;  // Variável para verificar se a última linha termina com '\n'

    // Leia o arquivo em partes e conte as quebras de linha
    ssize_t bytesRead;
    while ((bytesRead = read(file, buffer, sizeof(buffer))) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            if (buffer[i] == '\n') {
                lineCount++;
                ultimaline = 1;  // Marque que encontramos um '\n'
            } else {
                ultimaline = 0;  // Se não for '\n', marque que não encontramos
            }
        }
    }

    // Verifique se houve um erro na leitura
    if (bytesRead == -1) {
        perror("Erro ao ler o arquivo");
        close(file);
        return 1;
    }

    // Se o arquivo não termina com '\n', considere a última linha
    if (!ultimaline) {
        lineCount++;
    }

    // Exiba o número total de linhas na tela
    printf("Número total de linhas: %d\n", lineCount);

    //Feche o arquivo após a leitura
    close(file);

    return 0;
}
