#include <stdio.h>    // Inclui as definições para printf e perror
#include <fcntl.h>    // Inclui as definições para open e suas flags
#include <unistd.h>   // Inclui as definições para read, write e close

int main() {
    // 1. Abra um arquivo de texto chamado 'lab2_ex1.txt' em modo leitura
    int file = open("lab2_ex1.txt", O_RDONLY);

    // 2. Verifique se o arquivo foi aberto com sucesso
    if (file == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;  // Encerra o programa com um código de erro
    }

    // 3. Leia o conteúdo do arquivo para um buffer
    char buffer[128];  // Buffer de 128 bytes
    ssize_t bytesRead = read(file, buffer, sizeof(buffer) - 1);

    // Verifique se a leitura foi bem-sucedida
    if (bytesRead == -1) {
        perror("Erro ao ler o arquivo");
        close(file);  // Feche o arquivo antes de sair
        return 1;
    }

    // 4. Certifique-se de adicionar um caractere nulo (\0) ao final do buffer após a leitura
    buffer[bytesRead] = '\0';

    // Exiba o conteúdo lido na tela
    printf("Conteúdo do arquivo:\n%s\n", buffer);

    // 5. Feche o arquivo após a leitura
    close(file);

    return 0;
}