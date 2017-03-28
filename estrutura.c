#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// TUDO DE LISTA 

typedef struct {
    int chave;
} Registro;

typedef struct aux {
    Registro reg;
    struct aux* prox;
} Elemento;

typedef Elemento* Pont;

typedef struct {
    Pont inicio;
} Lista;

int tamanho (Lista *l) {
    Pont endereco = l->inicio;  
    int tam = 0;
    while (endereco != NULL) {
        tam++;
        endereco = endereco->prox;
    }
    return tam;
}

void inicializa(Lista* l) {
    l->inicio = NULL;
}

void exibirLista (Lista* l) {
    Pont endereco = l->inicio;
    printf("Lista: \n");
    while (endereco != NULL){
        printf("%d ", endereco->reg.chave);
        endereco = endereco->prox;
    }
    printf("\n");
}

Pont buscaSequencial (Lista* l, int chave, Pont *ant) {
    *ant = NULL;
    Pont atual = l->inicio;
    while ((atual != NULL) && (atual->reg.chave<chave)) {
        *ant = atual;
        atual = atual->prox;
    }
    if ((atual != NULL) && (atual->reg.chave == chave)) return atual; 
    return NULL;
}

int insere (Lista* l, Registro reg) {
    int chave = reg.chave;
    Pont ant, i;
    i = buscaSequencial(l, chave, &ant);
    if (i!= NULL) return 0; // não queremos chave repetida
    i = (Pont) malloc(sizeof(Elemento));
    i->reg = reg;
    if (ant == NULL) {
        i->prox = l->inicio;
        l->inicio = i;
    } else {
        i->prox = ant->prox;
        ant->prox = i;
    }

}

Registro* insereNode (int chave) {
    
   Registro* node = (Registro*) malloc(sizeof(Registro));

   if (node == NULL) {
     printf(" Erro: Memoria insuficiente!\n");
     exit(1);
   }
   
    node->chave = chave;
    return *node;
}

int exclui (Lista *l, int excluir) {
    Pont ant, i; 
    i = buscaSequencial(l,excluir, &ant);
    if (i==NULL) return 0; // n tenho como excluir algo que não existe
    if (ant == NULL) l->inicio = i->prox;
    else ant->prox = i->prox;
    free(i);
    return 1;
} 

void reinicializarLista(Lista *l) {
    Pont end = l->inicio;
    while (end!=NULL){
        Pont apagar = end;
        end = end->prox;
        free(apagar);
    }
}
// ACABOU LISTA /////////////////////////////////

int main(int argc, char const *argv[])
{

    int op, num;
    Lista* MinhaLista;
    Registro no;

    scanf("%d", &op);
    while (op != 0) {
        printf("\n 1- Iniciar lista \n 
            2- Inserir novo elemento \n 
            3- Esvaziar Lista \n 
            4- Verficar se a lista está vazia 
            \n 5- Imprimir lista"); 
        switch (op) {

            case 1: 
                inicializa(MinhaLista);
                printf("\n Lista iniciada!");
            break;

            case 2: 
                printf("\n Digite o elemento que você gostaria de inserir.");
                scanf("%d\n", &num);
                no =  insereNode(num);
                insere(MinhaLista, no);
            break;

            case 3: 
                reinicializarLista(MinhaLista);
            break;

            case 4: 
            inicializa(MinhaLista);
            printf("\n Lista iniciada!");
            break;

            case 5: 
            exibirLista(MinhaLista);
            printf("\n Lista iniciada!");
            break;
        }
        printf("\nDigite uma opcao.");
        scanf("%d", &op);
    }
    printf("\nDia livre amanhã!");
    return 0;
}