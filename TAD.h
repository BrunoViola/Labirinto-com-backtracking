// ============== PILHA ===============
typedef struct coord{
    struct coord* proximo;
    int x;
    int y;
    int ultimaJogada;
}Coordenada;

typedef struct{
    Coordenada *topo;
}PILHA;

void inicializarPilha(PILHA *p);
void push(PILHA *p, int x, int y, int ultimoMovimento);
int *pop(PILHA *p);
void imprimirPilha(PILHA *p);
void liberarPilha(PILHA *p);
//======================================