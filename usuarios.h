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


