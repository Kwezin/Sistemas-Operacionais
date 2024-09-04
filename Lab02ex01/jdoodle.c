#include <stdio.h>    // Inclui as definições para printf e perror
#include <fcntl.h>    // Inclui as definições para open e suas flags
#include <unistd.h>   // Inclui as definições para read, write e close

int main() {
    // Abra um arquivo de texto chamado 'lab2_ex1.txt' em modo leitura
    int file = open("/uploads/lab2_ex1.txt", O_RDONLY);

    // Verifique se o arquivo foi aberto com sucesso
    if (file == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;  // Encerra o programa com um código de erro
    }

    // Leia o conteúdo do arquivo para um buffer
    char buffer[128];  // Buffer de 128 bytes
    ssize_t bytesRead = read(file, buffer, sizeof(buffer) - 1);

    // Verifique se a leitura foi bem-sucedida
    if (bytesRead == -1) {
        perror("Erro ao ler o arquivo");
        close(file);  // Feche o arquivo antes de sair
        return 1;
    }

    // Certifique-se de adicionar um caractere nulo (\0) ao final do buffer após a leitura
    buffer[bytesRead] = '\0';

    // Exiba o conteúdo lido na tela
    printf("Conteúdo do arquivo:\n%s\n", buffer);

    // Feche o arquivo após a leitura
    close(file);

    return 0;
}
