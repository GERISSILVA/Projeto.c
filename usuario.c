#ifndef USUARIOS_H
#define USUARIOS_H

#include <stdbool.h>

#define MAX_USUARIOS 100
#define TAM_MAX_EMAIL 80

typedef struct {
    char nome[40];
    char senha[40];
    char email[TAM_MAX_EMAIL];
} Usuario;

void CadastrarUsuario(Usuario usuarios[], int *numUsuarios);
bool verificar_login(Usuario usuarios[], int numUsuarios, char login[], char senha[]);
bool verifica_email(Usuario usuarios[], int numUsuarios, char email[]);

#endif


#include <stdio.h>
#include <string.h>
#include "usuarios.h"

void CadastrarUsuario(Usuario usuarios[], int *numUsuarios) {
    if (*numUsuarios >= MAX_USUARIOS) {
        printf("Limite de usuários atingido!\n");
        return;
    }

    printf("Digite o nome de usuário: ");
    scanf("%39s", usuarios[*numUsuarios].nome);

    printf("Digite o e-mail: ");
    char email[80];
    scanf("%79s", email);

    if (verifica_email(usuarios, *numUsuarios, email)) {
        strcpy(usuarios[*numUsuarios].email, email);
    } else {
        printf("E-mail inválido ou já cadastrado.\n");
        return;
    }

    printf("Digite a senha: ");
    scanf("%39s", usuarios[*numUsuarios].senha);

    (*numUsuarios)++;
    printf("Usuário cadastrado com sucesso!\n");
}

bool verificar_login(Usuario usuarios[], int numUsuarios, char login[], char senha[]) {
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].nome, login) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return true;
        }
    }
    return false;
}

bool verifica_email(Usuario usuarios[], int numUsuarios, char email[]) {
    if (strchr(email, '@') == NULL || strlen(email) >= TAM_MAX_EMAIL) {
        return false;
    }
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {
            return false;
        }
    }
    return true;
}
