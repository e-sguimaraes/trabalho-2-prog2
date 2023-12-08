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
        if(strcmp(lista -> nomeProcurado, ObtemNomePaciente(lista -> pacientes[i]))) {
            printf("%d - ", pacienteEncontrado);
            imprimeNaTelaPaciente(lista -> pacientes[i]);
            pacienteEncontrado++;
        }
    }

}

void imprimeEmArquivoListaBusca(void *dado, char *path) {

    tListaBusca * lista = (tListaBusca *)dado;

    FILE * arqListaBusca = NULL;

    char diretorioDoRelatorio[50];
    sprintf(diretorioDoRelatorio, "%s/%s", path, NOME_ARQUIVO_LISTA_BUSCA);
    arqListaBusca = fopen(diretorioDoRelatorio, "a");

    int pacienteEncontrado = 0;

    for(int i = 0; i < lista -> qtdPacientes; i++) {
        if(strcmp(lista -> nomeProcurado, ObtemNomePaciente(lista -> pacientes[i]))) {
            fprintf(arqListaBusca, "%d - ", pacienteEncontrado);
            imprimeEmArquivoPaciente(lista -> pacientes[i], path);
            pacienteEncontrado++;
        }
    }

}

void desalocaListaBusca(void * dado) {
    free((tListaBusca *)dado);
}