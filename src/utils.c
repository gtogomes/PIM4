#include <string.h>
#include "utils.h"

// Implementação de uma criptografia simples (ROT13)
void criptografar(char *dados) {
    for (int i = 0; dados[i] != '\0'; i++) {
        if ((dados[i] >= 'A' && dados[i] <= 'Z') || (dados[i] >= 'a' && dados[i] <= 'z')) {
            if ((dados[i] >= 'a' && dados[i] <= 'z' && dados[i] + 13 > 'z') ||
                (dados[i] >= 'A' && dados[i] <= 'Z' && dados[i] + 13 > 'Z')) {
                dados[i] -= 13;
            } else {
                dados[i] += 13;
            }
        }
    }
}
