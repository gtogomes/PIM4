#include <stdio.h>
#include "cadastro.h"

void cadastro() {
    // Tenta abrir o arquivo para adicionar dados. Se não existir, tenta criá-lo.
    FILE *file = fopen("industrias.txt", "a");  // Modo de append (criação do arquivo se não existir)
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo. Tentando criar...\n");
        file = fopen("industrias.txt", "w");  // Modo de escrita, cria o arquivo se não existir
        if (file == NULL) {
            printf("Não foi possível criar o arquivo.\n");
            return;
        }
    }

    char nome[100], cnpj[20], endereco[150], regiao[50];
    int residuos;
    float custo;

    printf("===== CADASTRO DE INDÚSTRIAS =====\n");
    printf("Nome da indústria: ");
    scanf(" %[^\n]", nome);
    printf("CNPJ: ");
    scanf("%s", cnpj);
    printf("Endereço: ");
    scanf(" %[^\n]", endereco);
    printf("Região: ");
    scanf(" %[^\n]", regiao);
    printf("Resíduos tratados (em toneladas): ");
    scanf("%d", &residuos);
    printf("Custo mensal (R$): ");
    scanf("%f", &custo);

    // Escreve os dados no arquivo
    fprintf(file, "%s;%s;%s;%s;%d;%.2f\n", nome, cnpj, endereco, regiao, residuos, custo);
    fclose(file);  // Fecha o arquivo após escrever os dados
    printf("Cadastro realizado com sucesso!\n");
}
