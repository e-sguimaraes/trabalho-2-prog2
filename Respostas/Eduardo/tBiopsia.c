#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tBiopsia.h"
#include "limites.h"

struct tBiopsia {
    char * nomePaciente[MAX_NOME];
    char * cpf[TAM_CPF];
    tLesao ** lesao;
    int qtdLesoes;
    char * nomeMedico[MAX_NOME];
    char * crm[TAM_CRM];
    char * data[TAM_DATA];
};


tBiopsia * criaBiopsia(char *nomePaciente, char * cpfPaciente, tLesao ** lesao,
                      int qtdLesoes, char * nomeMedico, char * crm, char * data) {

    tBiopsia * biopsia = (tBiopsia *) malloc(sizeof(tBiopsia));

    strcpy(biopsia -> nomePaciente, nomePaciente);
    strcpy(biopsia -> cpf, cpfPaciente);
    biopsia -> lesao = lesao;
    biopsia -> qtdLesoes = qtdLesoes;
    strcpy(biopsia -> nomeMedico, nomeMedico);
    strcpy(biopsia -> crm, crm);
    strcpy(biopsia -> data, data);

}


void desalocaBiopsia(void *dado) {

    tBiopsia * biopsia = (tBiopsia *)dado;

    desalocaLesao(biopsia -> lesao, biopsia -> qtdLesoes);
    free(biopsia);
    
}


void imprimeNaTelaBiopsia(void *dado) {

    tBiopsia * biopsia = (tBiopsia *)dado;

    printf("PACIENTE: %s\n", biopsia -> nomePaciente);
    printf("CPF: %s\n\n", biopsia -> cpf);
    printf("SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
    imprimeNaTelaLesao(biopsia -> lesao, biopsia -> qtdLesoes);
    printf("%s (%s)\n", biopsia -> nomeMedico, biopsia -> crm);
    printf("%s\n", biopsia -> data);

}


void imprimeEmArquivoBiopsia(void *dado, char *path) {

    FILE * arqBiopsia = NULL;
    tBiopsia * biopsia = (tBiopsia *)dado;

    char diretorioDaBiopsia[50];
    sprintf(diretorioDaBiopsia, "%s/%s", path, NOME_ARQUIVO_BIOPSIA);
    arqBiopsia = fopen(diretorioDaBiopsia, "a");

    printf("IMPRIMINDO %s\n", NOME_ARQUIVO_BIOPSIA);
    fprintf(arqBiopsia, "PACIENTE: %s\n", biopsia -> nomePaciente);
    fprintf(arqBiopsia, "CPF: %s\n\n", biopsia -> cpf);
    fprintf(arqBiopsia, "SOLICITACAO DE BIOPSIA PARA AS LESOES:\n");
    imprimeEmArquivoLesao(biopsia -> lesao, biopsia -> qtdLesoes, path);
    fprintf(arqBiopsia, "%s (%s)\n", biopsia -> nomeMedico, biopsia -> crm);
    fprintf(arqBiopsia, "%s\n", biopsia -> data);

    fclose(arqBiopsia);
}