#include <stdlib.h>
#include <stdio.h>
#include "tDocumento.h"

typedef struct {
    int qtdItens;
    tDocumento ** documentos;
} tFila;


tFila *criaFila() {

    tFila * fila = (tFila *) malloc(sizeof(tFila));

    fila -> qtdItens = 0;
    fila -> documentos = NULL;

return fila;
}


void desalocaFila(tFila *f) {

    if(NULL) return;

    for(int i = 0; i < f -> qtdItens; i++) {
        desalocaDocumento(f -> documentos[i]);
    }
    free(f -> documentos);
    free(f);

}


void insereDocumentoFila(tFila *f, void *dado, func_ptr_imprimeNaTela imprimeNaTela,
                         func_ptr_imprimeEmArquivo ImprimeEmArquivo,
                         func_ptr_desaloca desaloca) {
    
    f -> qtdItens++;

    f -> documentos = (tDocumento **) realloc(f -> documentos, f -> qtdItens * sizeof(tDocumento *));

    f -> documentos[f -> qtdItens - 1] = criaDocumento(dado, imprimeNaTela, ImprimeEmArquivo, desaloca);
    
}


int quantidadeDocumentosNaFila(tFila *f) {
return f -> qtdItens;
}


void imprimeFila(tFila *f, char *path) {

    printf("################### FILA DE IMPRESSAO MEDICA #####################\n");
    printf("EXECUTANDO FILA DE IMPRESSÃO:\n\n");

    for(int i = 0; i < quantidadeDocumentosNaFila(f); i++) {
        printf("---\n");
        printf("IMPRIMINDO %s"); //NAO SEI SE ONDE TIRAR ESSA STRING E NEM SE ESSE PRINTF DEVERIA ESTAR AQUI
        imprimeNaTelaDocumento(f -> documentos[i]);
        imprimeEmArquivoDocumento(f -> documentos[i], path);

        printf("---\n");
        printf("PRESSIONE QUALQUER TECLA PARA PARAR A EXECUÇÃO DA FILA\n\n");
    }

    printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU PRINCIPAL\n");
    printf("############################################################\n");
}