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


tLesao ** criaLesoes() {

    tLesao ** lesao = (tLesao **) malloc(sizeof(tLesao *));

    lesao[0] = (tLesao *) malloc(sizeof(tLesao));

return lesao;
}

void adicionaLesao(tLesao ** lesoes, int qtdLesoes) {

    tLesao * lesao = (tLesao *) malloc(sizeof(tLesao));
    scanf("%s", &lesao -> rotulo);
    scanf("%s", &lesao -> diagnostico);
    scanf("%s", &lesao -> regiao);
    scanf("%d", &lesao -> tamanho);
    scanf("%d", &lesao -> necessitaCirurgia);
    scanf("%d", &lesao -> necessitaCrioterapia);

    lesoes = (tLesao **) realloc(lesoes, qtdLesoes * sizeof(tLesao *));
    lesoes[qtdLesoes - 1] = (tLesao *) malloc(sizeof(tLesao));
    lesoes[qtdLesoes - 1] = lesao;

}


void desalocaLesao(tLesao ** lesoes, int qtdLesoes) {

    for(int i = 0; i < qtdLesoes; i++) {
        free(lesoes[i]);
    }
    free(lesoes);

}


void imprimeNaTelaLesao(tLesao ** lesoes, int qtdLesoes) {
    
    for(int i = 0; i < qtdLesoes; i++) {
        printf("%s - %s - %s - %dMM\n\n", lesoes[i] -> rotulo, lesoes[i] -> diagnostico, lesoes[i] -> regiao, lesoes[i] -> tamanho);
    }

}


void imprimeEmArquivoLesao(tLesao ** lesoes, int qtdLesoes, char *path) {

    FILE * arqLesao = NULL;

    arqLesao = fopen(path, "a");
    for(int i = 0; i < qtdLesoes; i++) {
        fprintf(arqLesao, "%s - %s - %s - %dMM\n\n", lesoes[i] -> rotulo, lesoes[i] -> diagnostico, lesoes[i] -> regiao, lesoes[i] -> tamanho);
    }

}