#include <stdio.h>    // Para printf e perror
#include <fcntl.h>    // Para open e suas flags
#include <unistd.h>   // Para read e close

int main() {
    // 1. Abra um arquivo de texto chamado 'lab2_ex2.txt' em modo leitura
    int file = open("/uploads/lab2_ex2.txt", O_RDONLY);
    
    // Verifique se o arquivo foi aberto com sucesso
    if (file == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;  // Encerra o programa com um código de erro
    }

    // 2. Variável para contar o número de linhas
    int lineCount = 0;
    char buffer[128];  // Buffer de 128 bytes

    // 3. Leia o arquivo em partes e conte as quebras de linha
    ssize_t bytesRead;
    while ((bytesRead = read(file, buffer, sizeof(buffer))) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            if (buffer[i] == '\n') {
                lineCount++;
            }
        }
    }

    // Verifique se houve um erro na leitura
    if (bytesRead == -1) {
        perror("Erro ao ler o arquivo");
        close(file);
        return 1;
    }

    // 4. Exiba o número total de linhas na tela
    printf("Número total de linhas: %d\n", lineCount);

    // 5. Feche o arquivo após a leitura
    close(file);

    return 0;
}
