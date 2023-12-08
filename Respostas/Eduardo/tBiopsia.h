#ifndef _TBIOPSIA_H_
#define _TBIOPSIA_H_

#include "tLesao.h"

#define MAX_TAM_NOME_MEDICAMENTO 50
#define MAX_TAM_TIPO_MEDICAMENTO 50
#define MAX_TAM_INSTRUCOES 300
#define NOME_ARQUIVO_BIOPSIA "biopsia.txt"

#define MAX_NOME 100
#define TAM_CRM 12
#define TAM_DATA 10
#define TAM_CPF 14
#define TAM_TEL 14
#define TAM_GEN 9
#define MAX_TAM_ESPECIALIDADE 50
#define MAX_TAM_MOTIVO 300


typedef struct tBiopsia tBiopsia;

/**
 * Função que recebe todas as informações pertinentes a uma biopsia e retorna
 * um ponteiro com a biopsia criada.
 * Apenas pacientes com lesões enviadas para cirurgia podem gerar uma biópsia,
 * caso não exista uma lesão enviada para cirurgia, retorna NULL;
 */
tBiopsia * criaBiopsia(char *nomePaciente, char * cpfPaciente, tLesao ** lesoes,
                      int qtdLesoes, char * nomeMedico, char * crm, char * data);

/**
 * Função que recebe o ponteiro genérico (que deve conter uma biopsia) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaBiopsia(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma biopsia) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaBiopsia(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma biopsia) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoBiopsia(void *dado, char *path);

#endif