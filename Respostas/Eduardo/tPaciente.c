#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPaciente.h"

typedef struct tPaciente {
    char * nomePaciente;
    char * cpf;
    char * dataNascimento;
    char * telefone;
    char * genero;
    int diabetico;
    int fumante;
    int historicoCancer;
    int tipoPele;
};


tPaciente * criaPaciente(char *nomePaciente, char * cpfPaciente, char * dataNascimento,
                      char * telefone, char * genero) {
    
    tPaciente * paciente = (tPaciente *) malloc(sizeof(tPaciente));

    strcpy(paciente -> nomePaciente, nomePaciente);
    strcpy(paciente -> cpf, cpfPaciente);
    strcpy(paciente -> dataNascimento, dataNascimento);
    strcpy(paciente -> telefone, telefone);
    strcpy(paciente -> genero, genero);
    paciente -> diabetico = 0;
    paciente -> fumante = 0;
    paciente -> historicoCancer = 0;
    paciente -> tipoPele = 0;

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


int EhDiabeticoPaciente(tPaciente * paciente) {
return paciente -> diabetico;
}


int EhFumantePaciente(tPaciente * paciente) {
return paciente -> fumante;
}


int TemHistoricoDeCancerPaciente(tPaciente * paciente) {
return paciente -> historicoCancer;
}


int ObtemTipoPelePaciente(tPaciente * paciente) {
return paciente -> tipoPele;
}


void desalocaPaciente(tPaciente * paciente) {
    free(paciente);
}


void imprimeNaTelaPaciente(tPaciente * paciente) {

    printf("%s (%s)\n", paciente -> nomePaciente, paciente -> cpf);

}


void imprimeEmArquivoPaciente(tPaciente * paciente, char *path) {

    FILE * arqPaciente = NULL;

    arqPaciente = fopen(path, "a");
    fprintf(arqPaciente, "%s (%s)\n", paciente -> nomePaciente, paciente -> cpf);

    
}