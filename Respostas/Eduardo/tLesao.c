#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tLesao.h"

#define TAM_ROTULO 5
#define TAM_DIAGNO 23
#define TAM_REGIAO 14


struct tLesao {
    char rotulo[TAM_ROTULO];
    char diagnostico[TAM_DIAGNO];
    char regiao[TAM_REGIAO];
    int tamanho;
    int necessitaCirurgia;
    int necessitaCrioterapia;
};


tLesao * copiaLesao(tLesao * src) {

    tLesao * dest = (tLesao *) malloc(sizeof(tLesao));
    strcpy(dest -> rotulo, src -> rotulo);
    strcpy(dest -> diagnostico, src -> diagnostico);
    strcpy(dest -> regiao, src -> regiao);
    dest -> tamanho = src -> tamanho;
    dest -> necessitaCirurgia = src -> necessitaCirurgia;
    dest -> necessitaCrioterapia = src -> necessitaCrioterapia;

return dest;
}

void adicionaLesao(tLesao ** lesoes, int qtdLesoes) {

    tLesao * lesao = (tLesao *) malloc(sizeof(tLesao));

    sprintf(lesao -> rotulo, "L%d", qtdLesoes);

    printf("#################### CONSULTA MEDICA #######################\n");
    printf("CADASTRO DE LESAO:\n");
    printf("DIAGNOSTICO CLINICO: ");
    scanf("%s%*c", lesao -> diagnostico);
    printf("REGIAO DO CORPO: ");
    scanf("%s%*c", lesao -> regiao);
    printf("TAMANHO: ");
    scanf("%d%*c", &lesao -> tamanho);
    printf("ENVIO PARA CIRURGIA: ");
    scanf("%d%*c", &lesao -> necessitaCirurgia);
    printf("ENVIO PARA CRIOTERAPIA: ");
    scanf("%d%*c", &lesao -> necessitaCrioterapia);

    if(qtdLesoes > 1) lesoes = (tLesao **) realloc(lesoes, qtdLesoes * sizeof(tLesao *));
    lesoes[qtdLesoes - 1] = lesao;

    printf("LESAO REGISTRADA COM SUCESSO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
    printf("############################################################");

    scanf("%*c");

}

int NecessitaCirurgiaLesao(tLesao * lesao) {
return lesao -> necessitaCirurgia;
}

int NecessitaCrioterapiaLesao(tLesao * lesao) {
return lesao -> necessitaCrioterapia;
}

int ObtemTamanhoLesao(tLesao * lesao) {
return lesao -> tamanho;
}


void desalocaLesao(tLesao ** lesoes, int qtdLesoes) {

    for(int i = 0; i < qtdLesoes; i++) {
        free(lesoes[i]);
    }
    free(lesoes);

}


void imprimeNaTelaLesao(tLesao ** lesoes, int qtdLesoes) {
    
    for(int i = 0; i < qtdLesoes; i++) {
        if(NecessitaCirurgiaLesao(lesoes[i])) printf("%s - %s - %s - %dMM\n\n", lesoes[i] -> rotulo, 
                                                     lesoes[i] -> diagnostico, lesoes[i] -> regiao, lesoes[i] -> tamanho);
    }

}


void imprimeEmArquivoLesao(tLesao ** lesoes, int qtdLesoes, FILE * arqLesao) {

    for(int i = 0; i < qtdLesoes; i++) {
        if(NecessitaCirurgiaLesao(lesoes[i])) fprintf(arqLesao, "%s - %s - %s - %dMM\n\n", lesoes[i] -> rotulo, 
                                                      lesoes[i] -> diagnostico, lesoes[i] -> regiao, lesoes[i] -> tamanho);
    }

}