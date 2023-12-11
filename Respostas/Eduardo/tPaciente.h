#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

#include "tLesao.h"

typedef struct tPaciente tPaciente;

tPaciente * cadastraPaciente(char *nomePaciente, char * cpfPaciente, char * dataNascimento,
                      char * telefone, char * genero, int idade);

char * ObtemNomePaciente(tPaciente * paciente);

char * ObtemCPFPaciente(tPaciente * paciente);

char * ObtemNascimentoPaciente(tPaciente * paciente);

char * ObtemTelefonePaciente(tPaciente * paciente);

char * ObtemGeneroPaciente(tPaciente * paciente);

int ObtemIdadePaciente(tPaciente * paciente);

void AlteraDiabetePaciente(tPaciente * paciente, int valor);

void AlteraFumantePaciente(tPaciente * paciente, int valor);

void AlteraAlergiaMedicamento(tPaciente * paciente, int valor);

void AlteraHistoricoDeCancerPaciente(tPaciente * paciente, int valor);

void AlteraTipoDePelePaciente(tPaciente * paciente, char * valor);

int EhDiabeticoPaciente(tPaciente * paciente);

int EhFumantePaciente(tPaciente * paciente);

int TemHistoricoDeCancerPaciente(tPaciente * paciente);

char * ObtemTipoPelePaciente(tPaciente * paciente);

int ObtemQuantidadeLesoesPaciente(tPaciente * paciente);

int ObtemQtdLesoesCirurgia(tPaciente * paciente);

int ObtemQtdLesoesCrioterapia(tPaciente * paciente);

tLesao ** ObtemLesoesPaciente(tPaciente * paciente);

int ObtemTamanhoLesaoPaciente(tPaciente * paciente, int indice);

void adicionaLesaoPaciente(tPaciente * paciente);

void desalocaPaciente(tPaciente * paciente);

void imprimeNaTelaPaciente(tPaciente * paciente);

void imprimeEmArquivoPaciente(tPaciente * paciente, FILE * arqPaciente);

void salvaBinarioPaciente(tPaciente * paciente, FILE * bPaciente);

tPaciente * recuperaPaciente(FILE * bPaciente);

void foiAtendidoPaciente(tPaciente * paciente);

int ObtemAtendidoPaciente(tPaciente * paciente);

#endif