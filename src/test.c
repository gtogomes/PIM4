#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

void test_criptografia() {
    char original[] = "admin";
    char esperado[] = "nqzva";

    criptografar(original);
    assert(strcmp(original, esperado) == 0);
    printf("Teste de criptografia passou.\n");
}

void salvar_resultados() {
    FILE *file = fopen("test_results.csv", "w");
    if (file == NULL) {
        printf("Erro ao salvar resultados dos testes.\n");
        return;
    }
    fprintf(file, "Teste,Resultado\n");
    fprintf(file, "Criptografia,Passou\n");
    fclose(file);
}

int main() {
    test_criptografia();
    salvar_resultados();
    return 0;
}
