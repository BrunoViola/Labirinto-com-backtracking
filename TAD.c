#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"
//================== PILHA ===========================
void inicializarPilha(PILHA *p){
    p->topo = NULL;
}

void liberarPilha(PILHA *p) {
    while (p->topo != NULL) {
        Coordenada *temp = p->topo;
        p->topo = p->topo->proximo;
        free(temp);
    }
}

void push(PILHA *p, int x, int y, int ultimoMovimento){
    Coordenada *ptr = (Coordenada*) malloc(sizeof(Coordenada));

    if (ptr == NULL) {
        printf("Erro: falha na alocação de memória!\n");
        exit(1); 
    }

    ptr->x = x;
    ptr->y = y;
    ptr->ultimaJogada = ultimoMovimento;
    ptr->proximo = p->topo;
    p->topo = ptr;
}

int *pop(PILHA *p){
    int ultimoMovimento;
    int *valores = (int*) malloc(3*sizeof(int));

    if (p->topo == NULL) {
        free(valores);
        return NULL;
    }

    Coordenada *ptr = p->topo;
    valores[0] = ptr->ultimaJogada;
    valores[1] = ptr->x;
    valores[2] = ptr->y;
    p->topo = ptr->proximo;
    
    free(ptr);
    return valores;
}

void imprimirPilha(PILHA *p){
    Coordenada *ptr = p->topo;
    Coordenada *aux;
    PILHA *auxiliar = (PILHA *) malloc(sizeof(PILHA));;
    inicializarPilha (auxiliar);

    while(ptr != NULL){
        push(auxiliar, ptr->x, ptr->y, 1);
        ptr = ptr->proximo;
    }
    aux = auxiliar->topo;

    while(aux != NULL){
        printf("(%d,%d)", aux->x, aux->y);
        aux = aux->proximo;
    }

    liberarPilha(auxiliar);
    free(auxiliar);
}
//==================================================