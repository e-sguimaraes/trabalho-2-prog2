#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tSistema.h"
#include "tUsuario.h"
#include "tPaciente.h"
#include "tFila.h"
#include "tRelatorio.h"
#include "tReceita.h"
#include "tBiopsia.h"
#include "tEncaminhamento.h"
#include "tListaBusca.h"

#define DIA_ATUAL 9
#define MES_ATUAL 11
#define ANO_ATUAL 2023

struct tSistema {
    tUsuario ** usuarios;
    tPaciente ** pacientes;
    tFila * fila;
    int qtdUsuarios;
    int qtdPacientes;
    int qtdAtendidos;
};


tSistema * criaSistema() {

    tSistema * sistema = (tSistema *) malloc(sizeof(tSistema));
    
    sistema -> usuarios = (tUsuario **) malloc(sizeof(tUsuario *));

    sistema -> pacientes = (tPaciente **) malloc(sizeof(tPaciente *));

    sistema -> fila = criaFila();

    sistema -> qtdUsuarios = 0;
    sistema -> qtdPacientes = 0;
    sistema -> qtdAtendidos = 0;

    adicionaUsuarioSistema(sistema, 2); 
    
}

void adicionaUsuarioSistema(tSistema * sistema, int nivelUser) {

    sistema -> qtdUsuarios++;
    if(sistema -> qtdUsuarios > 1) sistema -> usuarios = (tUsuario **) realloc(sistema -> usuarios, sistema -> qtdUsuarios * sizeof(tUsuario *));

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

    scanf("%*c");

}

void adicionaPaciente(tSistema * sistema) {

    sistema -> qtdPacientes++;
    if(sistema -> qtdPacientes > 1) sistema -> pacientes = (tPaciente **) realloc(sistema -> pacientes, sistema -> qtdPacientes * sizeof(tPaciente *));

    char * nomePaciente[MAX_NOME];
    char * cpf[TAM_CPF];
    char * dataNascimento[TAM_DATA];
    char * telefone[TAM_TEL];
    char * genero[TAM_GEN];
    int dia, mes, ano, idade = 0;

    printf("#################### CADASTRO PACIENTE #######################\n");
    printf("NOME COMPLETO: ");
    scanf("%[^\n]%*c", nomePaciente);
    printf("CPF: ");
    scanf("%s%*c", cpf);
    printf("DATA DE NASCIMENTO: ");
    scanf("%d/%d/%d%*c", &dia, &mes, &ano);
    printf("TELEFONE: ");
    scanf("%s%*c", telefone);
    printf("GENERO: ");
    scanf("%s%*c", genero);

    fprintf(dataNascimento, "%02d/%02d/%04d", dia, mes, ano);

    if((dia <= DIA_ATUAL && mes == MES_ATUAL) || (mes < MES_ATUAL)) {
        idade = ANO_ATUAL - ano;
    }
    else {
        idade = ANO_ATUAL - ano - 1;
    }

    sistema -> pacientes[(sistema -> qtdPacientes) - 1] = cadastraPaciente(nomePaciente, cpf, dataNascimento, telefone, genero, idade);

    printf("#############################################################\n");

}

void executaConsulta(tSistema * sistema, tUsuario * usuario) {

    printf("#################### CONSULTA MEDICA #######################\n");
    printf("CPF DO PACIENTE: ");

    char * cpfConsultado[TAM_CPF];
    int cpfEncontrado = 0;
    scanf("%s%*c", cpfConsultado);
    
    for(int i = 0; i < sistema -> qtdPacientes; i++) {
        if(strcmp(cpfConsultado, sistema -> pacientes[i])) {
            consultaPaciente(sistema -> fila, sistema -> pacientes[i], ObtemNomeUsuario(usuario), ObtemCRMUsuario(usuario), ObtemNivelUser(usuario));
            sistema -> qtdAtendidos++;
            cpfEncontrado = 1;
        }
    }
    if(!cpfEncontrado) printf("PACIENTE SEM CADASTRO\n\nPRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL\n############################################################");

    scanf("%*c");

}

