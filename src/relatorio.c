#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"

void relatorios_individualizados() {
    FILE *file = fopen("industrias.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo. Certifique-se de que o arquivo existe.\n");
        return;
    }

    char linha[256];
    printf("\n===== RELATÓRIOS INDIVIDUALIZADOS =====\n");
    printf("Indústria          | Resíduos Tratados (semestre) | Gastos Mensais\n");
    printf("------------------------------------------------------------------\n");

    // Criação do arquivo CSV para exportação
    FILE *csv_file = fopen("relatorios_individualizados.csv", "w");
    if (csv_file == NULL) {
        printf("Erro ao criar o arquivo CSV.\n");
        fclose(file);
        return;
    }
    
    // Escreve o cabeçalho no CSV
    fprintf(csv_file, "Indústria,Resíduos Tratados (semestre),Gastos Mensais\n");

    while (fgets(linha, sizeof(linha), file)) {
        char nome[100], cnpj[20], endereco[150], regiao[50];
        int residuos;
        float custo;

        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];%d;%f", nome, cnpj, endereco, regiao, &residuos, &custo);
        printf("%-18s | %-28d | R$ %.2f\n", nome, residuos * 6, custo);

        // Escreve os dados no arquivo CSV
        fprintf(csv_file, "%s,%d,R$ %.2f\n", nome, residuos * 6, custo);
    }

    fclose(file);  // Fecha o arquivo de dados
    fclose(csv_file);  // Fecha o arquivo CSV

    printf("\n[ Exportar para TXT ]  [ Exportar para CSV ]\n");
    printf("\nMensagem: Relatório exportado com sucesso!\n");
}

void relatorios_globais() {
    FILE *file = fopen("industrias.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo. Certifique-se de que o arquivo existe.\n");
        return;
    }

    int total_residuos[5] = {0}; // Para 5 regiões (Norte, Sul, Leste, Oeste, Centro-Oeste)
    float aporte_total = 0;
    char menor_industria[100] = "";
    int menor_residuos = __INT_MAX__;

    char linha[256];
    while (fgets(linha, sizeof(linha), file)) {
        char nome[100], cnpj[20], endereco[150], regiao[50];
        int residuos;
        float custo;

        sscanf(linha, "%[^;];%[^;];%[^;];%[^;];%d;%f", nome, cnpj, endereco, regiao, &residuos, &custo);

        aporte_total += custo * 6; // Total financeiro semestral
        if (residuos < menor_residuos) {
            menor_residuos = residuos;
            strcpy(menor_industria, nome);
        }

        if (strcmp(regiao, "Norte") == 0) total_residuos[0] += residuos;
        else if (strcmp(regiao, "Sul") == 0) total_residuos[1] += residuos;
        else if (strcmp(regiao, "Leste") == 0) total_residuos[2] += residuos;
        else if (strcmp(regiao, "Oeste") == 0) total_residuos[3] += residuos;
        else if (strcmp(regiao, "Centro-Oeste") == 0) total_residuos[4] += residuos;
    }

    fclose(file);

    // Encontrar a região com maior volume de resíduos
    int max_residuos = 0, max_indice = 0;
    for (int i = 0; i < 5; i++) {
        if (total_residuos[i] > max_residuos) {
            max_residuos = total_residuos[i];
            max_indice = i;
        }
    }

    const char *regioes[] = {"Norte", "Sul", "Leste", "Oeste", "Centro-Oeste"};
    printf("\n===== RELATÓRIOS GLOBAIS =====\n");
    printf("Região com maior volume de resíduos: %s\n", regioes[max_indice]);
    printf("Indústria com menor produção: %s (%d toneladas)\n", menor_industria, menor_residuos);
    printf("Aporte financeiro total no semestre: R$ %.2f\n", aporte_total);

    // Criação do arquivo CSV para exportação
    FILE *csv_file = fopen("relatorios_globais.csv", "w");
    if (csv_file == NULL) {
        printf("Erro ao criar o arquivo CSV.\n");
        return;
    }

    // Escreve o cabeçalho no CSV
    fprintf(csv_file, "Região com maior volume de resíduos,Indústria com menor produção,Aporte financeiro total no semestre\n");
    fprintf(csv_file, "%s,%s (%d toneladas),R$ %.2f\n", regioes[max_indice], menor_industria, menor_residuos, aporte_total);

    fclose(csv_file);  // Fecha o arquivo CSV

    printf("\n[ Exportar para TXT ]  [ Exportar para CSV ]\n");
    printf("\nMensagem: Relatório exportado com sucesso!\n");
}

void salvar_relatorio(const char *arquivo, const char *conteudo) {
    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao salvar o relatório.\n");
        return;
    }

    fprintf(file, "%s", conteudo);
    fclose(file);
    printf("Relatório salvo em %s\n", arquivo);
}
