#include <stdio.h>
#include <stdlib.h>
#include "tSistema.h"
#include "tUsuario.h"

int main(int argc, char * argv[]) {

    char diretorioGeral[1001], binaryPath[1001], newBinaryPath[1002];

    scanf("%s%*c", binaryPath);

    if(argc <= 1) {
        printf("ERRO: o diretório de arquivos não foi informado");
        exit(1);
    }

    sprintf(diretorioGeral, "%s/saida", argv[1]);
    sprintf(newBinaryPath, "%s/%s", argv[1], binaryPath);

    tSistema * sistema = criaSistema(newBinaryPath);
    int opcao = 0;

    tUsuario * logado = fazLogin(sistema);

    while(opcao != 8) {

        printf("####################### MENU PRINCIPAL #########################\n");
        printf("ESCOLHA UMA OPCAO:\n");
        printf("\t(1) CADASTRAR SECRETARIO\n");
        printf("\t(2) CADASTRAR MEDICO\n");
        printf("\t(3) CADASTRAR PACIENTE\n");
        printf("\t(4) REALIZAR CONSULTA\n");
        printf("\t(5) BUSCAR PACIENTES\n");
        printf("\t(6) RELATORIO GERAL\n");
        printf("\t(7) FILA DE IMPRESSAO\n");
        printf("\t(8) FINALIZAR O PROGRAMA\n");
        printf("###############################################################\n");

        scanf("%d%*c", &opcao);

        switch (opcao) {

            case 1:
                adicionaPessoaSistema(sistema, 2);
                break;

            case 2:
                adicionaPessoaSistema(sistema, 1);
                break;

            case 3:
                adicionaPessoaSistema(sistema, 0);
                break;

            case 4:
                executaConsulta(sistema, logado);
                break;

            case 5:
                buscaPacienteSistema(sistema);
                break;

            case 6:
                relatorioGeralSistema(sistema);
                break;

            case 7:
                executaFilaDeImpressao(sistema, diretorioGeral);
                break;

        }
    }

    finalizaSistema(sistema, newBinaryPath);

return 0;
}