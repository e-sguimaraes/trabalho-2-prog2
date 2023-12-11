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
    tLesao ** lesoes;
    int qtdUsuarios;
    int qtdPacientes;
    int qtdLesoes;
    tFila * fila;
};


tSistema * criaSistema(char * binaryPath) {

    tSistema * sistema = (tSistema *) malloc(sizeof(tSistema));

    sistema -> usuarios = (tUsuario **) calloc(1, sizeof(tUsuario *));

    sistema -> pacientes = (tPaciente **) calloc(1, sizeof(tPaciente *));

    sistema -> lesoes = (tLesao **) calloc(1, sizeof(tLesao *));

    sistema -> fila = criaFila();

    //Lendo as lesões do arquivo binário;
    char binaryLesoes[1003];
    sprintf(binaryLesoes, "%s/lesoes.bin", binaryPath);

    FILE * bLesoes = NULL;
    bLesoes = fopen(binaryLesoes, "rb");
    if(bLesoes != NULL) {
        fread(&sistema -> qtdLesoes, sizeof(int), 1, bLesoes);
        printf("%d\n", sistema -> qtdLesoes);
        sistema -> lesoes = (tLesao **) realloc(sistema -> lesoes, sistema -> qtdLesoes * sizeof(tLesao *));

        for(int i = 0; i < sistema -> qtdLesoes; i++) {
            sistema -> lesoes[i] = recuperaLesao(bLesoes);
        }

        fclose(bLesoes);
    }
    else {
            sistema -> qtdLesoes = 0;
    }

    //Lendo os pacientes do arquivo binário;
    char binaryPacientes[1003];
    sprintf(binaryPacientes, "%s/pacientes.bin", binaryPath);

    FILE * bPacientes = NULL;
    bPacientes = fopen(binaryPacientes, "rb");
    if(bPacientes != NULL) {
        fread(&sistema -> qtdPacientes, sizeof(int), 1, bPacientes);
        sistema -> pacientes = (tPaciente **) realloc(sistema -> pacientes, sistema -> qtdPacientes * sizeof(tPaciente *));

        for(int i = 0; i < sistema -> qtdPacientes; i++) {
            sistema -> pacientes[i] = recuperaPaciente(bPacientes);
        }

        fclose(bPacientes);
    }
    else {
            sistema -> qtdPacientes = 0;
    }

    //Lendo os usuários do arquivo binário;
    char binaryUsuarios[1003];
    sprintf(binaryUsuarios, "%s/usuarios.bin", binaryPath);

    FILE * bUsuarios = NULL;
    bUsuarios = fopen(binaryUsuarios, "rb");
    if(bUsuarios != NULL) {
        fread(&sistema -> qtdUsuarios, sizeof(int), 1, bUsuarios);
        sistema -> usuarios = (tUsuario **) realloc(sistema -> usuarios, sistema -> qtdUsuarios * sizeof(tUsuario *));

        for(int i = 0; i < sistema -> qtdUsuarios; i++) {
            sistema -> usuarios[i] = recuperaUsuario(bUsuarios);
        }

        fclose(bUsuarios);
    }
    else {
            sistema -> qtdUsuarios = 0;
            adicionaPessoaSistema(sistema, 2); 
    }
    
return sistema;
}

