char *alocarMatriz();
void imprimirLabirinto(char *ptr);
int modificarUltimo(int ultimoMovimento);
int verificarEncurralado(char *ptr, int xAtual, int yAtual, int tamanhoMatriz);
void delay(int segundos);
void clear ();

char moverBaixo(char *ptr, int xAtual, int yAtual, int tamanhoMatriz, int ultimoMovimento);
char moverCima(char *ptr, int xAtual, int yAtual, int tamanhoMatriz, int ultimoMovimento);
char moverDireita(char *ptr, int xAtual, int yAtual, int tamanhoMatriz, int ultimoMovimento);
char moverEsquerda(char *ptr, int xAtual, int yAtual, int tamanhoMatriz, int ultimoMovimento);
