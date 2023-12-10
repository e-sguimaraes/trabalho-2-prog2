#ifndef _TLESAO_H_
#define _TLESAO_H_

#define NOME_ARQUIVO_LESAO "lesao.txt"


typedef struct tLesao tLesao;


tLesao * copiaLesao(tLesao * lesao);


void adicionaLesao(tLesao ** lesao, int qtdLesoes);


int NecessitaCirurgiaLesao(tLesao * lesao);


int NecessitaCrioterapiaLesao(tLesao * lesao);


int ObtemTamanhoLesao(tLesao * lesao);


void desalocaLesao(tLesao ** lesoes, int qtdLesoes);


void imprimeNaTelaLesao(tLesao ** lesoes, int qtdLesoes);


void imprimeEmArquivoLesao(tLesao ** lesoes, int qtdLesoes, FILE * arqLesao);

#endif