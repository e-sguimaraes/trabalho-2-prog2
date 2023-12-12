#include <stdlib.h>
#include <stdio.h>
#include "tFila.h"

struct tFila {
    int qtdItens;
    tDocumento ** documentos;
};


tFila *criaFila() {

    tFila * fila = (tFila *) malloc(sizeof(tFila));

    fila -> qtdItens = 0;
    fila -> documentos = (tDocumento **) malloc(sizeof(tDocumento *));

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

    if(f -> qtdItens != 1) f -> documentos = (tDocumento **) realloc(f -> documentos, f -> qtdItens * sizeof(tDocumento *));

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
        imprimeNaTelaDocumento(f -> documentos[i]);
        imprimeEmArquivoDocumento(f -> documentos[i], path);

        printf("---\n");
        printf("PRESSIONE QUALQUER TECLA PARA PARAR A EXECUÇÃO DA FILA\n\n");
    }

    printf("PRESSIONE QUALQUER TECLA PARA VOLTAR PARA O MENU ANTERIOR\n");
    printf("############################################################\n");
}