#include <fcntl.h>    // Para open e suas flags
#include <unistd.h>   // Para read, write e close
#include <stdio.h>    // Para perror e printf

int main() {
    // Abra um arquivo de origem 'lab2_ex3_origem.txt' em modo leitura
    int origemFile = open("/uploads/lab2_ex3_origem.txt", O_RDONLY);
    
    // Verifique se o arquivo de origem foi aberto com sucesso
    if (origemFile == -1) {
        perror("Erro ao abrir o arquivo de origem");
        return 1;  // Encerra o programa com um código de erro
    }

    // Abra ou crie um arquivo de destino 'lab2_ex3_destino.txt' em modo escrita
    int destFile = open("lab2_ex3_destino.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    // Verifique se o arquivo de destino foi aberto com sucesso
    if (destFile == -1) {
        perror("Erro ao abrir o arquivo de destino");
        close(origemFile);  // Fecha o arquivo de origem antes de sair
        return 1;  // Encerra o programa com um código de erro
    }

    // Leia o conteúdo do arquivo de origem e escreva no arquivo de destino
    char buffer[128];  // Buffer de 128 bytes
    ssize_t bytesRead;

    while ((bytesRead = read(origemFile, buffer, sizeof(buffer))) > 0) {
        ssize_t bytesWritten = write(destFile, buffer, bytesRead);
        
        if (bytesWritten == -1) {
            perror("Erro ao escrever no arquivo de destino");
            close(origemFile);
            close(destFile);
            return 1;  // Encerra o programa com um código de erro
        }
    }

    // Verifique se houve um erro na leitura
    if (bytesRead == -1) {
        perror("Erro ao ler o arquivo de origem");
        close(origemFile);
        close(destFile);
        return 1;
    }

    // Feche ambos os arquivos após a operação
    close(origemFile);
    close(destFile);

    printf("Arquivo copiado com sucesso!\n");
    
    return 0;
}
