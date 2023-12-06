#ifndef _TLESAO_H_
#define _TLESAO_H_

//MEXER AQUI
#define MAX_TAM_NOME_MEDICAMENTO 50
#define MAX_TAM_TIPO_MEDICAMENTO 50
#define MAX_TAM_INSTRUCOES 300
#define NOME_ARQUIVO_RECEITA "receita.txt"


typedef struct tLesao tLesao;

/**
 * Função que recebe todas as informações de uma lesão e retorna um ponteiro para essa lesão;
 */
tLesao ** criaLesoes();


/**
 * Função que recebe o ponteiro genérico (que deve conter uma biopsia) e o desaloca da memória.
 * Essa função primeiro verifica se o ponteiro é NULL antes de desalocar.
 */
void desalocaLesao(tLesao ** lesoes, int qtdLesoes);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma lesao) e imprime os dados na tela
 * de acordo com o especificado na descrição do trabalho.
 */
void imprimeNaTelaLesao(tLesao ** lesoes, int qtdLesoes);

/**
 * Função que recebe um ponteiro genérico (que deve conter uma lesao) e imprime os dados no arquivo
 * específico de acordo com a descrição do trabalho.
 * Essa função também recebe o path da pasta onde o arquivo deve ser criado ou editado.
 * Ex: /home/usuario/Documentos
 * O nome do arquivo e a maneira de escrita é definido dentro da função
 */
void imprimeEmArquivoLesao(tLesao ** lesoes, int qtdLesoes, char *path);

#endif