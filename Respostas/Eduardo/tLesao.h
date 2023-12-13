#ifndef _TLESAO_H_
#define _TLESAO_H_

#define NOME_ARQUIVO_LESAO "lesao.txt"


typedef struct tLesao tLesao;


tLesao * copiaLesao(tLesao * lesao);


tLesao ** adicionaLesao(tLesao ** lesao, int qtdLesoes);


int NecessitaCirurgiaLesao(tLesao * lesao);


int NecessitaCrioterapiaLesao(tLesao * lesao);


int ObtemTamanhoLesao(tLesao * lesao);

/**
 * Função que recebe um ponteiro de ponteiro para lesões, bem como sua quantidade e
 * desaloca TODAS as lesões
 */
void desalocaLesao(tLesao ** lesoes, int qtdLesoes);

void imprimeNaTelaLesao(tLesao ** lesoes, int qtdLesoes);

void imprimeEmArquivoLesao(tLesao ** lesoes, int qtdLesoes, FILE * arqLesao);

void salvaBinarioLesoes(tLesao ** lesoes, int qtdLesoes, FILE * binaryLesao);

tLesao ** recuperaLesoes(FILE * binaryLesao, int qtdLesoes);

tLesao * recuperaLesao(FILE * binaryLesao);

#endif