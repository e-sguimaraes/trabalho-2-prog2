#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tEncaminhamento.h"

#define MAX_NOME 101
#define TAM_CRM 13
#define TAM_DATA 11
#define TAM_CPF 15
#define TAM_TEL 15
#define TAM_GEN 10


struct tEncaminhamento{
    char nomePaciente[MAX_NOME];
    char cpf[TAM_CPF];
    char especialidade[MAX_TAM_ESPECIALIDADE];
    char motivo[MAX_TAM_MOTIVO];
    char nomeMedico[MAX_NOME];
    char crm[TAM_CRM];
    char data[TAM_DATA];
};


tEncaminhamento * criaEncaminhamento(char *nomePaciente, char * cpfPaciente, char * especialidade, 
                                     char * motivo, char * nomeMedico, char * crm, char * data) {


    tEncaminhamento * encaminhamento = (tEncaminhamento *) malloc(sizeof(tEncaminhamento));

    strcpy(encaminhamento -> nomePaciente, nomePaciente);
    strcpy(encaminhamento -> cpf, cpfPaciente);
    strcpy(encaminhamento -> especialidade, especialidade);
    strcpy(encaminhamento -> motivo, motivo);
    strcpy(encaminhamento -> nomeMedico, nomeMedico);
    strcpy(encaminhamento -> crm, crm);
    strcpy(encaminhamento -> data, data);

return encaminhamento;
}


void desalocaEncaminhamento(void *dado) {
    free((tEncaminhamento *)dado);
}


void imprimeNaTelaEncaminhamento(void *dado) {

    tEncaminhamento * encaminhamento = (tEncaminhamento *)dado;

    printf("PACIENTE: %s\n", encaminhamento -> nomePaciente);
    printf("CPF: %s\n\n", encaminhamento -> cpf);
    printf("ESPECIALIDADE ENCAMINHADA: %s\n", encaminhamento -> especialidade);
    printf("MOTIVO: %s\n\n", encaminhamento -> motivo);
    printf("%s (%s)\n", encaminhamento -> nomeMedico, encaminhamento -> crm);
    printf("%s\n", encaminhamento -> data);

}


void imprimeEmArquivoEncaminhamento(void *dado, char *path) {

    FILE * arqEncaminhamento = NULL;
    tEncaminhamento * encaminhamento = (tEncaminhamento *)dado;

    char diretorioDoEncaminhamento[100];
    sprintf(diretorioDoEncaminhamento, "%s/%s", path, NOME_ARQUIVO_ENCAMINHAMENTO);
    arqEncaminhamento = fopen(diretorioDoEncaminhamento, "a");

    printf("IMPRIMINDO %s\n", NOME_ARQUIVO_ENCAMINHAMENTO);

    fprintf(arqEncaminhamento, "PACIENTE: %s\n", encaminhamento -> nomePaciente);
    fprintf(arqEncaminhamento, "CPF: %s\n\n", encaminhamento -> cpf);
    fprintf(arqEncaminhamento, "ESPECIALIDADE ENCAMINHADA: %s\n", encaminhamento -> especialidade);
    fprintf(arqEncaminhamento, "MOTIVO: %s\n\n", encaminhamento -> motivo);
    fprintf(arqEncaminhamento, "%s (%s)\n", encaminhamento -> nomeMedico, encaminhamento -> crm);
    fprintf(arqEncaminhamento, "%s\n", encaminhamento -> data);

    fclose(arqEncaminhamento);
}