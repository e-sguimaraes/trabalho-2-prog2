#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tPaciente.h"
#include "limites.h"
#include "tReceita.h"
#include "tUsuario.h"
#include "tBiopsia.h"
#include "tEncaminhamento.h"

typedef struct tPaciente {
    char * nomePaciente[MAX_NOME];
    char * cpf[TAM_CPF];
    char * dataNascimento[TAM_DATA];
    char * telefone[TAM_TEL];
    char * genero[TAM_GEN];
    int diabetico;
    int fumante;
    int alergiaMedicamento;
    int historicoCancer;
    int tipoPele;
    tLesao ** lesoes;
    int qtdLesoes;
};


tPaciente * cadastraPaciente(char *nomePaciente, char * cpfPaciente, char * dataNascimento,
                      char * telefone, char * genero) {
    
    tPaciente * paciente = (tPaciente *) malloc(sizeof(tPaciente));

    strcpy(paciente -> nomePaciente, nomePaciente);
    strcpy(paciente -> cpf, cpfPaciente);
    strcpy(paciente -> dataNascimento, dataNascimento);
    strcpy(paciente -> telefone, telefone);
    strcpy(paciente -> genero, genero);
    paciente -> diabetico = 0;
    paciente -> fumante = 0;
    paciente -> alergiaMedicamento = 0;
    paciente -> historicoCancer = 0;
    paciente -> tipoPele = 0;
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

void AlteraTipoDePelePaciente(tPaciente * paciente, int valor) {
    paciente -> tipoPele = valor;
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


void consultaPaciente(tPaciente * paciente, tUsuario * usuario) {

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
    scanf("%s", dataConsulta);
    printf("POSSUI DIABETES: ");
    scanf("%d", diabetes);
    printf("FUMANTE: ");
    scanf("%d", fumante);
    printf("ALEGIA A MEDICAMENTO: ");
    scanf("%d", alergia);
    printf("HISTORICO DE CANCER: ");
    scanf("%d", historicoDeCancer);
    printf("TIPO DE PELE: ");
    scanf("%d", tipoPele);

    AlteraDiabetePaciente(paciente, diabetes);
    AlteraFumantePaciente(paciente, diabetes);
    AlteraAlergiaMedicamento(paciente, diabetes);
    AlteraHistoricoDeCancerPaciente(paciente, diabetes);
    AlteraTipoDePelePaciente(paciente, diabetes);

    int opcao;

    while(opcao != 5) {
        printf("#################### CONSULTA MEDICA #######################");
        printf("ESCOLHA UMA OPCAO:\n");
        printf("(1) CADASTRAR LESAO\n");
        printf("(2) GERAR RECEITA MEDICA\n");
        printf("(3) SOLICITACAO DE BIOPSIA\n");
        printf("(4) ENCAMINHAMENTO\n");
        printf("(5) ENCERRAR CONSULTA\n");
        printf("############################################################\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:

                paciente -> qtdLesoes++;
                adicionaLesao(paciente -> lesoes, paciente -> qtdLesoes);

                break;

            case 2:

                eTipoUso tipoUso;
                char * nomeMedicamento[MAX_TAM_NOME_MEDICAMENTO];
                char * tipoMedicamento[MAX_TAM_TIPO_MEDICAMENTO];
                int * qtdMedicamento;
                char * instrucoes[MAX_TAM_INSTRUCOES];

                printf("RECEITA MEDICA:\n");
                printf("TIPO DE USO: ");
                scanf("%s", &tipoUso);
                //PODE ISSO???;
                printf("NOME DO MEDICAMENTO: ");
                scanf("%s", nomeMedicamento);
                printf("TIPO DE MEDICAMENTO: ");
                scanf("%s", tipoMedicamento);
                printf("QUANTIDADE: ");
                scanf("%d", &qtdMedicamento);
                printf("INSTRUÇÕES DE USO: ");
                scanf("%[^\n]s", instrucoes);

                //ISSO TEM QUE SER REVISTO PARA O CASO DE CONSULTA REALIZADA POR SECRETÁRIO;
                criaReceita(paciente -> nomePaciente, tipoUso, nomeMedicamento, tipoMedicamento, instrucoes, 
                            qtdMedicamento, ObtemNomeUsuario(usuario), ObtemCRMUsuario(usuario), dataConsulta); 

                printf("RECEITA ENVIADA PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                printf("############################################################\n");

                break;

            case 3: 
                
                int precisaDeCirurgia = 0;

                for(int i = 0; i < paciente -> qtdLesoes; i++) {
                    if(NecessitaCirurgiaLesao(paciente -> lesoes[i])) {
                        criaBiopsia(paciente -> nomePaciente, paciente -> cpf, paciente -> lesoes, paciente -> qtdLesoes, 
                            ObtemNomeUsuario(usuario), ObtemCRMUsuario(usuario), dataConsulta);
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

                break;

            case 4:

                char * especialidade[MAX_TAM_ESPECIALIDADE];
                char * motivo[MAX_TAM_MOTIVO];

                printf("#################### CONSULTA MEDICA #######################\n");
                printf("ENCAMINHAMENTO:\n");
                printf("ESPECIALIDADE ENCAMINHADA: ");
                scanf("%[^\n]s", especialidade);
                printf("MOTIVO: ");
                scanf("%[^\n]s", motivo);

                criaEncaminhamento(paciente -> nomePaciente, paciente -> cpf, ObtemNomeUsuario(usuario), 
                                   especialidade, motivo, ObtemCRMUsuario(usuario), dataConsulta);

                printf("ENCAMINHAMENTO ENVIADO PARA FILA DE IMPRESSAO. PRESSIONE QUALQUER TECLA PARA RETORNAR AO MENU ANTERIOR\n");
                printf("############################################################");

                break;
                
        }
    }
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