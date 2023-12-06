#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tBiopsia.h"

typedef struct tBiopsia {
    char * nomePaciente[100];
    char * cpf[14];
    tLesao ** lesao;
    int qtdLesoes;
    char * nomeMedico[100];
    char * crm[12];
    char * data[10];
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