#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tConsulta.h"

struct tConsulta{
    char cpf[TAM_CPF];
    char crm[TAM_CRM];
    char dataConsulta[TAM_DATA];
    int diabete;
    int fumante;
    int alergia;
    int historicoDeCancer;
    int qtdLesoes;
};


tConsulta * criaConsulta(char * cpf, char * crm, char * dataConsulta, int diabete, 
                         int fumante, int alergia, int historicoDeCancer, int qtdLesoes) {
    
    tConsulta * consulta = (tConsulta *) calloc(1, sizeof(tConsulta));

    strcpy(consulta -> cpf, cpf);
    strcpy(consulta -> crm, crm);
    strcpy(consulta -> dataConsulta, dataConsulta);
    consulta -> diabete = diabete;
    consulta -> fumante = fumante;
    consulta -> alergia = alergia;
    consulta -> historicoDeCancer = historicoDeCancer;
    consulta -> qtdLesoes = qtdLesoes;

return consulta;
}


void salvaBinarioConsulta(tConsulta * consulta, FILE * bConsulta) {
    fwrite(consulta, sizeof(tConsulta), 1, bConsulta);
}


void desalocaConsulta(tConsulta * consulta) {
    free(consulta);
}


tConsulta * recuperaConsulta(FILE * bConsultas) {

    tConsulta * consulta = (tConsulta *) calloc(1, sizeof(tConsulta));

    fread(consulta, sizeof(tConsulta), 1, bConsultas);

return consulta;
}