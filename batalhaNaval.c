#include <stdio.h>

// Desafio Batalha Naval - MateCheck

// ** Definindo constantes para o tamanho do tabuleiro, tamanho do navio e valores representativos
#define TAMANHO_TABULEIRO 10 // Tamanho do tabuleiro, que é 10x10
#define TAMANHO_NAVIO 3 // Tamanho do navio, que é 3 para este desafio
#define VALOR_NAVIO 3 // Valor que representa uma parte do navio no tabuleiro

// ** Estrutura para armazenar a posição de um navio no tabuleiro
// A estrutura Posicao armazena as coordenadas x e y de um navio no tabuleiro
typedef struct {
    int x; // Coordenada x -> linha
    int y; // Coordenada y -> coluna
} Posicao;

// Estrutura para definir as direções possíveis de posicionamento dos navios
// A enum Direcao define as direções possíveis para posicionar um navio no tabuleiro
typedef enum {
  HORIZONTAL,
  VERTICAL,
  DIAGONAL_PRINCIPAL,
  DIAGONAL_SECUNDARIA
} Direcao;

// ** Função para verificar posição válida de um navio mais seu valor dentro do tabuleiro
int pode_posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], Posicao inicio, int tamanho, Direcao direcao) {
  for (int i = 0; i < tamanho; i++) {
      int x = inicio.x;
      int y = inicio.y;
      if (direcao == HORIZONTAL) y += i;
      else if (direcao == VERTICAL) x += i;
      else if (direcao == DIAGONAL_PRINCIPAL) { x += i; y += i; }
      else if (direcao == DIAGONAL_SECUNDARIA) { x += i; y -= i; }

      // Verifica limites do tabuleiro
      if (x < 0 || x >= TAMANHO_TABULEIRO || y < 0 || y >= TAMANHO_TABULEIRO)
          return 0; // Não pode posicionar

      // Verifica se já existe navio
      if (tabuleiro[x][y] != 0)
          return 0; // Não pode posicionar
  }
  return 1; // Pode posicionar
}


int main() {

    // ** Declarando tabuleiro do jogo.

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // ** Inicializando tabuleiro com valores 0, representando água

    char coluna[TAMANHO_TABULEIRO]; // Colunas do cabeçalho do tabuleiro
    int linha[TAMANHO_TABULEIRO]; // Linhas do tabuleiro, de 1 a 10
    
    // ** Atribuindo valores à matriz do tabuleiro e aos vetores navios
    
    // ** Preenchendo os vetores coluna e linha com valores correspondentes
    for (int i = 0; i < 10; i++) // Preenchendo o vetor coluna com letras de A a J
    {
        coluna[i] = 'A' + i; // Atribui a letra correspondente à coluna
    }

    for (int i = 0; i < 10; i++) // Preenchendo o vetor linha com valores de 1 a 10
    {
        linha[i] = i + 1; // Atribui o valor da linha correspondente
    }

    // **  Inicialização do tabuleiro, com 0 representando a água.

    for (int i = 0; i < 10; i++) //Percorre as linhas do tabuleiro
    {
        for (int j = 0; j < 10; j++) // Percorre as colunas do tabuleiro
        {
            tabuleiro[i][j] = 0; // Inicializa o tabuleiro com 0 (água)
        }
        printf("\n"); // Linha em branco para melhor visualização
    }

    // ** Posições iniciais dos navios
    Posicao navioH = {2, 2}; //  Coordenadas iniciais do navio horizontal
    Posicao navioV = {5, 5}; // Coordenadas iniciais do navio vertical
    Posicao navioDP = {1, 0}; // Coordenadas iniciais do navio diagonal principal
    Posicao navioDS = {0, TAMANHO_TABULEIRO - 1}; // Coordenadas iniciais do navio diagonal secundária
    
    // ** Inserir navios no tabuleiro
    // Verifica se as posições iniciais dos navios são válidas
    // Chama a função para verificar se é possível posicionar os navios nas posições especificadas
    // Se não for possível, imprime uma mensagem de erro e encerra o programa
    // ** Verificando se navio H está dentro dos limites do tabuleiro  e inserindo seus valores - Horizontal
    if (!pode_posicionar_navio(tabuleiro, navioH, TAMANHO_NAVIO, HORIZONTAL)) {
      printf("Posição inválida para o navio horizontal.\n");
      return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
      tabuleiro[navioH.x][navioH.y + i] = VALOR_NAVIO;
    }
    
    // ** Verificando se navio V está dentro dos limites do tabuleiro e inserindo seus valores - Vertical
    if (!pode_posicionar_navio(tabuleiro, navioV, TAMANHO_NAVIO, VERTICAL)) {
      printf("Posição inválida para o navio vertical.\n");
      return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
      tabuleiro[navioV.x + i][navioV.y] = VALOR_NAVIO;
    }

    // ** Verificando se navio 3 está dentro dos limites do tabuleiro e inserindo seus valores - Diagonal principal
    if (!pode_posicionar_navio(tabuleiro, navioDP, TAMANHO_NAVIO, DIAGONAL_PRINCIPAL)) {
      printf("Posição inválida para o navio diagonal principal.\n");
      return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
      tabuleiro[navioDP.x + i][navioDP.y + i] = VALOR_NAVIO;
    }

    // ** Verificando se navio 4 está dentro dos limites do tabuleiro e inserindo seus valores - Diagonal secundária
    if (!pode_posicionar_navio(tabuleiro, navioDS, TAMANHO_NAVIO, DIAGONAL_SECUNDARIA)) {
      printf("Posição inválida para o navio diagonal secundária.\n");
      return 1;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
      tabuleiro[navioDS.x + i][navioDS.y - i] = VALOR_NAVIO;
    }
    
    // ** Exibindo o tabuleiro e os navios no console
    printf("** TABULEIRO BATALHA NAVAL **\n");

    printf("\n"); // Pula linha em branco para melhor visualização
    printf("   "); // Espaço para as colunas a insercão do cabeçalho
    
    // Loop para a impressão das colunas do tabuleiro
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%c ", coluna[j]); // Exibe as colunas de A a J
    }

    //  Loop para impressão das linhas do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        if(i != 9) // Verifica se o indice é diferente de 9
        {
            printf("\n%d  ", linha[i]); // Exibe as linhas de 1 a 9
        }
        else
        {
            printf("\n%d ", linha[i]); // Exibe a linha 10 com um espaço a menos para padronização do tabuleiro
        }
       
        // Percorre as colunas do tabuleiro
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            printf("%d ", tabuleiro[i][j]); // Exibe o valor do tabuleiro   
        }  
    }

    printf("\n \n"); // Pula 2 linhas após imprimir o tabuleiro
     
    // **Nível Mestre - Habilidades Especiais com Matrizes
    // TODO Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // TODO Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
        
       
    
            
           
           
    

        
       



    

    
    

    

    



       
    
    
    
    

    