void buscaPacienteSistema(tSistema * sistema) {

    char * pacienteProcurado[MAX_NOME];

    printf("#################### BUSCAR PACIENTES #######################\n");
    printf("NOME DO PACIENTE: ");
    scanf("%[^\n]%*c", pacienteProcurado);
    printf("############################################################\n");

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

        tListaBusca * lista = criaListaBusca(sistema -> pacientes, sistema -> qtdPacientes, pacienteProcurado);

        imprimeNaTelaListaBusca(lista);

        printf("SELECIONE UMA OPÇÃO:\n");
        printf("\t(1) ENVIAR LISTA PARA IMPRESSAO\n");
        printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
        printf("############################################################\n");

        int opcao;

        scanf("%d", &opcao);
        if(opcao == 1) {

            insereDocumentoFila(sistema -> fila, lista, imprimeNaTelaListaBusca, imprimeEmArquivoListaBusca, desalocaListaBusca);

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

    scanf("%*c");

}


void relatorioGeralSistema(tSistema * sistema) {

    int idadeMedia = 0, f = 0, m = 0, o = 0, tamMedioLesoes = 0, nLesoes = 0, cirurgiaLesoes = 0, crioterapiaLesoes = 0;

    for(int i = 0; i < sistema -> qtdPacientes; i++) {
        if(ObtemGeneroPaciente(sistema -> pacientes[i])[0] = "F") f++;
        if(ObtemGeneroPaciente(sistema -> pacientes[i])[0] = "M") m++;
        if(ObtemGeneroPaciente(sistema -> pacientes[i])[0] = "O") o++;

        nLesoes += ObtemQuantidadeLesoesPaciente(sistema -> pacientes[i]);
    
        for(int j = 0; j < ObtemQuantidadeLesoesPaciente(sistema -> pacientes[i]); j++) {
            tamMedioLesoes += ObtemTamanhoLesaoPaciente(sistema -> pacientes[i], j);
            
        }

        idadeMedia += ObtemIdadePaciente(sistema -> pacientes[i]);
        cirurgiaLesoes += ObtemQtdLesoesCirurgia(sistema -> pacientes[i]);
        crioterapiaLesoes += ObtemQtdLesoesCrioterapia(sistema -> pacientes[i]);
    }

    idadeMedia /= sistema -> qtdAtendidos;
    tamMedioLesoes /= nLesoes;


    tRelatorio * relatorio = criaRelatorio(sistema -> qtdAtendidos, idadeMedia, f, m, o, tamMedioLesoes, nLesoes, cirurgiaLesoes, crioterapiaLesoes);

    imprimeNaTelaRelatorio(relatorio);

    printf("SELECIONE UMA OPÇÃO:\n");
    printf("\t(1) ENVIAR PARA IMPRESSAO\n");
    printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
    printf("############################################################\n");

    int opcao;
    scanf("%d", &opcao);

    if(opcao == 1) {
        insereDocumentoFila(sistema -> fila, relatorio, imprimeNaTelaRelatorio, imprimeEmArquivoRelatorio, desalocaRelatorio);

        printf("#################### RELATORIO GERAL #######################\n");
        printf("RELATÓRIO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
        printf("############################################################\n");

        scanf("%*c");
    }

}

void executaFilaDeImpressao(tSistema * sistema, char * path) {
    imprimeFila(sistema -> fila, path);
}


void finalizaSistema(tSistema * sistema) {

    for(int i = 0; i < sistema -> qtdUsuarios; i++) {
        desalocaUsuario(sistema -> usuarios[i]);
    }

    for(int i = 0; i < sistema -> qtdPacientes; i++) {
        desalocaPaciente(sistema -> pacientes[i]);
    }

    desalocaFila(sistema -> fila);

    free(sistema);
}

tUsuario * fazLogin(tSistema * sistema) {

    char nome[20];
    char senha[20];
    int usuarioEncontrado = 0;

    while(1) {
        scanf("%s", nome);
        scanf("%s", senha);
        
        for(int i = 0; i < sistema -> qtdUsuarios; i++) {
            if(strcmp(nome, ObtemNomeUser(sistema -> usuarios[i])) && strcmp(senha, ObtemSenhaUser(sistema -> usuarios[i]))) {
                printf("USUARIO LOGADO COM SUCESSO\n");
                return sistema -> usuarios[i];
            }
        }

        printf("USUÁRIO OU SENHA INCORRETA\n");
    }
}


int obtemAtendidosSistema(tSistema * sistema) {
return sistema -> qtdAtendidos;
}


int obtemQtdPacientes(tSistema * sistema) {
return sistema -> qtdPacientes;
}


tPaciente * obtemPaciente(tSistema * sistema, int indice) {
return sistema -> pacientes[indice];
}

void consultaPaciente(tFila * fila, tPaciente * paciente, char * nomeUsuario, char * crm, int nivelUser) {

    char conserta = nomeUsuario[0];

    if(nivelUser = 3) nomeUsuario[0] = '\0';

    printf("---\n");
    printf("- NOME: %s\n", ObtemNomePaciente(paciente));
    printf("- DATA DE NASCIMENTO: %s\n", ObtemNascimentoPaciente(paciente));
    printf("---\n");

    char * dataConsulta;
    int diabetes;
    int fumante;
    int alergia;
    int historicoDeCancer;
    int tipoPele;

    printf("DATA DA CONSULTA: ");
    scanf("%s%*c", dataConsulta);
    printf("POSSUI DIABETES: ");
    scanf("%d%*c", diabetes);
    printf("FUMANTE: ");
    scanf("%d%*c", fumante);
    printf("ALEGIA A MEDICAMENTO: ");
    scanf("%d%*c", alergia);
    printf("HISTORICO DE CANCER: ");
    scanf("%d%*c", historicoDeCancer);
    printf("TIPO DE PELE: ");
    scanf("%d%*c", tipoPele);

    AlteraDiabetePaciente(paciente, diabetes);
    AlteraFumantePaciente(paciente, diabetes);
    AlteraAlergiaMedicamento(paciente, diabetes);
    AlteraHistoricoDeCancerPaciente(paciente, diabetes);
    AlteraTipoDePelePaciente(paciente, diabetes);

    int opcao;

    while(opcao != 5) {
        printf("#################### CONSULTA MEDICA #######################");
        printf("ESCOLHA UMA OPCAO:\n");
        printf("\t(1) CADASTRAR LESAO\n");
        printf("\t(2) GERAR RECEITA MEDICA\n");
        printf("\t(3) SOLICITACAO DE BIOPSIA\n");
        printf("\t(4) ENCAMINHAMENTO\n");
        printf("\t(5) ENCERRAR CONSULTA\n");
        printf("############################################################\n");

        scanf("%d%*c", &opcao);

        switch (opcao) {
            case 1:

                adicionaLesaoPaciente(paciente);

                break;

            case 2:

                char * tipoUso[10];
                char * nomeMedicamento[MAX_TAM_NOME_MEDICAMENTO];
                char * tipoMedicamento[MAX_TAM_TIPO_MEDICAMENTO];
                int * qtdMedicamento;
                char * instrucoes[MAX_TAM_INSTRUCOES];

                printf("RECEITA MEDICA:\n");
                printf("TIPO DE USO: ");
                scanf("%s%*c", tipoUso);
                printf("NOME DO MEDICAMENTO: ");
                scanf("%s%*c", nomeMedicamento);
                printf("TIPO DE MEDICAMENTO: ");
                scanf("%s%*c", tipoMedicamento);
                printf("QUANTIDADE: ");
                scanf("%d%*c", &qtdMedicamento);
                printf("INSTRUÇÕES DE USO: ");
                scanf("%[^\n]%*c", instrucoes);

                int tipoUsoInt;
                if(tipoUso[0] == 'O') tipoUsoInt = 0;

                tReceita * receita = criaReceita(ObtemNomePaciente(paciente), tipoUsoInt, nomeMedicamento, tipoMedicamento, instrucoes, 
                                                 qtdMedicamento, nomeUsuario, crm, dataConsulta); 

                insereDocumentoFila(fila, receita, imprimeNaTelaReceita, imprimeEmArquivoReceita, desalocaReceita);

                printf("RECEITA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                printf("############################################################\n");

                scanf("%*c");

                break;

            case 3: 
                
                int precisaDeCirurgia = 0;

                for(int i = 0; i < ObtemQuantidadeLesoesPaciente(paciente); i++) {
                    if(NecessitaCirurgiaLesao(ObtemLesoesPaciente(paciente)[i])) {
                        tBiopsia * biopsia = criaBiopsia(ObtemNomePaciente(paciente), ObtemCPFPaciente(paciente), ObtemLesoesPaciente(paciente), 
                                    ObtemQuantidadeLesoesPaciente(paciente), nomeUsuario, crm, dataConsulta);

                        insereDocumentoFila(fila, biopsia, imprimeNaTelaBiopsia, imprimeEmArquivoBiopsia, desalocaBiopsia);

                        precisaDeCirurgia = 1;
                        break;
                    }
                }

                if(precisaDeCirurgia) {
                    printf("#################### CONSULTA MEDICA #######################\n");
                    printf("SOLICITACAO DE BIOPSIA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                    printf("############################################################\n");
                }
                else {
                    printf("#################### CONSULTA MEDICA #######################\n");
                    printf("NAO E POSSIVEL SOLICITAR BIOPSIA SEM LESAO CIRURGICA. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                    printf("############################################################\n");
                }

                scanf("%*c");

                break;

            case 4:

                char * especialidade[MAX_TAM_ESPECIALIDADE];
                char * motivo[MAX_TAM_MOTIVO];

                printf("#################### CONSULTA MEDICA #######################\n");
                printf("ENCAMINHAMENTO:\n");
                printf("ESPECIALIDADE ENCAMINHADA: ");
                scanf("%[^\n]%*c", especialidade);
                printf("MOTIVO: ");
                scanf("%[^\n]%*c", motivo);

                tEncaminhamento * encaminhamento = criaEncaminhamento(ObtemNomePaciente(paciente), ObtemCPFPaciente(paciente), nomeUsuario, 
                                                                      especialidade, motivo, crm, dataConsulta);

                insereDocumentoFila(fila, encaminhamento, imprimeNaTelaEncaminhamento, imprimeEmArquivoEncaminhamento, desalocaEncaminhamento);

                printf("ENCAMINHAMENTO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                printf("############################################################");

                scanf("%*c");

                break;
                
        }
    }

    nomeUsuario[0] = conserta;
    
}
