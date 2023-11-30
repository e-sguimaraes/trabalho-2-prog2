#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tEncaminhamento.h"

typedef struct {
    char * nomePaciente[100];
    char * cpf[14];
    char * especialidade[MAX_TAM_ESPECIALIDADE];
    char * motivo[MAX_TAM_MOTIVO];
    char * nomeMedico[100];
    char * crm[12];
    char * data[10];
} tEncaminhamento;


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

/**
 * Função que recebe um ponteiro genérico (que deve conter um encaminhamento) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaEncaminhamento(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter um encaminhamento) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoEncaminhamento(void *dado, char *path);