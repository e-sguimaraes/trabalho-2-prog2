#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tListaBusca.h"

struct tListaBusca {
    tPaciente ** pacientes;
    int qtdPacientes;
    char nomeProcurado[100];
};

tListaBusca * criaListaBusca(tPaciente ** pacientes, int qtdPacientes, char * nomeProcurado) {

    tListaBusca * lista = (tListaBusca *) malloc(sizeof(tListaBusca));

    lista -> pacientes = pacientes;
    lista -> qtdPacientes = qtdPacientes;
    strcpy(lista -> nomeProcurado, nomeProcurado);

return lista;
}

void imprimeNaTelaListaBusca(void *dado) {

    tListaBusca * lista = (tListaBusca *)dado;
    int pacienteEncontrado = 0;

    for(int i = 0; i < lista -> qtdPacientes; i++) {
        if(!strcmp(lista -> nomeProcurado, ObtemNomePaciente(lista -> pacientes[i]))) {
            pacienteEncontrado++;
            printf("%d - ", pacienteEncontrado);
            imprimeNaTelaPaciente(lista -> pacientes[i]);
        }
    }

}

void imprimeEmArquivoListaBusca(void *dado, char *path) {

    tListaBusca * lista = (tListaBusca *)dado;

    FILE * arqListaBusca = NULL;

    char diretorioDaListaBusca[100];
    sprintf(diretorioDaListaBusca, "%s/%s", path, NOME_ARQUIVO_LISTA_BUSCA);
    arqListaBusca = fopen(diretorioDaListaBusca, "a");

    int pacienteEncontrado = 0;

    for(int i = 0; i < lista -> qtdPacientes; i++) {
        if(!strcmp(lista -> nomeProcurado, ObtemNomePaciente(lista -> pacientes[i]))) {
            pacienteEncontrado++;
            fprintf(arqListaBusca, "%d - ", pacienteEncontrado);
            imprimeEmArquivoPaciente(lista -> pacientes[i], arqListaBusca);
        }
    }

    fclose(arqListaBusca);

}

void desalocaListaBusca(void * dado) {
    free((tListaBusca *)dado);
}