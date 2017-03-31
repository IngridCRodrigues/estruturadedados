#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;
typedef struct {
    TIPOCHAVE chave;
} Registro;

typedef struct  aux {
    Registro reg;
    struct aux* prox;
} Elemento;

typedef Elemento *Pont;

typedef struct {
    Pont topo; // ponteiro para o primeiro elemento da pilha
} Pilha;

void inicializaPilha (Pilha *p) {
    p->topo = NULL;
}

int pilhaVazia (Pilha *p) {
    if (p->topo == NULL) return 1;
    return 0;
}

int tamanhoPilha (PILHA* p) {
    PONT end = p->topo;
    int tamanho = 0;
    while (end != NULL) {
        tam++;
        end = end->prox;
    }
}

void exibePilha (Pilha* p) {
    PONT end = p->topo;
    printf("\n Exibindo Pilha:");
    while (end != NULL) {
        printf("%d\n", end->reg.chave);
        end = end->prox;
    }
}   printf("\n.");


int Empilha(Pilha* ) {

}

int main(int argc, char const *argv[])
{
    printf("\n Olá");
    return 0;
}