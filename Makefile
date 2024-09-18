# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Arquivos de origem
SRCS = main.c TAD.c funcoes_labirinto.c

# Arquivo de saída
TARGET = labirinto

# Regra padrão
all: $(TARGET)

# Como criar o executável
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Limpar arquivos gerados
clean:
	rm -f $(TARGET)

.PHONY: all clean