void consultaPaciente(tFila * fila, tPaciente * paciente, char * nomeUsuario, char * crm, int nivelUser) {

    printf("---\n");
    printf("- NOME: %s\n", ObtemNomePaciente(paciente));
    printf("- DATA DE NASCIMENTO: %s\n", ObtemNascimentoPaciente(paciente));
    printf("---\n");

    char dataConsulta[TAM_DATA];
    int dia, mes, ano;
    int diabetes;
    int fumante;
    int alergia;
    int historicoDeCancer;
    char tipoPele[3];

    printf("DATA DA CONSULTA: ");
    scanf("%d/%d/%d%*c", &dia, &mes, &ano);
    printf("POSSUI DIABETES: ");
    scanf("%d%*c", &diabetes);
    printf("FUMANTE: ");
    scanf("%d%*c", &fumante);
    printf("ALEGIA A MEDICAMENTO: ");
    scanf("%d%*c", &alergia);
    printf("HISTORICO DE CANCER: ");
    scanf("%d%*c", &historicoDeCancer);
    printf("TIPO DE PELE: ");
    scanf("%[^\n]%*c", tipoPele);

    sprintf(dataConsulta, "%d/%d/%d", dia, mes, ano);

    AlteraDiabetePaciente(paciente, diabetes);
    AlteraFumantePaciente(paciente, fumante);
    AlteraAlergiaMedicamento(paciente, alergia);
    AlteraHistoricoDeCancerPaciente(paciente, historicoDeCancer);
    AlteraTipoDePelePaciente(paciente, tipoPele);

    int opcao = 0;

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

                char tipoUso[10];
                char nomeMedicamento[MAX_TAM_NOME_MEDICAMENTO];
                char tipoMedicamento[MAX_TAM_TIPO_MEDICAMENTO];
                int qtdMedicamento;
                char instrucoes[MAX_TAM_INSTRUCOES];

                printf("RECEITA MEDICA:\n");
                printf("TIPO DE USO: ");
                scanf("%s%*c", tipoUso);
                printf("NOME DO MEDICAMENTO: ");
                scanf("%[^\n]%*c", nomeMedicamento);
                printf("TIPO DE MEDICAMENTO: ");
                scanf("%s%*c", tipoMedicamento);
                printf("QUANTIDADE: ");
                scanf("%d%*c", &qtdMedicamento);
                printf("INSTRUÇÕES DE USO: ");
                scanf("%[^\n]%*c", instrucoes);

                eTipoUso tipoUsoInt;
                if(tipoUso[0] == 'O') tipoUsoInt = 0;
                if(tipoUso[0] == 'T') tipoUsoInt = 1;

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

                char especialidade[MAX_TAM_ESPECIALIDADE];
                char motivo[MAX_TAM_MOTIVO];

                printf("#################### CONSULTA MEDICA #######################\n");
                printf("ENCAMINHAMENTO:\n");
                printf("ESPECIALIDADE ENCAMINHADA: ");
                scanf("%[^\n]%*c", especialidade);
                printf("MOTIVO: ");
                scanf("%[^\n]%*c", motivo);

                tEncaminhamento * encaminhamento = criaEncaminhamento(ObtemNomePaciente(paciente), ObtemCPFPaciente(paciente), especialidade, 
                                                                      motivo, nomeUsuario, crm, dataConsulta);

                insereDocumentoFila(fila, encaminhamento, imprimeNaTelaEncaminhamento, imprimeEmArquivoEncaminhamento, desalocaEncaminhamento);

                printf("ENCAMINHAMENTO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                printf("############################################################");

                scanf("%*c");

                break;
                
        }
    }

    foiAtendidoPaciente(paciente);
    
}

void adicionaPessoaSistema(tSistema * sistema, int nivelUser) {

    char nomeUsuario[MAX_NOME];
    char nomePaciente[MAX_NOME];
    char cpf[TAM_CPF];
    char dataNascimento[TAM_DATA];
    char telefone[TAM_TEL];
    char genero[TAM_GEN];
    char crm[TAM_CRM];
    char nomeUser[MAX_USER];
    char senhaUser[MAX_USER];
    int dia, mes, ano, idade = 0;

    char nivelAcesso[6];

    switch (nivelUser) {

        case 0:

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

            sprintf(dataNascimento, "%d/%d/%d", dia, mes, ano);

            if((dia <= DIA_ATUAL && mes == MES_ATUAL) || (mes < MES_ATUAL)) {
                idade = ANO_ATUAL - ano;
            }
            else {
                idade = ANO_ATUAL - ano - 1;
            }

            for(int i = 0; i < sistema -> qtdPacientes; i++) {
                if(!strcmp(ObtemCPFPaciente(sistema -> pacientes[i]), cpf)) {
                    printf("CPF JÁ CADASTRADO FILHO DA PUTA\n");
                    return;
                }
            }

            sistema -> qtdPacientes++;
            if(sistema -> qtdPacientes > 1) sistema -> pacientes = (tPaciente **) realloc(sistema -> pacientes, sistema -> qtdPacientes * sizeof(tPaciente *));
            sistema -> pacientes[(sistema -> qtdPacientes) - 1] = cadastraPaciente(nomePaciente, cpf, dataNascimento, telefone, genero, idade);
            break;

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

            for(int i = 0; i < sistema -> qtdUsuarios; i++) {
                if(!strcmp(ObtemCPFUsuario(sistema -> usuarios[i]), cpf)) {
                    printf("CPF JÁ CADASTRADO FILHO DA PUTA\n");
                    return;
                }
            }

            sistema -> qtdUsuarios++;
            if(sistema -> qtdUsuarios > 1) sistema -> usuarios = (tUsuario **) realloc(sistema -> usuarios, sistema -> qtdUsuarios * sizeof(tUsuario *));
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

            for(int i = 0; i < sistema -> qtdUsuarios; i++) {
                if(!strcmp(ObtemCPFUsuario(sistema -> usuarios[i]), cpf)) {
                    printf("CPF JÁ CADASTRADO FILHO DA PUTA\n");
                    return;
                }
            }

            if(nivelAcesso[0] == 'A') nivelUser = 3;

            nomeUsuario[0] = '\0';

            sistema -> qtdUsuarios++;
            if(sistema -> qtdUsuarios > 1) sistema -> usuarios = (tUsuario **) realloc(sistema -> usuarios, sistema -> qtdUsuarios * sizeof(tUsuario *));
            sistema -> usuarios[(sistema -> qtdUsuarios) - 1] = cadastraUsuario(nomeUsuario, cpf, dataNascimento, telefone, 
                                                                                genero, crm, nomeUser, senhaUser, nivelUser);

            if(sistema -> qtdUsuarios == 1) return;

            break;


    }
    printf("CADASTRO REALIZADO COM SUCESSO. PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU INICIAL\n");
    printf("############################################################\n");

    scanf("%*c");

}

