#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tLesao.h"

#define TAM_ROTULO 6
#define TAM_DIAGNO 24
#define TAM_REGIAO 15


struct tLesao {
    char rotulo[TAM_ROTULO];
    char diagnostico[TAM_DIAGNO];
    char regiao[TAM_REGIAO];
    int tamanho;
    int necessitaCirurgia;
    int necessitaCrioterapia;
};


tLesao * copiaLesao(tLesao * src) {

    tLesao * dest = (tLesao *) calloc(1, sizeof(tLesao));
    strcpy(dest -> rotulo, src -> rotulo);
    strcpy(dest -> diagnostico, src -> diagnostico);
    strcpy(dest -> regiao, src -> regiao);
    dest -> tamanho = src -> tamanho;
    dest -> necessitaCirurgia = src -> necessitaCirurgia;
    dest -> necessitaCrioterapia = src -> necessitaCrioterapia;

return dest;
}


void desalocaLesao(tLesao ** lesoes, int qtdLesoes) {

    for(int i = 0; i < qtdLesoes; i++) {
        free(lesoes[i]);
    }
    free(lesoes);

}


tLesao ** copiaLesoes(tLesao ** lesoes, tLesao * lesaoNova, int qtdLesoes) {
    
    tLesao ** lesoesNova = (tLesao **) malloc(qtdLesoes * sizeof(tLesao *));

    for(int i = 0; i < qtdLesoes - 1; i++) {
        lesoesNova[i] = copiaLesao(lesoes[i]);
    }

    lesoesNova[qtdLesoes - 1] = copiaLesao(lesaoNova);

    desalocaLesao(lesoes, qtdLesoes - 1);

    free(lesaoNova);

return lesoesNova;
}


tLesao ** adicionaLesao(tLesao ** lesoes, int qtdLesoes) {

    tLesao * lesao = (tLesao *) calloc(1, sizeof(tLesao));

    sprintf(lesao -> rotulo, "L%d", qtdLesoes);

    printf("#################### CONSULTA MEDICA #######################\n");
    printf("CADASTRO DE LESAO:\n");
    printf("DIAGNOSTICO CLINICO: ");
    scanf("%[^\n]%*c", lesao -> diagnostico);
    printf("REGIAO DO CORPO: ");
    scanf("%[^\n]%*c", lesao -> regiao);
    printf("TAMANHO: ");
    scanf("%d%*c", &lesao -> tamanho);
    printf("ENVIO PARA CIRURGIA: ");
    scanf("%d%*c", &lesao -> necessitaCirurgia);
    printf("ENVIO PARA CRIOTERAPIA: ");
    scanf("%d%*c", &lesao -> necessitaCrioterapia);

    printf("LESAO REGISTRADA COM SUCESSO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
    printf("############################################################");

    scanf("%*c");

return copiaLesoes(lesoes, lesao, qtdLesoes);
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

void salvaBinarioLesoes(tLesao ** lesoes, int qtdLesoes, FILE * binaryLesao) {
    for(int i = 0; i < qtdLesoes; i++) {
        fwrite(lesoes[i], sizeof(tLesao), 1, binaryLesao);
    }
}

void salvaBinarioLesao(tLesao * lesao, FILE * binaryLesao) {
    fwrite(lesao, sizeof(tLesao), 1, binaryLesao);
}

tLesao ** recuperaLesoes(FILE * binaryLesao, int qtdLesoes) {

    tLesao ** lesoes = (tLesao **) calloc(qtdLesoes, sizeof(tLesao *));

    for(int i = 0; i < qtdLesoes; i++) {
        tLesao * lesao = (tLesao *) calloc(1, sizeof(tLesao));
        fread(lesao, sizeof(tLesao), 1, binaryLesao);
        lesoes[i] = lesao;
    }

return lesoes;
}

tLesao * recuperaLesao(FILE * binaryLesao) {
    
    tLesao * lesao = (tLesao *) calloc(1, sizeof(tLesao));

    fread(lesao, sizeof(tLesao), 1, binaryLesao);

return lesao;
}