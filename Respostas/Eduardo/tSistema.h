#ifndef _TSISTEMA_H_
#define _TSISTEMA_H_

#define MAX_NOME 100
#define TAM_CRM 12
#define TAM_DATA 10
#define TAM_CPF 14
#define TAM_TEL 14
#define TAM_GEN 9
#define MAX_TAM_ESPECIALIDADE 50
#define MAX_TAM_MOTIVO 300

#include "tUsuario.h"

typedef struct tSistema tSistema;

/**
 * Função que recebe todas as informações pertinentes a um sistema e retorna
 * um ponteiro com o sistema criado.
 */
tSistema * criaSistema();

void adicionaUsuarioSistema(tSistema * sistema, int nivelUser);

void adicionaPaciente(tSistema * sistema);

void executaConsulta(tSistema * sistema, tUsuario * usuario);

void buscaPacienteSistema(tSistema * sistema);

void relatorioGeralSistema(tSistema * sistema);

void executaFilaDeImpressao(tSistema * sistema, char * path);

void finalizaSistema(tSistema * sistema);

int obtemAtendidos(tSistema * sistema);

int obtemQtdPacientes(tSistema * sistema);

tUsuario * fazLogin(tSistema * sistema);

#endif