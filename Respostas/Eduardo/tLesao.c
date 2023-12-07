#include <stdlib.h>
#include <stdio.h>
#include "tLesao.h"

#define TAM_ROTULO 5
#define TAM_DIAGNO 23
#define TAM_REGIAO 14


struct tLesao {
    char * rotulo[TAM_ROTULO];
    char * diagnostico[TAM_DIAGNO];
    char * regiao[TAM_REGIAO];
    int tamanho;
    int necessitaCirurgia;
    int necessitaCrioterapia;
};


tLesao * criaLesao() {

    tLesao * lesao = (tLesao *) malloc(sizeof(tLesao));

return lesao;
}

void adicionaLesao(tLesao ** lesoes, int qtdLesoes) {

    tLesao * lesao = (tLesao *) malloc(sizeof(tLesao));

    lesao -> rotulo; //O QUE?

    printf("#################### CONSULTA MEDICA #######################\n");
    printf("CADASTRO DE LESAO:\n");
    printf("DIAGNOSTICO CLINICO: ");
    scanf("%s", &lesao -> diagnostico);
    printf("REGIAO DO CORPO: ");
    scanf("%s", &lesao -> regiao);
    printf("TAMANHO: ");
    scanf("%d", &lesao -> tamanho);
    printf("ENVIO PARA CIRURGIA: ");
    scanf("%d", &lesao -> necessitaCirurgia);
    printf("ENVIO PARA CRIOTERAPIA: ");
    scanf("%d", &lesao -> necessitaCrioterapia);

    lesoes = (tLesao **) realloc(lesoes, qtdLesoes * sizeof(tLesao *));
    lesoes[qtdLesoes - 1] = (tLesao *) malloc(sizeof(tLesao));
    lesoes[qtdLesoes - 1] = lesao;

    printf("LESAO REGISTRADA COM SUCESSO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
    printf("############################################################");

}


void desalocaLesao(tLesao ** lesoes, int qtdLesoes) {

    for(int i = 0; i < qtdLesoes; i++) {
        free(lesoes[i]);
    }
    free(lesoes);

}


void imprimeNaTelaLesao(tLesao ** lesoes, int qtdLesoes) {
    
    //CONFERIR SE TODAS AS LESOES QUE SÃO PRINTADAS SEGUEM O MODELO DE CIRURGIA;
    for(int i = 0; i < qtdLesoes; i++) {
        if(NecessitaCirurgiaLesao(lesoes[i])) printf("%s - %s - %s - %dMM\n\n", lesoes[i] -> rotulo, lesoes[i] -> diagnostico, lesoes[i] -> regiao, lesoes[i] -> tamanho);
    }

}


void imprimeEmArquivoLesao(tLesao ** lesoes, int qtdLesoes, char *path) {

    FILE * arqLesao = NULL;

    arqLesao = fopen(path, "a");
    for(int i = 0; i < qtdLesoes; i++) {
        fprintf(arqLesao, "%s - %s - %s - %dMM\n\n", lesoes[i] -> rotulo, lesoes[i] -> diagnostico, lesoes[i] -> regiao, lesoes[i] -> tamanho);
    }

}