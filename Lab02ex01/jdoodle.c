#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 128

int main() {
    // Abra o arquivo em modo leitura
    int file = open("/uploads/lab2_ex1.txt", O_RDONLY);

    // Verifique se o arquivo foi aberto com sucesso
    if (file == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Buffer para armazenar dados lidos
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    // Leia o arquivo em partes e exiba o conteúdo
    while ((bytesRead = read(file, buffer, sizeof(buffer))) > 0) {
        // Certifique-se de adicionar um caractere nulo (\0) ao final do buffer
        buffer[bytesRead] = '\0';
        // Exiba o conteúdo lido
        printf("%s", buffer);
    }

    // Verifique se houve um erro durante a leitura
    if (bytesRead == -1) {
        perror("Erro ao ler o arquivo");
        close(file);
        return 1;
    }

    // Feche o arquivo
    close(file);

    return 0;
}
