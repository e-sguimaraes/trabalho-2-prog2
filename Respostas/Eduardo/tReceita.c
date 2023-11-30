#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tReceita.h"

typedef enum
{
    ORAL,
    TOPICO
} eTipoUso;

typedef struct {
    char pacienteNome[100];
    eTipoUso tipoUso;
    char medicamentoNome[MAX_TAM_NOME_MEDICAMENTO];
    char tipoMedicamento[MAX_TAM_TIPO_MEDICAMENTO];
    int qtd;
    char instrucoes[MAX_TAM_INSTRUCOES];
    char medicoNome[100];
    char crm[12];
    char data[10];
} tReceita;


tReceita *criaReceita(char *nomePaciente, eTipoUso tipoUso, char *nomeMedicamento,
                      char *tipoMedicamento, char *instrucoes, int qntd,
                      char *nomeMedico, char *CRM, char *dataStr) {

    tReceita * receita = (tReceita *) malloc(sizeof(tReceita));

    strcpy(receita -> pacienteNome, nomePaciente);
    receita -> tipoUso = tipoUso;
    strcpy(receita -> medicamentoNome, nomeMedicamento);
    strcpy(receita -> tipoMedicamento, tipoMedicamento);
    receita -> qtd = qntd;
    strcpy(receita -> instrucoes, instrucoes);
    strcpy(receita -> medicoNome, nomeMedico);
    strcpy(receita -> crm, CRM);
    strcpy(receita -> data, dataStr);

return receita;
}


void desalocaReceita(void *dado) {
    free((tReceita *)dado);
}


void imprimeNaTelaReceita(void *dado) {

    tReceita * receita = (tReceita *)dado;

    printf("RECEITUARIO\n");
    printf("NOME: %s\n\n", receita -> pacienteNome);
    printf("%s\n\n", receita -> tipoUso);
    printf("%s\n%d %s\n\n", receita -> medicamentoNome, receita -> qtd, receita -> tipoMedicamento);
    printf("%s\n\n", receita -> instrucoes);
    printf("%s %s\n", receita -> medicoNome, receita -> crm);
    printf("%s\n", receita -> data);

}


void imprimeEmArquivoReceita(void *dado, char *path) {

    FILE * arqReceita = NULL;
    tReceita * receita = (tReceita *)dado;

    char diretorioDoResumo[50];
    sprintf(diretorioDoResumo, "%s/%s", path, NOME_ARQUIVO_RECEITA);
    arqReceita = fopen(diretorioDoResumo, "w");

    printf("IMPRIMINDO %s\n", NOME_ARQUIVO_RECEITA);
    fprintf(arqReceita, "RECEITUARIO\n");
    fprintf(arqReceita, "NOME: %s\n\n", receita -> pacienteNome);
    fprintf(arqReceita, "%s\n\n", receita -> tipoUso);
    fprintf(arqReceita, "%s\n%d %s\n\n", receita -> medicamentoNome, receita -> qtd, receita -> tipoMedicamento);
    fprintf(arqReceita, "%s\n\n", receita -> instrucoes);
    fprintf(arqReceita, "%s %s\n", receita -> medicoNome, receita -> crm);
    fprintf(arqReceita, "%s\n", receita -> data);

    fclose(arqReceita);
}
