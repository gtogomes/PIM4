#include <stdio.h>
#include <locale.h>
#include "login.h"
#include "cadastro.h"
#include "relatorio.h"

// Declaração da função menu
void menu();

int main() {
    // Configurar localidade para UTF-8
    setlocale(LC_ALL, ""); 

    printf("Bem-vindo ao Sistema de Gerenciamento de Indústrias\n");
    menu();  // Chama a função menu
    return 0;
}

// Definição da função menu
void menu() {
    int opcao;
    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Login\n");
        printf("2. Cadastro de Indústrias\n");
        printf("3. Relatórios Individualizados\n");
        printf("4. Relatórios Globais\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                login();
                break;
            case 2:
                cadastro();
                break;
            case 3:
                relatorios_individualizados();
                break;
            case 4:
                relatorios_globais();
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);
}
