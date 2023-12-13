#ifndef _TCONSULTA_H_
#define _TCONSULTA_H_

#define MAX_NOME 100
#define TAM_CRM 12
#define TAM_DATA 11
#define TAM_CPF 15
#define TAM_TEL 15
#define TAM_GEN 10
#define MAX_USER 21

typedef struct tConsulta tConsulta;

tConsulta * criaConsulta(char * cpf, char * crm, char * dataConsulta, int diabete, 
                         int fumante, int alergia, int historicoDeCancer, int qtdLesoes);

void salvaBinarioConsulta(tConsulta * consulta, FILE * bConsulta);

void desalocaConsulta(tConsulta * consulta);

tConsulta * recuperaConsulta(FILE * bConsultas);

#endif