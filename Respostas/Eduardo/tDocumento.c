#include "tDocumento.h"
#include <stdlib.h>

typedef struct {
    void * dado;
    func_ptr_imprimeNaTela imprimeNaTela;
    func_ptr_imprimeEmArquivo imprimeEmArquivo;
    func_ptr_desaloca desaloca;
} tDocumento;


tDocumento *criaDocumento(void *dado, func_ptr_imprimeNaTela imprimeNaTela,
                          func_ptr_imprimeEmArquivo ImprimeEmArquivo,
                          func_ptr_desaloca desaloca) {

    tDocumento * documento = (tDocumento *) malloc(sizeof(tDocumento));

    documento -> dado = dado;
    documento -> imprimeNaTela = imprimeNaTela;
    documento -> imprimeEmArquivo = ImprimeEmArquivo;
    documento -> desaloca = desaloca;
}


void desalocaDocumento(tDocumento *doc) {
    doc -> desaloca(doc);
}


void imprimeNaTelaDocumento(tDocumento *doc) {
    doc -> imprimeNaTela(doc);
}


void imprimeEmArquivoDocumento(tDocumento *doc, char *path) {
    doc -> imprimeEmArquivo(doc, path);
}