#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tSistema.h"
#include "tUsuario.h"
#include "tPaciente.h"
#include "tFila.h"
#include "limites.h"

struct tSistema {
    tUsuario ** usuarios;
    tPaciente ** pacientes;
    tFila * fila;
    int qtdUsuarios;
    int qtdPacientes;
};


tSistema * criaSistema() {

    tSistema * sistema = (tSistema *) malloc(sizeof(tSistema));
    
    sistema -> usuarios = (tUsuario **) malloc(sizeof(tUsuario *));

    adicionaUsuarioSistema(sistema, 2); 

}

void adicionaUsuarioSistema(tSistema * sistema, int nivelUser) {

    sistema -> qtdUsuarios++;
    sistema -> usuarios = (tUsuario **) realloc(sistema -> usuarios, sistema -> qtdUsuarios * sizeof(tUsuario *));

    char * nomeUsuario[MAX_NOME];
    char * cpf[TAM_CPF];
    char * dataNascimento[TAM_DATA];
    char * telefone[TAM_TEL];
    char * genero[TAM_GEN];
    char * crm[TAM_CRM];
    char * nomeUser[MAX_USER];
    char * senhaUser[MAX_USER];

    char * nivelAcesso;

    switch (nivelUser) {

        case 1:
            printf("#################### CADASTRO MEDICO #######################\n");
            printf("NOME COMPLETO: ");
            scanf("%[^\n]%*c", nomeUsuario);
            printf("CPF: ");
            scanf("%s%*c", cpf);
            printf("DATA DE NASCIMENTO: ");
            scanf("%s%*c", dataNascimento);
            printf("TELEFONE: ");
            scanf("%s%*c", telefone);
            printf("GENERO: ");
            scanf("%s%*c", genero);
            printf("CRM: ");
            scanf("%s%*c", crm);
            printf("NOME DE USUARIO: ");
            scanf("%s%*c", nomeUser);
            printf("SENHA: ");
            scanf("%s%*c", senhaUser);

            sistema -> usuarios[(sistema -> qtdUsuarios) - 1] = cadastraUsuario(nomeUsuario, cpf, dataNascimento, telefone, 
                                                                                genero, crm, nomeUser, senhaUser, nivelUser);

            break;

        case 2:
            printf("#################### CADASTRO SECRETARIO #######################\n");
            printf("NOME COMPLETO: ");
            scanf("%[^\n]%*c", nomeUsuario);
            printf("CPF: ");
            scanf("%s%*c", cpf);
            printf("DATA DE NASCIMENTO: ");
            scanf("%s%*c", dataNascimento);
            printf("TELEFONE: ");
            scanf("%s%*c", telefone);
            printf("GENERO: ");
            scanf("%s%*c", genero);
            printf("NOME DE USUARIO: ");
            scanf("%s%*c", nomeUser);
            printf("SENHA: ");
            scanf("%s%*c", senhaUser);
            printf("NIVEL DE ACESSO: ");
            scanf("%s%*c", nivelAcesso);
            crm[0] = '\0';

            if(nivelAcesso[0] == 'A') nivelUser = 3;

            sistema -> usuarios[(sistema -> qtdUsuarios) - 1] = cadastraUsuario(nomeUsuario, cpf, dataNascimento, telefone, 
                                                                                genero, crm, nomeUser, senhaUser, nivelUser);
            break;
        
    }
    printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
    printf("############################################################\n");

}

void adicionaPaciente(tSistema * sistema) {

    sistema -> qtdPacientes++;
    sistema -> pacientes = (tPaciente **) realloc(sistema -> pacientes, sistema -> qtdPacientes * sizeof(tPaciente *));

    char * nomePaciente[MAX_NOME];
    char * cpf[TAM_CPF];
    char * dataNascimento[TAM_DATA];
    char * telefone[TAM_TEL];
    char * genero[TAM_GEN];

    printf("#################### CADASTRO PACIENTE #######################\n");
    printf("NOME COMPLETO: ");
    scanf("%[^\n]%*c", nomePaciente);
    printf("CPF: ");
    scanf("%s%*c", cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%s%*c", dataNascimento);
    printf("TELEFONE: ");
    scanf("%s%*c", telefone);
    printf("GENERO: ");
    scanf("%s%*c", genero);

}

void executaConsulta(tSistema * sistema, tUsuario * usuario) {

    printf("#################### CONSULTA MEDICA #######################\n");
    printf("CPF DO PACIENTE: ");

    char * cpfConsultado[TAM_CPF];
    int cpfEncontrado = 0;
    scanf("%s%*c", cpfConsultado);
    
    for(int i = 0; i < sistema -> qtdPacientes; i++) {
        if(strcmp(cpfConsultado, sistema -> pacientes[i])) {
            consultaPaciente(sistema -> pacientes[i], usuario);
            cpfEncontrado = 1;
        }
    }
    if(!cpfEncontrado) printf("PACIENTE SEM CADASTRO\n\nPRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL\n############################################################");

}

void buscaPacienteSistema(tSistema * sistema) {

    char * pacienteProcurado[MAX_NOME];

    printf("#################### BUSCAR PACIENTES #######################\n");
    printf("NOME DO PACIENTE: ");
    scanf("%[^\n]%*c", pacienteProcurado);
    printf("############################################################\n");

    printf("#################### BUSCAR PACIENTES #######################\n");
    printf("PACIENTES ENCONTRADOS:\n");

    int pacienteEncontrado = 0;

    for(int i = 0; i < sistema -> qtdPacientes; i++) {
        if(strcmp(pacienteProcurado, ObtemNomePaciente(sistema -> pacientes[i]))) {
            pacienteEncontrado = 1;
            break;
        }
    }

    if(pacienteEncontrado) {
        printf("#################### BUSCAR PACIENTES #######################\n");
        printf("PACIENTES ENCONTRADOS: \n");

        for(int i = 0; i < sistema -> qtdPacientes; i++) {
            if(strcmp(pacienteProcurado, ObtemNomePaciente(sistema -> pacientes[i]))) {
                printf("- %s (%s)\n", ObtemNomePaciente(sistema -> pacientes[i]), ObtemCPFPaciente(sistema -> pacientes[i]));
            }
        }

        printf("SELECIONE UMA OPÇÃO:\n");
        printf("    (1) ENVIAR LISTA PARA IMPRESSAO\n");
        printf("    (2) RETORNAR AO MENU PRINCIPAL\n");
        printf("############################################################\n");

        int opcao;

        scanf("%d", &opcao);
        if(opcao == 1) {

            //ENVIAR PARA A LISTA DE IMPRESSÃO!!!

            printf("#################### BUSCAR PACIENTES #######################\n");
            printf("LISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU PRINCIPAL\n");
            printf("############################################################\n");
        }
    }
    else {
        printf("#################### BUSCAR PACIENTES #######################\n");
        printf("NENHUM PACIENTE FOI ENCONTRADO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
        printf("############################################################\n");
    }
}

void relatorioGeralSistema(tSistema * sistema);

void executaFilaDeImpressao(tSistema * sistema);

void finalizaSistema(tSistema * sistema);
