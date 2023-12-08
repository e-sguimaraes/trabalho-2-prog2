#ifndef _TLISTABUSCA_H_
#define _TLISTABUSCA_H_

#include "tPaciente.h"

#define NOME_ARQUIVO_LISTA_BUSCA "lista_busca.txt"

typedef struct tListaBusca tListaBusca;

tListaBusca * criaListaBusca(tPaciente ** pacientes, int qtdPacientes, char * nomeProcurado);

void imprimeNaTelaListaBusca(void *dado);

void imprimeEmArquivoListaBusca(void *dado, char *path);

void desalocaListaBusca(void * dado);

#endif