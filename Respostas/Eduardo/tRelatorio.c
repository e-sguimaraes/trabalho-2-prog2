#include <stdlib.h>
#include <stdio.h>
#include "tRelatorio.h"
#include "tPaciente.h"

struct tRelatorio {
    int totalAtendidos;
    int idadeMedia;
    int f, m, o;
    int tamMedioLesoes;
    int nLesoes, cirurgiaLesoes, crioterapiaLesoes;
};

tRelatorio * criaRelatorio(int totalAtendidos, int idadeMedia, int f, int m, int o, int tamMedioLesoes,
                           int nLesoes, int cirurgiaLesoes, int crioterapiaLesoes) {

    tRelatorio * relatorio = (tRelatorio *) malloc(sizeof(tRelatorio));

    relatorio -> totalAtendidos = totalAtendidos;
    relatorio -> idadeMedia = idadeMedia;
    relatorio -> f = f;
    relatorio -> m = m;
    relatorio -> o = o;
    relatorio -> tamMedioLesoes = tamMedioLesoes;
    relatorio -> nLesoes = nLesoes;
    relatorio -> cirurgiaLesoes = cirurgiaLesoes;
    relatorio -> crioterapiaLesoes = crioterapiaLesoes;

return relatorio;
}

void imprimeNaTelaRelatorio(void *dado) {

    tRelatorio * relatorio = (tRelatorio *)dado;

    printf("#################### RELATORIO GERAL #######################\n");

    printf("NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", relatorio -> totalAtendidos);
    printf("IDADE MEDIA: %d\n", relatorio -> idadeMedia);
    printf("DISTRIBUICAO POR GENERO:\n");
    printf("- FEMININO: %d\n", relatorio -> f);
    printf("- MASCULINO: %d\n", relatorio -> m);
    printf("- OUTROS: %d\n", relatorio -> o);
    printf("TAMANHO MEDIO DAS LESOES: %d\n", relatorio -> tamMedioLesoes);
    printf("NUMERO TOTAL DE LESOES: %d\n", relatorio -> nLesoes);
    printf("NUMERO TOTAL DE CIRURGIAS: %d\n", relatorio -> cirurgiaLesoes);
    printf("NUMERO TOTAL DE CRIOTERAPIA: %d\n", relatorio -> crioterapiaLesoes);

    printf("############################################################\n");

}

void imprimeEmArquivoRelatorio(void *dado, char *path) {

    FILE * arqRelatorio = NULL;
    tRelatorio * relatorio = (tRelatorio *)dado;

    char diretorioDoRelatorio[50];
    sprintf(diretorioDoRelatorio, "%s/%s", path, NOME_ARQUIVO_RELATORIO);
    arqRelatorio = fopen(diretorioDoRelatorio, "a");

    fprintf(arqRelatorio, "NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", relatorio -> totalAtendidos);
    fprintf(arqRelatorio, "IDADE MEDIA: %d\n", relatorio -> idadeMedia);
    fprintf(arqRelatorio, "DISTRIBUICAO POR GENERO:\n");
    fprintf(arqRelatorio, "- FEMININO: %d\n", relatorio -> f);
    fprintf(arqRelatorio, "- MASCULINO: %d\n", relatorio -> m);
    fprintf(arqRelatorio, "- OUTROS: %d\n", relatorio -> o);
    fprintf(arqRelatorio, "TAMANHO MEDIO DAS LESOES: %d\n", relatorio -> tamMedioLesoes);
    fprintf(arqRelatorio, "NUMERO TOTAL DE LESOES: %d\n", relatorio -> nLesoes);
    fprintf(arqRelatorio, "NUMERO TOTAL DE CIRURGIAS: %d\n", relatorio -> cirurgiaLesoes);
    fprintf(arqRelatorio, "NUMERO TOTAL DE CRIOTERAPIA: %d\n", relatorio -> crioterapiaLesoes);

    fclose(arqRelatorio);

}

void desalocaRelatorio(void * dado) {
    free((tRelatorio *)dado);
}