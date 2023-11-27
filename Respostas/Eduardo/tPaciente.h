#ifndef _TPACIENTE_H_
#define _TPACIENTE_H_

//MEXER AQUI
#define MAX_TAM_NOME_MEDICAMENTO 50
#define MAX_TAM_TIPO_MEDICAMENTO 50
#define MAX_TAM_INSTRUCOES 300
#define NOME_ARQUIVO_RECEITA "receita.txt"


typedef struct tPaciente tPaciente;

/**
 * Função que recebe todas as informações pertinentes a um paciente e retorna
 * um ponteiro com o paciente criado.
 */
tPaciente * criaPaciente(char *nomePaciente, char * cpfPaciente, char * dataNascimento,
                      char * telefone, char * genero);

char * ObtemNomePaciente(tPaciente paciente);

char * ObtemCPFPaciente(tPaciente paciente);

char * ObtemNascimentoPaciente(tPaciente paciente);

char * ObtemTelefonePaciente(tPaciente paciente);

char * ObtemGeneroPaciente(tPaciente paciente);

char * ObtemGeneroPaciente(tPaciente paciente);

int EhDiabeticoPaciente(tPaciente paciente);

int EhFumantePaciente(tPaciente paciente);

int TemHistoricoDeCancerPaciente(tPaciente paciente);

int PelePaciente(tPaciente paciente);

/**
 * Função que recebe o ponteiro genérico (que deve conter um paciente) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaPaciente(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter um paciente) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaPaciente(void *dado);

/**
 * Função que recebe um ponteiro genérico (que deve conter paciente) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoPaciente(void *dado, char *path);

#endif