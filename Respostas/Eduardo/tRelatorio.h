#ifndef _TRELATORIO_H_
#define _TRELATORIO_H_

#define NOME_ARQUIVO_RELATORIO "relatorio.txt"

typedef struct tRelatorio tRelatorio;

tRelatorio * criaRelatorio(int totalAtendidos, int idadeMedia, int f, int m, int o, int tamMedioLesoes,
                           int nLesoes, int cirurgiaLesoes, int crioterapiaLesoes); 

void imprimeNaTelaRelatorio(void *dado);

void imprimeEmArquivoRelatorio(void *dado, char *path);

void desalocaRelatorio(void * dado);

#endif