#ifndef _TSISTEMA_H_
#define _TSISTEMA_H_

#include "tUsuario.h"

typedef struct tSistema tSistema;

/**
 * Função que recebe todas as informações pertinentes a um sistema e retorna
 * um ponteiro com o sistema criado.
 */
tSistema * criaSistema(char * binaryPath);

void adicionaPessoaSistema(tSistema * sistema, int nivelUser);

void executaConsulta(tSistema * sistema, tUsuario * usuario);

void buscaPacienteSistema(tSistema * sistema);

void relatorioGeralSistema(tSistema * sistema);

void executaFilaDeImpressao(tSistema * sistema, char * path);

void finalizaSistema(tSistema * sistema, char * binaryPath);

int obtemQtdPacientes(tSistema * sistema);

tUsuario * fazLogin(tSistema * sistema);

#endif