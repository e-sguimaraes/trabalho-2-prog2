#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tReceita.h"
#include "limites.h"

struct tReceita {
    char pacienteNome[MAX_NOME];
    eTipoUso tipoUso;
    char medicamentoNome[MAX_TAM_NOME_MEDICAMENTO];
    char tipoMedicamento[MAX_TAM_TIPO_MEDICAMENTO];
    int qtd;
    char instrucoes[MAX_TAM_INSTRUCOES];
    char medicoNome[MAX_NOME];
    char crm[TAM_CRM];
    char data[TAM_DATA];
};


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

    if(receita -> tipoUso == ORAL) {
        printf("USO ORAL\n\n");
    }
    else {
        printf("USO TOPICO\n\n");
    }

    printf("%s\n%d %s\n\n", receita -> medicamentoNome, receita -> qtd, receita -> tipoMedicamento);
    printf("%s\n\n", receita -> instrucoes);
    printf("%s %s\n", receita -> medicoNome, receita -> crm);
    printf("%s\n", receita -> data);

}


void imprimeEmArquivoReceita(void *dado, char *path) {

    FILE * arqReceita = NULL;
    tReceita * receita = (tReceita *)dado;

    char diretorioDaReceita[50];
    sprintf(diretorioDaReceita, "%s/%s", path, NOME_ARQUIVO_RECEITA);
    arqReceita = fopen(diretorioDaReceita, "a");

    printf("IMPRIMINDO %s\n", NOME_ARQUIVO_RECEITA);
    fprintf(arqReceita, "RECEITUARIO\n");
    fprintf(arqReceita, "NOME: %s\n\n", receita -> pacienteNome);

    if(receita -> tipoUso == ORAL) {
        fprintf(arqReceita, "USO ORAL\n\n");
    }
    else {
        fprintf(arqReceita, "USO TOPICO\n\n");
    }

    fprintf(arqReceita, "%s\n%d %s\n\n", receita -> medicamentoNome, receita -> qtd, receita -> tipoMedicamento);
    fprintf(arqReceita, "%s\n\n", receita -> instrucoes);
    fprintf(arqReceita, "%s (%s)\n", receita -> medicoNome, receita -> crm);
    fprintf(arqReceita, "%s\n", receita -> data);

    fclose(arqReceita);
}
