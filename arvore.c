// Altura é8 o caminho mais longo.
#include <stdio.h>
#include <malloc.h>

typedef struct aux {
    int chave;
    struct aux *esq, *dir;
}No;

typedef No* PontArv;

PontArv inicializaArv() {
    return NULL;
}

PontArv insereNodeArv (int chave) {
    PontArv noNovo = (PontArv)malloc(sizeof(noNovo));
    noNovo->chave = chave;
    noNovo->esq = noNovo->dir = NULL;
    return (noNovo);
}

PontArv insereArv(PontArv raiz, PontArv no) {
    if (raiz == NULL) return(no);
    if (no->chave < raiz->chave) {
            raiz->esq = insereArv(raiz->esq, no);
        } else {
            raiz->dir = insereArv(raiz->dir, no);           
        }
    return (raiz);
}

PontArv buscaArv(PontArv raiz, int chave) {
    if (raiz == NULL) return NULL;
    if (raiz->chave == chave) return raiz;
    if (raiz->chave < chave) return buscaArv(raiz->dir, chave); 
    return buscaArv(raiz->esq, chave);
}

int numeroNosArv(PontArv raiz) {
    if (!raiz) return 0;
    return numeroNosArv(raiz->esq) +1 + numeroNosArv(raiz->dir);

}

void imprimeArvCrescente(PontArv raiz) {
    if (raiz != NULL) {
        imprimeArvCrescente(raiz->esq);
        printf("%d ",raiz->chave);
        imprimeArvCrescente(raiz->dir);
    }
}

int main() {
    PontArv raiz;
    raiz = inicializaArv();
    PontArv no = insereNodeArv(60);
    raiz = insereArv(raiz, no);
    no = insereNodeArv(3);
    raiz = insereArv(raiz, no);
    no = insereNodeArv(4);
    raiz = insereArv(raiz, no);
    no = insereNodeArv(10);
    raiz = insereArv(raiz, no);    
    no = insereNodeArv(50);
    raiz = insereArv(raiz, no);    
    no = insereNodeArv(80);
    raiz = insereArv(raiz, no);    
    no = insereNodeArv(90);
    raiz = insereArv(raiz, no);    
    no = insereNodeArv(70);
    raiz = insereArv(raiz, no);
    PontArv p = buscaArv(raiz, 2);
    int nos = numeroNosArv(raiz);
    printf("Quantidade de nós: %d\n",nos);
    printf("Imprimindo Árvore:\n");
    imprimeArvCrescente(raiz);
    return 0;
}