## 💻 Sobre o repositório
Este repositório contém um trabalho desenvolvido em **C** para a disciplina de 🎲 **Estrutura de Dados I**.  
O projeto resolve labirintos utilizando **pilhas** para implementar o **algoritmo de backtracking**, permitindo que o programa retorne a pontos de referência anteriores quando necessário.  

---

## 📄 Descrição detalhada
Um dos desafios frequentemente abordados com o uso de **pilhas** envolve a resolução de
labirintos, que são enigmas concebidos como testes para avaliar o desempenho das
estruturas de dados. Além disso, as **pilhas** desempenham um papel crucial na aplicação de
algoritmos de Backtracking, que envolvem a criação de **pontos de referência** para permitir
que o algoritmo faça retornos a estados/pontos anteriores.

Em um labirinto, por exemplo, podemos encontrar um caminho correto empilhando cada
espaço avançado e desempilhando espaços quando chegar a um ponto sem saída, até algum
espaço que possibilita a tomada de outro caminho. Nesta lógica, ao final do algoritmo a **pilha**
irá conter o **caminho correto**. E uma **pilha vazia** indica que **não há solução** para o labirinto
apresentado.

O objetivo deste programa é encontrar um caminho do ponto de partida até o ponto de chegada, obedecendo às seguintes regras:  

- Movimentação permitida apenas nas quatro direções cardeais: cima, baixo, esquerda e direita.  
- Não é possível atravessar paredes.  
- O labirinto é fechado (sem saídas externas).  
- O algoritmo de backtracking deve explorar todas as opções até encontrar a saída ou concluir que não existe caminho.  

### Entrada
O labirinto é fornecido em um arquivo chamado `labirinto.txt` com o seguinte formato:  

1. A primeira linha contém um número inteiro `n`, representando a dimensão do labirinto (sempre uma matriz quadrada).  
2. As próximas `n` linhas contêm a matriz do labirinto, com números inteiros separados por espaço, conforme a legenda:  
   - `1` – Parede  
   - `0` – Caminho livre/vazio  
   - `2` – Posição inicial  
   - `3` – Posição de chegada  

---

## 👀 Demonstração
![Demonstração do Programa](gif/demonstração%20do%20programa.gif)
