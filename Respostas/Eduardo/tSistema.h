#ifndef _TSISTEMA_H_
#define _TSISTEMA_H_

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

void executaFilaDeImpressao(tSistema * sistema);

void finalizaSistema(tSistema * sistema);

#endif