void executaConsulta(tSistema * sistema, tUsuario * usuario) {

    printf("#################### CONSULTA MEDICA #######################\n");
    printf("CPF DO PACIENTE: ");

    char cpfConsultado[TAM_CPF];
    int cpfEncontrado = 0;
    scanf("%s%*c", cpfConsultado);
    
    for(int i = 0; i < sistema -> qtdPacientes; i++) {
        if(!strcmp(cpfConsultado, ObtemCPFPaciente(sistema -> pacientes[i]))) {
            consultaPaciente(sistema -> fila, sistema -> pacientes[i], ObtemNomeUsuario(usuario), ObtemCRMUsuario(usuario), ObtemNivelUser(usuario));
            cpfEncontrado = 1;
        }
    }
    if(!cpfEncontrado) {
        printf("PACIENTE SEM CADASTRO PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL\n");
        printf("############################################################\n");
        scanf("%*c");
    }


}

void buscaPacienteSistema(tSistema * sistema) {

    char pacienteProcurado[MAX_NOME];

    printf("#################### BUSCAR PACIENTES #######################\n");
    printf("NOME DO PACIENTE: ");
    scanf("%[^\n]%*c", pacienteProcurado);
    printf("############################################################\n");

    int pacienteEncontrado = 0;

    for(int i = 0; i < sistema -> qtdPacientes; i++) {
        if(!strcmp(pacienteProcurado, ObtemNomePaciente(sistema -> pacientes[i]))) {
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

        scanf("%d%*c", &opcao);
        if(opcao == 1) {

            insereDocumentoFila(sistema -> fila, lista, imprimeNaTelaListaBusca, imprimeEmArquivoListaBusca, desalocaListaBusca);

            printf("#################### BUSCAR PACIENTES #######################\n");
            printf("LISTA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU PRINCIPAL\n");
            printf("############################################################\n");
        }
        else {
            return;
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

    int idadeMedia = 0, f = 0, m = 0, o = 0, tamMedioLesoes = 0, nLesoes = sistema -> qtdLesoes, cirurgiaLesoes = 0, crioterapiaLesoes = 0, qtdAtendidos = 0;

    for(int i = 0; i < sistema -> qtdLesoes; i++) {
        cirurgiaLesoes += NecessitaCirurgiaLesao(sistema -> lesoes[i]);
        crioterapiaLesoes += NecessitaCrioterapiaLesao(sistema -> lesoes[i]);
        tamMedioLesoes += ObtemTamanhoLesao(sistema -> lesoes[i]);
    }

    for(int i = 0; i < sistema -> qtdPacientes; i++) {
        if(ObtemGeneroPaciente(sistema -> pacientes[i])[0] == 'F') f++;
        if(ObtemGeneroPaciente(sistema -> pacientes[i])[0] == 'M') m++;
        if(ObtemGeneroPaciente(sistema -> pacientes[i])[0] == 'O') o++;
        if(ObtemAtendidoPaciente(sistema -> pacientes[i])) qtdAtendidos++;

        nLesoes += ObtemQuantidadeLesoesPaciente(sistema -> pacientes[i]);
    
        for(int j = 0; j < ObtemQuantidadeLesoesPaciente(sistema -> pacientes[i]); j++) {
            tamMedioLesoes += ObtemTamanhoLesaoPaciente(sistema -> pacientes[i], j);
            
        }

        idadeMedia += ObtemIdadePaciente(sistema -> pacientes[i]);
        cirurgiaLesoes += ObtemQtdLesoesCirurgia(sistema -> pacientes[i]);
        crioterapiaLesoes += ObtemQtdLesoesCrioterapia(sistema -> pacientes[i]);
    }

    if(!nLesoes) nLesoes = 1;

    idadeMedia /= sistema -> qtdPacientes;
    tamMedioLesoes /= nLesoes;


    tRelatorio * relatorio = criaRelatorio(qtdAtendidos, idadeMedia, f, m, o, tamMedioLesoes, nLesoes, cirurgiaLesoes, crioterapiaLesoes);

    imprimeNaTelaRelatorio(relatorio);

    printf("SELECIONE UMA OPÇÃO:\n");
    printf("\t(1) ENVIAR PARA IMPRESSAO\n");
    printf("\t(2) RETORNAR AO MENU PRINCIPAL\n");
    printf("############################################################\n");

    int opcao;
    scanf("%d%*c", &opcao);

    if(opcao == 1) {
        insereDocumentoFila(sistema -> fila, relatorio, imprimeNaTelaRelatorio, imprimeEmArquivoRelatorio, desalocaRelatorio);

        printf("#################### RELATORIO GERAL #######################\n");
        printf("RELATÓRIO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
        printf("############################################################\n");

        scanf("%*c");
    }

}

void executaFilaDeImpressao(tSistema * sistema, char * path) {
    printf("################### FILA DE IMPRESSAO MEDICA #####################\n");
    printf("ESCOLHA UMA OPCAO: \n");
    printf("\t(1) EXECUTAR FILA DE IMPRESSAO\n");
    printf("\t(2) RETORNAR AO MENU ANTERIOR\n");
    printf("############################################################\n");
    
    int opcao = 0;
    scanf("%d%*c", &opcao);
    if(opcao == 1) imprimeFila(sistema -> fila, path);

}


void finalizaSistema(tSistema * sistema, char * binaryPath) {

    char binaryPacientes[1002], binaryUsuarios[1002], binaryLesoes[1002];

    sprintf(binaryLesoes, "%s/lesoes.bin", binaryPath);
    FILE * bLesoes = NULL;
    bLesoes = fopen(binaryLesoes, "wb");

    int qtdAntigaLesoes = sistema -> qtdLesoes;

    for(int i = 0; i < sistema -> qtdPacientes; i++) {
        sistema -> qtdLesoes += ObtemQuantidadeLesoesPaciente(sistema -> pacientes[i]);
    }
    fwrite(&sistema -> qtdLesoes, sizeof(int), 1, bLesoes);

    salvaBinarioLesoes(sistema -> lesoes, qtdAntigaLesoes, bLesoes);
    desalocaLesao(sistema -> lesoes, qtdAntigaLesoes);

    for(int i = 0; i < sistema -> qtdPacientes; i++) {
        salvaBinarioLesoes(ObtemLesoesPaciente(sistema -> pacientes[i]), ObtemQuantidadeLesoesPaciente(sistema -> pacientes[i]), bLesoes);
    }

    fclose(bLesoes);

    sprintf(binaryUsuarios, "%s/usuarios.bin", binaryPath);
    FILE * bUsuarios = NULL;
    bUsuarios = fopen(binaryUsuarios, "wb");

    fwrite(&sistema -> qtdUsuarios, sizeof(int), 1, bUsuarios);

    for(int i = 0; i < sistema -> qtdUsuarios; i++) {
        salvaBinarioUsuario(sistema -> usuarios[i], bUsuarios);
        desalocaUsuario(sistema -> usuarios[i]);
    }
    fclose(bUsuarios);
    free(sistema -> usuarios);

    sprintf(binaryPacientes, "%s/pacientes.bin", binaryPath);
    FILE * bPacientes = NULL;
    bPacientes = fopen(binaryPacientes, "wb");

    fwrite(&sistema -> qtdPacientes, sizeof(int), 1, bPacientes);

    for(int i = 0; i < sistema -> qtdPacientes; i++) {
        salvaBinarioPaciente(sistema -> pacientes[i], bPacientes);
        desalocaPaciente(sistema -> pacientes[i]);
    }
    fclose(bPacientes);
    free(sistema -> pacientes);

    desalocaFila(sistema -> fila);

    free(sistema);
}

tUsuario * fazLogin(tSistema * sistema) {

    char nome[20];
    char senha[20];

    while(1) {
        scanf("%s%*c", nome);
        scanf("%s%*c", senha);

        for(int i = 0; i < sistema -> qtdUsuarios; i++) {
            if(!strcmp(nome, ObtemNomeUser(sistema -> usuarios[i])) && !strcmp(senha, ObtemSenhaUser(sistema -> usuarios[i]))) {
                printf("USUARIO LOGADO COM SUCESSO\n");
                return sistema -> usuarios[i];
            }
        }

        printf("USUÁRIO OU SENHA INCORRETA\n");
    }
}


int obtemQtdPacientes(tSistema * sistema) {
return sistema -> qtdPacientes;
}


tPaciente * obtemPaciente(tSistema * sistema, int indice) {
return sistema -> pacientes[indice];
}
