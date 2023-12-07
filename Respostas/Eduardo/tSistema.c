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
            scanf("%[^\n]s", nomeUsuario);
            printf("CPF: ");
            scanf("%s", cpf);
            printf("DATA DE NASCIMENTO: ");
            scanf("%s", dataNascimento);
            printf("TELEFONE: ");
            scanf("%s", telefone);
            printf("GENERO: ");
            scanf("%s", genero);
            printf("CRM: ");
            scanf("%s", crm);
            printf("NOME DE USUARIO: ");
            scanf("%s", nomeUser);
            printf("SENHA: ");
            scanf("%s", senhaUser);

            sistema -> usuarios[(sistema -> qtdUsuarios) - 1] = cadastraUsuario(nomeUsuario, cpf, dataNascimento, telefone, 
                                                                                genero, crm, nomeUser, senhaUser, nivelUser);
            break;

        case 2:
            printf("#################### CADASTRO SECRETARIO #######################\n");
            printf("NOME COMPLETO: ");
            scanf("%[^\n]s", nomeUsuario);
            printf("CPF: ");
            scanf("%s", cpf);
            printf("DATA DE NASCIMENTO: ");
            scanf("%s", dataNascimento);
            printf("TELEFONE: ");
            scanf("%s", telefone);
            printf("GENERO: ");
            scanf("%s", genero);
            printf("NOME DE USUARIO: ");
            scanf("%s", nomeUser);
            printf("SENHA: ");
            scanf("%s", senhaUser);
            printf("NIVEL DE ACESSO: ");
            scanf("%s", nivelAcesso);
            crm[0] = '\0';

            if(nivelAcesso == "ADMIN") nivelUser = 3;
            //NÃO SEI SE ISSO FUNCIONA;

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
    scanf("%[^\n]s", nomePaciente);
    printf("CPF: ");
    scanf("%s", cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%s", dataNascimento);
    printf("TELEFONE: ");
    scanf("%s", telefone);
    printf("GENERO: ");
    scanf("%s", genero);

}

void executaConsulta(tSistema * sistema, tUsuario * usuario) {

    printf("#################### CONSULTA MEDICA #######################\n");
    printf("CPF DO PACIENTE: ");

    char * cpfConsultado[TAM_CPF];
    int cpfEncontrado = 0;
    scanf("%s", cpfConsultado);
    
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
    scanf("%[^\n]s", pacienteProcurado);
    printf("############################################################\n");

    printf("#################### BUSCAR PACIENTES #######################\n");
    printf("PACIENTES ENCONTRADOS:\n");

    int pacienteEncontrado = 0;
    for(int i = 0; i < sistema -> qtdPacientes; i++) {
        if(strcmp(pacienteProcurado, ObtemNomePaciente(sistema -> pacientes[i]))) {
            printf("- %s (%s)\n", ObtemNomePaciente(sistema -> pacientes[i]), ObtemCPFPaciente(sistema -> pacientes[i]));
            pacienteEncontrado = 1;
        }
    }

    if(pacienteEncontrado) {
        //PAREI AQUI;
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
