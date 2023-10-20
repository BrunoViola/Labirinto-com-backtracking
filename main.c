#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TAD.h"
#include "funcoes_labirinto.h"

int main(){
    // ===== Processo de leitura do arquivo =====
    FILE *arquivo;
    arquivo = fopen("labirinto.txt", "r");
    if(arquivo == NULL){
        printf("\nNao foi possivel abrir o seu arquivo");
        return 1;
    }
    // __________________________________________

    char *ptr, retirado = 'A';
    int ultimoMovimento = 0, xAtual, yAtual, *valores, tamanhoMatriz;

    PILHA *p = (PILHA*) malloc(sizeof(PILHA));
    inicializarPilha(p);

    ptr = alocarMatriz(); //Le a matriz no arquivo e a aloca de maneira dinamica

    if(ptr == NULL) { //Verifica se a matriz foi alocada corretamente
        printf("\nErro ao alocar a matriz.");
        fclose(arquivo);
        free(p);
        return 1;
    }
       
    fscanf(arquivo, "%d ", &tamanhoMatriz);//Le apenas o tamanho da matriz, pois esse valor eh importante para a logica do main

    // ====================== Encontra a posicao atual do jogador =====================
    for (int i = 0; i < tamanhoMatriz; i++){
        for(int j=0; j < tamanhoMatriz; j++){
            if(ptr[i*tamanhoMatriz+j] == '2'){
                xAtual = i;
                yAtual = j;
            }
        }
        printf("\n");
    }
    // =-------------------------------------------------------------------------------

    while(1){
        clear(); //Limpa o console
        imprimirLabirinto(ptr); //Imprime o estado atual do labirinto
        delay (200);//O valor de entrada desta funcao eh a quantidade de milissegundos entre uma geracao e outra

        /*  Significados da variável 'ultimoMovimento'
        2 - Cima
        4 - Esquerda
        6 - Direita
        8 - Baixo
        Sendo que se o personagem se moveu, por exemplo, para baixo ele nao podera retornar para cima, apenas para a esquerda, direita ou para baixo novamente*/

        if((ptr[(xAtual+1)*tamanhoMatriz+yAtual] == '0' || ptr[(xAtual+1)*tamanhoMatriz+yAtual] == '3') && (ultimoMovimento== 0 || ultimoMovimento == 8 || ultimoMovimento == 4 || ultimoMovimento == 6)){//verifica para baixo
            retirado = moverBaixo(ptr, xAtual, yAtual, tamanhoMatriz, ultimoMovimento);
            push(p, xAtual, yAtual, ultimoMovimento);
            xAtual++;

        }else if((ptr[(xAtual-1)*tamanhoMatriz+yAtual] == '0' || ptr[(xAtual-1)*tamanhoMatriz+yAtual] == '3')&&(ultimoMovimento==0 || ultimoMovimento == 2 || ultimoMovimento == 4 || ultimoMovimento == 6)){//verifica para cima
            push(p, xAtual, yAtual, ultimoMovimento);
            retirado = moverCima(ptr, xAtual, yAtual, tamanhoMatriz, ultimoMovimento);
            xAtual--;

        }else if((ptr[xAtual*tamanhoMatriz+(yAtual+1)] == '0'|| ptr[xAtual*tamanhoMatriz+(yAtual+1)] == '3')&& (ultimoMovimento==0 || ultimoMovimento == 8 || ultimoMovimento == 2 || ultimoMovimento == 6)){//verifica para direita
            push(p, xAtual, yAtual, ultimoMovimento);            
            retirado = moverDireita(ptr, xAtual, yAtual, tamanhoMatriz, ultimoMovimento);
            yAtual++;

        }else if((ptr[xAtual*tamanhoMatriz+(yAtual-1)] == '0' || ptr[xAtual*tamanhoMatriz+(yAtual-1)] == '3') && (ultimoMovimento==0 || ultimoMovimento == 8 || ultimoMovimento == 2 || ultimoMovimento == 4)){//verifica para a esquerda
            push(p, xAtual, yAtual, ultimoMovimento);       
            retirado = moverEsquerda(ptr, xAtual, yAtual, tamanhoMatriz, ultimoMovimento);
            yAtual--;

        }else if(retirado!='A'){//backtracking
            valores = pop(p);

            if(valores!= NULL){
                ptr[xAtual*tamanhoMatriz+yAtual] = '9';
                ultimoMovimento = valores[0];
                ultimoMovimento = modificarUltimo(ultimoMovimento);
                xAtual = valores[1];
                yAtual = valores[2];
                ptr[xAtual*tamanhoMatriz+yAtual] = '2';
                free(valores);
            }
        }
                            
        if(retirado == '3'){//Se o 'retirado' for o ponto de chegada, entao o labirinto foi completado com sucesso
            clear();
            imprimirLabirinto(ptr);
            printf("\nPronto! O labirinto foi completado!!!");

            printf("\nCaminho correto: ");
            imprimirPilha(p);

            free(ptr);
            liberarPilha(p);
            free(p);
            fclose(arquivo);
            return 1;
        }
        
        if(verificarEncurralado(ptr, xAtual, yAtual, tamanhoMatriz) == 1){
            clear();
            imprimirLabirinto(ptr);
            printf("\nO labirinto nao tem solucao");

            free(ptr);
            liberarPilha(p);
            free(p);
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}