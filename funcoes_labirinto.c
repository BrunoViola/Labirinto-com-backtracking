#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "funcoes_labirinto.h"

// ===== Define as cores a serem utilizadas nas impressoes do labirinto =====
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_DARKYELLOW  "\x1b[33;1m"
#define ANSI_COLOR_RESET   "\x1b[0m"
// -----------------------------------------------------------------------------

char *alocarMatriz(){ // Le a matriz do arquivo e a passa para uma matriz alocada dinamicamente
    FILE *arq;
    char *ptr= NULL;
    int tamanhoMatriz;

    arq = fopen("labirinto.txt", "r");
    if(arq){
        fscanf(arq, "%d ", &tamanhoMatriz);
        ptr = (char*) malloc(tamanhoMatriz*tamanhoMatriz*sizeof(char));

        for (int i = 0; i < tamanhoMatriz; i++) {
            for(int j=0; j < tamanhoMatriz; j++){
                fscanf(arq, "%c ", &ptr[i*tamanhoMatriz+j]);
            }
        }

        fclose(arq);
    }else{
        printf("\nArquivo nao encontrado");
    }
    return ptr;
}

void imprimirLabirinto(char *ptr){    
    setlocale(LC_ALL, "");
    FILE *arq;
    int tamanhoMatriz;
    
    arq = fopen("labirinto.txt", "r");
    if(arq){
        fscanf(arq, "%d ", &tamanhoMatriz);
        fclose(arq);
    }else{
        printf("\nErro ao abrir arquivo\n");
        return;
    }

    for (int i = 0; i < tamanhoMatriz; i++){
        for(int j=0; j < tamanhoMatriz; j++){
            if(ptr[i*tamanhoMatriz+j] == '1'){
                printf(ANSI_COLOR_RED "###" ANSI_COLOR_RESET);
            }else if(ptr[i*tamanhoMatriz+j] == '0' || ptr[i*tamanhoMatriz+j] == '9'){
                printf("   ");
            }else if(ptr[i*tamanhoMatriz+j] == '2'){
                printf(ANSI_COLOR_BLUE " & " ANSI_COLOR_RESET);
                
            }else if(ptr[i*tamanhoMatriz+j] == '3'){
                printf(ANSI_COLOR_YELLOW " @ " ANSI_COLOR_RESET);
            }else if(ptr[i*tamanhoMatriz+j] == '5'){
                printf(ANSI_COLOR_DARKYELLOW " . " ANSI_COLOR_RESET);
            }
        }
        printf("\n");
    }
}

int modificarUltimo(int ultimoMovimento){// Essa funcao evita que o personagem fique em um loop (onde ele vai e volta para determinada posicao)
    int valor;

    if(ultimoMovimento == 2){
        valor = 8;
    }else if(ultimoMovimento == 8){
        valor = 2;
    }else if(ultimoMovimento == 4){
        valor = 6;
    }else if(ultimoMovimento == 6){
        valor = 4;
    }
    return valor;
}

int verificarEncurralado(char *ptr, int xAtual, int yAtual, int tamanhoMatriz){ // verifica se o jogador nao possui mais possibilidades de se deslocar
    int valor = 0, verifica=0;
    if(ptr[(xAtual+1)*tamanhoMatriz+yAtual] == '1' || ptr[(xAtual+1)*tamanhoMatriz+yAtual] == '9'){
        verifica++;
    }
    if(ptr[(xAtual-1)*tamanhoMatriz+yAtual] == '1' || ptr[(xAtual-1)*tamanhoMatriz+yAtual] == '9'){
        verifica++;
    }
    if(ptr[xAtual*tamanhoMatriz+(yAtual+1)] == '1' || ptr[xAtual*tamanhoMatriz+(yAtual+1)] == '9'){
        verifica++;;
    }
    if(ptr[xAtual*tamanhoMatriz+(yAtual-1)] == '1' || ptr[xAtual*tamanhoMatriz+(yAtual-1)] == '9'){
        verifica++;
    }

    if(verifica == 4){
        valor = 1;
    }
    return valor;
}

void delay(int milissegundos) //Funcao destinada a criar o delay entre geracoes
{

    clock_t tempoinicial = clock();

    while (clock() < tempoinicial + milissegundos);
}


void clear (){ //Funcaoo destinada a limpeza do terminal a partir da identificao do sistema utilizado
   #ifdef _WIN32
        system("cls");
   #elif defined(__linux__) || defined(__APPLE__)
        system ("clear");
   #else
    printf("\nSistema nao reconhecido para a limpeza do terminal");

   #endif
}

// ===== Funcoes de movimentacao =====
char moverBaixo(char *ptr, int xAtual, int yAtual, int tamanhoMatriz, int ultimoMovimento){
    ptr[xAtual*tamanhoMatriz+yAtual] = '5';//moverBaixo();
    
    ultimoMovimento = 8;

    char retirado = ptr[(xAtual+1)*tamanhoMatriz+yAtual]; 
    ptr[(xAtual+1)*tamanhoMatriz+yAtual] = '2';

    return retirado;
}

char moverCima(char *ptr, int xAtual, int yAtual, int tamanhoMatriz, int ultimoMovimento){
    ptr[xAtual*tamanhoMatriz+yAtual] = '5';//moverCima();
    ultimoMovimento = 2;
                    
    char retirado = ptr[(xAtual-1)*tamanhoMatriz+yAtual];
    ptr[(xAtual-1)*tamanhoMatriz+yAtual] = '2';

    return retirado;
}

char moverDireita(char *ptr, int xAtual, int yAtual, int tamanhoMatriz, int ultimoMovimento){
    ptr[xAtual*tamanhoMatriz+yAtual] = '5';//moverDireita();
    ultimoMovimento = 6;
                    
    char retirado = ptr[xAtual*tamanhoMatriz+(yAtual+1)];
    ptr[xAtual*tamanhoMatriz+(yAtual+1)] = '2';

    return retirado;
}

char moverEsquerda(char *ptr, int xAtual, int yAtual, int tamanhoMatriz, int ultimoMovimento){
    ptr[xAtual*tamanhoMatriz+yAtual] = '5';//moverEsquerda();
    ultimoMovimento = 4;
                    
    char retirado = ptr[xAtual*tamanhoMatriz+(yAtual-1)];
    ptr[xAtual*tamanhoMatriz+(yAtual-1)] = '2';

    return retirado;
}
//-----------------------------------