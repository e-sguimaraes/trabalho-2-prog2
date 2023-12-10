#ifndef _TUSUARIO_H_
#define _TUSUARIO_H_

#define MAX_NOME 100
#define TAM_CRM 12
#define TAM_DATA 11
#define TAM_CPF 15
#define TAM_TEL 15
#define TAM_GEN 10
#define MAX_USER 21

typedef struct tUsuario tUsuario;

/**
 * Função que recebe todas as informações pertinentes a um usuario e retorna
 * um ponteiro com o usuario criado.
 */
tUsuario * cadastraUsuario(char *nomeUsuario, char * cpfUsuario, char * dataNascimento, char * telefone,
                           char * genero, char * crm, char * nomeUser, char * senhaUser, int nivelUser);

char * ObtemNomeUsuario(tUsuario * usuario);

char * ObtemCPFUsuario(tUsuario * usuario);

char * ObtemNascimentoUsuario(tUsuario * usuario);

char * ObtemTelefoneUsuario(tUsuario * usuario);

char * ObtemGeneroUsuario(tUsuario * usuario);

char * ObtemCRMUsuario(tUsuario * usuario);

char * ObtemNomeUser(tUsuario * usuario);

char * ObtemSenhaUser(tUsuario * usuario);

int ObtemNivelUser(tUsuario * usuario);

/**
 * Função que recebe o ponteiro genérico (que deve conter um usuario) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaUsuario(tUsuario * usuario);

#endif