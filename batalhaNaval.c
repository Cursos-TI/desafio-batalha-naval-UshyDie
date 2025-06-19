#include <stdio.h>

// Desafio Batalha Naval - MateCheck

// ** Definindo constantes para o tamanho do tabuleiro, tamanho do navio e valores representativos
#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_TABULEIRO 10 // Tamanho do tabuleiro, que é 10x10
#define TAMANHO_NAVIO 3 // Tamanho do navio, que é 3 para este desafio
#define VALOR_NAVIO 3 // Valor que representa uma parte do navio no tabuleiro

// Função recursiva para inicialização dos navios
void inicializarNavio(int vetor[], int indice) {
    if(indice >= TAMANHO_NAVIO) return; // Condição de parada: se o índice for igual ao tamanho do navio, retorna
   

    vetor[indice] = VALOR_NAVIO; // Atribui o valor representativo do navio
    inicializarNavio(vetor, indice + 1);
}


int main() {

    // ** Declarando as variáveis  necessárias para o jogo.

    char coluna[COLUNAS]; // Colunas do cabeçalho do tabuleiro
    int linha[LINHAS]; // Linhas do tabuleiro, de 1 a 10

    int tabuleiro[LINHAS][COLUNAS]; // Declaração da  matriz bidimensional para representar o tabuleiro.
    
    int navio1[TAMANHO_NAVIO]; // Declarando o vetor do navio 1 tamanho 3 - representando as partes do navio
    int posicao_navio1_i, posicao_navio1_j; // Variável para armazenar as coordenadas do navio 1 (j para coluna, i para linha)
    
    int navio2[TAMANHO_NAVIO]; // Declarando o vetor do navio 2 tamanho 3 - representando as partes do navio
    int posicao_navio2_i, posicao_navio2_j; // Variável para armazenar as coordenadas do navio 2 (j para coluna, i para linha)
    
    
    int navio3[TAMANHO_NAVIO]; // Declarando o vetor do navio 3 tamanho 3 - representando as partes do navio
    int posicao_navio3_i, posicao_navio3_j; // Variável para armazenar as coordenadas do navio 3 (j para coluna, i para linha)
    
    int navio4[TAMANHO_NAVIO]; // Declarando o vetor do navio 4 tamanho 3 - representando as partes do navio
    int posicao_navio4_i, posicao_navio4_j; // Variável para armazenar as coordenadas do navio 4 (j para coluna, i para linha)

    // Declarando variavel de controle para permissão de posicionamento - valor inicial de 1 (pode ocupar posição)
    int posicao_permitida = 1; // Variável para controlar se a posição é permitida para o navio
    
    // ** Atribuindo valores à matriz do tabuleiro e aos vetores navios
    
    // Preenchendo os vetores coluna e linha com valores correspondentes
    for (int i = 0; i < 10; i++) // Preenchendo o vetor coluna com letras de A a J
    {
        coluna[i] = 'A' + i; // Atribui a letra correspondente à coluna
    }

    for (int i = 0; i < 10; i++) // Preenchendo o vetor linha com valores de 1 a 10
    {
        linha[i] = i + 1; // Atribui o valor da linha correspondente
    }

    // Inicialização do tabuleiro, com 0 representando a água.

    for (int i = 0; i < 10; i++) //Percorre as linhas do tabuleiro
    {
        for (int j = 0; j < 10; j++) // Percorre as colunas do tabuleiro
        {
            tabuleiro[i][j] = 0; // Inicializa o tabuleiro com 0 (água)
        }
        printf("\n"); // Linha em branco para melhor visualização
    }

    // Inicializando o navio 1
    inicializarNavio(navio1, 0); // Chama a função recursiva para inicializar o navio 1

    // Inicializando o navio 2
    inicializarNavio(navio2, 0); // Chama a função recursiva para inicializar o navio 2
    
    // Inicializando o navio 3
    inicializarNavio(navio3, 0); // Chama a função recursiva para inicializar o navio 3
    
    // Inicializando o navio 4
    inicializarNavio(navio4, 0); // Chama a função recursiva para inicializar o navio 4
          
    // ** Verificando se navio 1 está dentro dos limites do tabuleiro - Horizontal
   
    posicao_navio1_i = 9; // Linha 10 (índice 9) do tabuleiro
    posicao_navio1_j = 0; // Coluna A (índice 0) do tabuleiro

    if (posicao_navio1_j + TAMANHO_NAVIO > TAMANHO_TABULEIRO || posicao_navio1_i >= TAMANHO_TABULEIRO)
    {
        posicao_permitida = 0; // Se a posição do navio 1 ultrapassar o tamanho do tabuleiro, não é permitido posicionar

    } else 
    {
        // Verifica se já existe um navio na posição
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[posicao_navio1_i][posicao_navio1_j + i] != 0) {
                posicao_permitida = 0; // Se já existe um navio na posição, não é permitido posicionar
                break;
            }
        }
    }
    
    // ** Inserindo o navio 1 no tabuleiro se a posição for permitida - Horizontal
    // Definindo a posição do navio 1 se for permitida
    if (posicao_permitida) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[posicao_navio1_i][posicao_navio1_j + i] = VALOR_NAVIO; // Insere o navio 1 no tabuleiro com o valor da constante
            // printf("Navio 1 posicionado em: %c%d\n", coluna[posicao_navio1_j + i], linha[posicao_navio1_i]); // Exibe a posição do navio
        }
    } else 
    {
        printf("Posição inválida para o Navio 1!\n"); // Mensagem de erro se a posição não for permitida
    }
    
    // ** Verificando se navio 2 está dentro dos limites do tabuleiro - Vertical
    // Definindo a posição do navio 2 (linha 1, coluna E)
    posicao_navio2_i = 0;
    posicao_navio2_j = 4;
    posicao_permitida = 1; // Reseta a variável de permissão para o navio 2

    if (posicao_navio2_i + TAMANHO_NAVIO > TAMANHO_TABULEIRO || posicao_navio2_j >= TAMANHO_TABULEIRO)
    {
        posicao_permitida = 0; // Se a posição do navio 2 ultrapassar o tamanho do tabuleiro, não é permitido posicionar

    } else 
    {
        // Verifica se já existe um navio na posição
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[posicao_navio2_i + i][posicao_navio2_j] != 0) {
                posicao_permitida = 0; // Se já existe um navio na posição, não é permitido posicionar
                break;
            }
        }
    }
    
    // ** Inserindo o navio 2 no tabuleiro se a posição for permitida - Vertical
    // Definindo a posição do navio 2 se permitida
    if (posicao_permitida) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[posicao_navio2_i + i][posicao_navio2_j] = VALOR_NAVIO; // Insere o navio 2 no tabuleiro com o valor da constante
           
        }
    } else 
    {
        printf("Posição inválida para o Navio 2!\n"); // Mensagem de erro se a posição não for permitida
    }

    // ** Verificando se navio 3 está dentro dos limites do tabuleiro - Diagonal principal
    // Definindo a posição do navio 3 (linha 1, coluna G)
    posicao_navio3_i = 0;
    posicao_navio3_j = 6;
    posicao_permitida = 1; // Reseta a variável de permissão para o navio 3

    if (posicao_navio3_i + TAMANHO_NAVIO > TAMANHO_TABULEIRO || posicao_navio3_j + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
    {
        posicao_permitida = 0; // Se a posição do navio 3 ultrapassar o tamanho do tabuleiro, não é permitido posicionar

    } else 
    {
        // Verifica se já existe um navio na posição
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[posicao_navio3_i + i][posicao_navio3_j + i] != 0) {
                posicao_permitida = 0; // Se já existe um navio na posição, não é permitido posicionar
                printf("Posição inválida para o Navio 3!\n"); // Mensagem de erro se a posição não for permitida
                break;
            }
        }
    }

    // ** Inserindo o navio 3 no tabuleiro se a posição for permitida - Diagonal principal

    // Definindo a posição do navio 3
    if (posicao_permitida) {
       for (int i = posicao_navio3_i; i < posicao_navio3_i + TAMANHO_NAVIO; i++)
       {
            for (int j = posicao_navio3_j; j < posicao_navio3_j + TAMANHO_NAVIO; j++)
            {
                if (i - posicao_navio3_i == j - posicao_navio3_j) { // Verifica se é a diagonal principal
                    tabuleiro[posicao_navio3_i + i][posicao_navio3_j + i] = VALOR_NAVIO; // Insere o navio 3 no tabuleiro com o valor da constante
                }
            }
        }
    }

    // ** Verificando se navio 4 está dentro dos limites do tabuleiro - Diagonal secundária
    // Definindo a posição do navio 4 (linha 5, coluna E)
    posicao_navio4_i = 4; // Linha 5 corresponde ao indice 3 
    posicao_navio4_j = 3; // Coluna E corresponde ao indice 4
    posicao_permitida = 1; // Reseta a variavel de permissão para o navio 4

    //  verifica se ultrapassa os limites do tabuleiro e se a posição já está ocupada
    if (posicao_navio4_i + TAMANHO_NAVIO > TAMANHO_TABULEIRO || posicao_navio4_j - TAMANHO_NAVIO + 1 < 0)
    {
        posicao_permitida = 0;
    } else
    {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[posicao_navio4_i + i][posicao_navio4_j - i] != 0) {
                posicao_permitida = 0;
                break;
            }
        }
    }
    
    // ** inserindo o navio $ no tabuleiro se a posição for perrmitida - Diagonal secundário
    if (posicao_permitida)
    {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            for (int j = 0; j < TAMANHO_NAVIO; j++) {
                if (i == j) {
                    tabuleiro[posicao_navio4_i + i][posicao_navio4_j - j] = VALOR_NAVIO;
                }
            }
        }
    }
    
    
        
    // ** Exibindo o tabuleiro e os navios no console
    printf("** TABULEIRO BATALHA NAVAL **\n");

    printf("\n"); // Pula linha em branco para melhor visualização
    printf("   "); // Espaço para as colunas a insercão do cabeçalho
    
    // Loop para a impressão das colunas do tabuleiro
    for (int j = 0; j < 10; j++) {
        printf("%c ", coluna[j]); // Exibe as colunas de A a J
    }

    //  Loop para impressão das linhas do tabuleiro
    for (int i = 0; i < 10; i++)
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
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]); // Exibe o valor do tabuleiro   
        }  
        
    }

    printf("\n \n"); // Pula 2 linhas após imprimir o tabuleiro
     
        
    // TODO Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // TODO Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // **Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // TODO Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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
        
       
    
            
           
           
    

        
       



    

    
    

    

    



       
    
    
    
    

    
