#include <stdlib.h>
#include <string.h>
#include "tUsuario.h"

struct tUsuario {
    char nomeUsuario[MAX_NOME];
    char cpf[TAM_CPF];
    char dataNascimento[TAM_DATA];
    char telefone[TAM_TEL];
    char genero[TAM_GEN];
    char crm[TAM_CRM];
    char nomeUser[MAX_USER];
    char senhaUser[MAX_USER];
    int nivelUser;
};


tUsuario * cadastraUsuario(char *nomeUsuario, char * cpfUsuario, char * dataNascimento, char * telefone,
                           char * genero, char * crm, char * nomeUser, char * senhaUser, int nivelUser) {

    tUsuario * usuario = (tUsuario *) malloc(sizeof(tUsuario));

    strcpy(usuario -> nomeUsuario, nomeUsuario);
    strcpy(usuario -> cpf, cpfUsuario);
    strcpy(usuario -> dataNascimento, dataNascimento);
    strcpy(usuario -> telefone, telefone);
    strcpy(usuario -> genero, genero);
    strcpy(usuario -> nomeUser, nomeUser);
    strcpy(usuario -> senhaUser, senhaUser);
    usuario -> nivelUser = nivelUser;

return usuario;
}


char * ObtemNomeUsuario(tUsuario * usuario) {
return usuario -> nomeUser;
}


char * ObtemCPFUsuario(tUsuario * usuario) {
return usuario -> cpf;
}


char * ObtemNascimentoUsuario(tUsuario * usuario) {
return usuario -> dataNascimento;
}


char * ObtemTelefoneUsuario(tUsuario * usuario) {
return usuario -> telefone;
}


char * ObtemGeneroUsuario(tUsuario * usuario) {
return usuario -> genero;
}


char * ObtemCRMUsuario(tUsuario * usuario) {
return usuario -> crm;
}


char * ObtemNomeUser(tUsuario * usuario) {
return usuario -> nomeUser;
}


char * ObtemSenhaUser(tUsuario * usuario) {
return usuario -> senhaUser;
}


int ObtemNivelUser(tUsuario * usuario) {
return usuario -> nivelUser;
}


void desalocaUsuario(tUsuario * usuario) {
    free(usuario);
}
