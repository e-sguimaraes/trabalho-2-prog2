#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPaciente.h"

#define MAX_NOME 101
#define TAM_CRM 13
#define TAM_DATA 11
#define TAM_CPF 15
#define TAM_TEL 15
#define TAM_GEN 10
#define MAX_TAM_ESPECIALIDADE 51
#define MAX_TAM_MOTIVO 301
#define MAX_PELE 3

struct tPaciente {
    char nomePaciente[MAX_NOME];
    char cpf[TAM_CPF];
    char dataNascimento[TAM_DATA];
    char telefone[TAM_TEL];
    char genero[TAM_GEN];
    int idade;
    int diabetico;
    int fumante;
    int alergiaMedicamento;
    int historicoCancer;
    char tipoPele[MAX_PELE];
    tLesao ** lesoes;
    int qtdLesoes;
};


tPaciente * cadastraPaciente(char *nomePaciente, char * cpfPaciente, char * dataNascimento,
                      char * telefone, char * genero, int idade) {
    
    tPaciente * paciente = (tPaciente *) calloc(1, sizeof(tPaciente));

    strcpy(paciente -> nomePaciente, nomePaciente);
    strcpy(paciente -> cpf, cpfPaciente);
    strcpy(paciente -> dataNascimento, dataNascimento);
    strcpy(paciente -> telefone, telefone);
    strcpy(paciente -> genero, genero);
    paciente -> idade = idade;
    paciente -> diabetico = 0;
    paciente -> fumante = 0;
    paciente -> alergiaMedicamento = 0;
    paciente -> historicoCancer = 0;
    paciente -> tipoPele[0] = '\0';
    paciente -> lesoes = (tLesao **) calloc(1, sizeof(tLesao *));
    paciente -> qtdLesoes = 0;

return paciente;
}


char * ObtemNomePaciente(tPaciente * paciente) {
return paciente -> nomePaciente;
}


char * ObtemCPFPaciente(tPaciente * paciente) {
return paciente -> cpf;
}


char * ObtemNascimentoPaciente(tPaciente * paciente) {
return paciente -> dataNascimento;
}


char * ObtemTelefonePaciente(tPaciente * paciente) {
return paciente -> telefone;
}


char * ObtemGeneroPaciente(tPaciente * paciente) {
return paciente -> genero;
}


int ObtemIdadePaciente(tPaciente * paciente) {
return paciente -> idade;
}


void AlteraDiabetePaciente(tPaciente * paciente, int valor) {
    paciente -> diabetico = valor;
}


void AlteraFumantePaciente(tPaciente * paciente, int valor) {
    paciente -> fumante = valor;
}


void AlteraAlergiaMedicamento(tPaciente * paciente, int valor) {
    paciente -> alergiaMedicamento = valor;
}


void AlteraHistoricoDeCancerPaciente(tPaciente * paciente, int valor) {
    paciente -> historicoCancer = valor;
}


void AlteraTipoDePelePaciente(tPaciente * paciente, char * valor) {
    strcpy(paciente -> tipoPele, valor);
}


int EhDiabeticoPaciente(tPaciente * paciente) {
return paciente -> diabetico;
}


int EhFumantePaciente(tPaciente * paciente) {
return paciente -> fumante;
}


int TemHistoricoDeCancerPaciente(tPaciente * paciente) {
return paciente -> historicoCancer;
}


char * ObtemTipoPelePaciente(tPaciente * paciente) {
return paciente -> tipoPele;
}


int ObtemQuantidadeLesoesPaciente(tPaciente * paciente) {
return paciente -> qtdLesoes;
}


int ObtemQtdLesoesCirurgia(tPaciente * paciente) {

    int cont = 0;

    for(int i = 0; i < paciente -> qtdLesoes; i++) {
        if(NecessitaCirurgiaLesao(paciente -> lesoes[i])) cont++;
    }

return cont;
}


int ObtemQtdLesoesCrioterapia(tPaciente * paciente) {

    int cont = 0;

    for(int i = 0; i < paciente -> qtdLesoes; i++) {
        if(NecessitaCrioterapiaLesao(paciente -> lesoes[i])) cont++;
    }

return cont;  
}

tLesao ** ObtemLesoesPaciente(tPaciente * paciente) {
return paciente -> lesoes;
}


int ObtemTamanhoLesaoPaciente(tPaciente * paciente, int indice) {
return ObtemTamanhoLesao(paciente -> lesoes[indice]);
}


void adicionaLesaoPaciente(tPaciente * paciente) {

    paciente -> qtdLesoes++;
    adicionaLesao(paciente -> lesoes, paciente -> qtdLesoes);

}


void desalocaPaciente(tPaciente * paciente) {
    desalocaLesao(paciente -> lesoes, paciente -> qtdLesoes);
    free(paciente);
}


void imprimeNaTelaPaciente(tPaciente * paciente) {

    printf("%s (%s)\n", paciente -> nomePaciente, paciente -> cpf);

}


void imprimeEmArquivoPaciente(tPaciente * paciente, FILE * arqPaciente) {

    fprintf(arqPaciente, "%s (%s)\n", paciente -> nomePaciente, paciente -> cpf);

}

void salvaBinarioPaciente(tPaciente * paciente, FILE * bUsuario) {
    fwrite(paciente, sizeof(tPaciente), 1, bUsuario);

    salvaBinarioLesoes(paciente -> lesoes, paciente -> qtdLesoes, bUsuario);
}

tPaciente * recuperaPaciente(FILE * bUsuario) {
    
    tPaciente * paciente = (tPaciente *) calloc(1, sizeof(tPaciente));

    fread(paciente, sizeof(tPaciente), 1, bUsuario);

    if(paciente -> qtdLesoes) paciente -> lesoes = recuperaLesoes(bUsuario, paciente -> qtdLesoes);

return paciente;
}