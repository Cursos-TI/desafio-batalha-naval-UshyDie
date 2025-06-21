#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck

// ** Definindo constantes para o tamanho do tabuleiro, tamanho do navio, tamanho das habilidades e  seus valores representativos 
#define TAMANHO_TABULEIRO 10 // Tamanho do tabuleiro, [10][10]
#define TAMANHO_NAVIO 3 // Tamanho do navio, que é 3 para este desafio
#define VALOR_NAVIO 3 // Valor que representa uma parte do vetor navio no tabuleiro
#define TAMANHO_HABILIDADE 5 // Tamanho da matriz para habilidades [5][5]
#define VALOR_HABILIDADE 1 // Valor que representa a parte preenchida da matriz habilidade

// ** Estrutura para armazenar a posição de um navio no tabuleiro
// A estrutura Posicao armazena as coordenadas x e y de um navio no tabuleiro
typedef struct {
    int x; // Coordenada x -> linha[i]
    int y; // Coordenada y -> coluna[j]
} Posicao;

// Estrutura para definir as direções possíveis de posicionamento dos navios
// A enum Direcao define as direções possíveis para posicionar um navio no tabuleiro
typedef enum {
  HORIZONTAL,
  VERTICAL,
  DIAGONAL_PRINCIPAL,
  DIAGONAL_SECUNDARIA
} Direcao;

// ** Estrutura para armazenar as habilidades
// A estrutura Habilidade armazena uma máscara de ocupação e a posição  da habilidade no tabuleiro
// A máscara é uma matriz que indica quais células do tabuleiro são afetadas pela habilidade
typedef struct {
  int mascara[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]; // 1 para ocupar, 0 para não
  Posicao eixo; // posição da habilidade no tabuleiro
} Habilidade;


// ** Função para verificar se pode aplicar a habilidade
int pode_aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], Habilidade hab) {
  int deslocamento = TAMANHO_HABILIDADE / 2; // Deslocamento para centralizar a habilidade
  // Verifica se a habilidade pode ser aplicada sem ultrapassar os limites do tabuleiro
  for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
      for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
          if (hab.mascara[i][j]) {
              int x = hab.eixo.x + (i - deslocamento); // Calcula a posição x considerando o eixo da habilidade
              int y = hab.eixo.y + (j - deslocamento); // Calcula a posição y considerando o eixo da habilidade
              if (x < 0 || x >= TAMANHO_TABULEIRO || y < 0 || y >= TAMANHO_TABULEIRO) // Condição para verificar se habilidade não extravasa tamanho do tabuleiro
                  return 0; // Fora do tabuleiro
              if (tabuleiro[x][y] != 0) // Condição para verificar se a posição do elemnto não está ocupado
                  return 0; // Já ocupado
          }
      }
  }
  return 1;
}

// ** Função para aplicar a habilidade no tabuleiro
// A função aplicar_habilidade recebe o tabuleiro, a habilidade e o valor a ser aplicado
// Ela percorre a máscara da habilidade e aplica o valor nas posições correspondentes do tabuleiro
void aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], Habilidade hab, int valor) {
  int deslocamento = TAMANHO_HABILIDADE / 2;
  for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
      for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
          if (hab.mascara[i][j]) {
              int x = hab.eixo.x + (i - deslocamento);
              int y = hab.eixo.y + (j - deslocamento);
              tabuleiro[x][y] = valor;
          }
      }
  }
}



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
    
    // ** Atribuindo valores à matriz , à linha e à coluna do tabuleiro 
    
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

    // ** Definições das habilidades
    // Define as habilidades com suas máscaras e posições centrais
    const int meio = TAMANHO_HABILIDADE / 2; // Constante que representa a metade do tamanho da matriz para centralizar a habilidade
    
    // ** Habilidadde Cone
    Habilidade cone = {0};
    cone.eixo.x = 2;
    cone.eixo.y = 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i <= meio && abs(j - meio) <= i) { // verifica a condição que indica [i] seja a metade do tamanho da matrize [j] o absoluto da subtração dele e a metade do tamanho da matriz
                cone.mascara[i][j] = VALOR_HABILIDADE; // Preenche a máscara do cone
            }
        }
    }

    // ** Habilidade Octaedro
    Habilidade octaedro = {0};
    octaedro.eixo.x = 7; // Posição do octaedro  - linha
    octaedro.eixo.y = 2; // Posição do octaedro  - coluna
    // Inicializa a matriz do octaedro e preenche a máscara
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio) { //Verifica a condição se a soma dos absolutos  de (i - a metade do tamanho da matriz) + (j - a metade do tamanho da matriz)é a distância de i até o eixo e abs(j - meio) é menor ou igual a metade do tamanho da matriz
                octaedro.mascara[i][j] = VALOR_HABILIDADE; // Preenche a máscara do octaedro
            }
        }
    }

    // ** Habilidade Cruz
    // A habilidade cruz é uma matriz 5x5 com a linha e coluna centrais preenchidas
    Habilidade cruz = {0};
    cruz.eixo.x = 6; // Posição  da cruz - linha
    cruz.eixo.y = 7; // Posição  da cruz no - coluna
    // Inicializa a matriz e preenche a máscara da cruz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        cruz.mascara[i][TAMANHO_HABILIDADE/2] = VALOR_HABILIDADE; // coluna - [i] recebe o valor da iteração, enquanto [j] recebe a metade do tamanho da matriz
        cruz.mascara[TAMANHO_HABILIDADE/2][i] = VALOR_HABILIDADE; // linha 
    }

    // ** Verifica se pode aplicar a habilidade cruz pode ser aplicada no tabuleiro
    // Se puder, aplica a habilidade cruz no tabuleiro

    if (pode_aplicar_habilidade(tabuleiro, cone)) {
      aplicar_habilidade(tabuleiro, cone, VALOR_HABILIDADE);
    }
    // ** Verifica se pode aplicar a habilidade octaedro pode ser aplicada no tabuleiro
    // Se puder, aplica a habilidade octaedro no tabuleiro
    if (pode_aplicar_habilidade(tabuleiro, octaedro)) {
      aplicar_habilidade(tabuleiro, octaedro, VALOR_HABILIDADE);
    }
    // ** Verifica se pode aplicar a habilidade cruz pode ser aplicada no tabuleiro
    // Se puder, aplica a habilidade cruz no tabuleiro
    if (pode_aplicar_habilidade(tabuleiro, cruz)) {
      aplicar_habilidade(tabuleiro, cruz, VALOR_HABILIDADE);
    }

    // ** Posições iniciais dos navios - [i][j]
    Posicao navioH = {9, 6}; //  Coordenadas iniciais do navio horizontal 
    Posicao navioV = {0, 9}; // Coordenadas iniciais do navio vertical
    Posicao navioDP = {1, 6}; // Coordenadas iniciais do navio diagonal principal
    Posicao navioDS = {2, 5}; // Coordenadas iniciais do navio diagonal secundária
    
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
     
    

    return 0;
}
        
       
    
            
           
           
    

        
       



    

    
    

    

    



       
    
    
    
    

    
