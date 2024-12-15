#include <stdio.h>
#include <string.h>
#include "login.h"
#include "utils.h"

void login() {
    char username[50];
    char password[50];
    char stored_username[] = "admin";
    char stored_password[] = "nqzva"; // "admin" criptografado com ROT13

    printf("===== LOGIN =====\n");
    printf("Usuário: ");
    scanf("%s", username);
    printf("Senha: ");
    scanf("%s", password);

    criptografar(password); // Criptografa a senha digitada para comparar

    if (strcmp(username, stored_username) == 0 && strcmp(password, stored_password) == 0) {
        printf("Login bem-sucedido!\n");
    } else {
        printf("Credenciais inválidas.\n");
    }
}
