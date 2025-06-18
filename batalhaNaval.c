#include <stdio.h>

// Desafio Batalha Naval - MateCheck

int main() {
    // **  Nível Novato - Posicionamento dos Navios

    // ** Declarando as variáveis necessárias para o jogo.

    char coluna[10]; // Colunas do tabuleiro
    int linha[10]; // Linhas do tabuleiro, de 1 a 10

    int tabuleiro[10][10]; // Declaração da  matriz bidimensional para representar o tabuleiro.
    int tamanho_tabuleiro = 10; // Armazena o tamanho do tabuleiro, 10x10
    
    int navio1[3]; // Declarando o vetor do navio 1 tamanho 3 - representando as partes do navio
    int posicao_navio1_i = 2, posicao_navio1_j = 5; // Variável para armazenar as coordenadas do navio 1 (j para coluna, i para linha)
    int tamanho_navio1 = 3; // Variável para armazenar o tamanho do navio 1 (3 partes)

    int navio2 [3]; // Declarando o vetor do navio 2 tamanho 3 - representando as partes do navio
    int posicao_navio2_i = 3 , posicao_navio2_j = 2; // Variável para armazenar as coordenadas do navio 2 (j para coluna, i para linha)
    int tamanho_navio2 = 3; // Variável para armazenar o tamanho do navio 2 (3 partes)

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

    for (int i = 0; i < 3; i++) //Percorre as linhas do vetor
    {
        navio1[i] = 3; // Inicializa o navio com 3 representando parte do navio
    }
        
    // Inicializando o navio 2

    for (int i = 0; i < 3; i++) //Percorre as linhas do vetor
    {
        navio2[i] = 3; // Inicializa o navio com 3 representando parte do navio
    }


    // ** Verificando se navio 1 está dentro dos limites do tabuleiro - Horizontal
    if (posicao_navio1_j + tamanho_navio1 > tamanho_tabuleiro)
    {
        posicao_permitida = 0; // Se a posição do navio 1 ultrapassar o tamanho do tabuleiro, não é permitido posicionar
    } else {
        // Verifica se já existe um navio na posição
        for (int i = 0; i < tamanho_navio1; i++) {
            if (tabuleiro[posicao_navio1_i][posicao_navio1_j + i] != 0) {
                posicao_permitida = 0; // Se já existe um navio na posição, não é permitido posicionar
                break;
            }
        }
    }
    
    // ** Inserindo o navio 1 no tabuleiro se a posição for permitida - Horizontal
    // Definindo a posição do navio 1
    if (posicao_permitida) {
        for (int i = 0; i < tamanho_navio1; i++) {
            tabuleiro[posicao_navio1_i][posicao_navio1_j + i] = navio1[i]; // Insere o navio 1 no tabuleiro
            // printf("Navio 1 posicionado em: %c%d\n", coluna[posicao_navio1_j + i], linha[posicao_navio1_i]); // Exibe a posição do navio
        }
    } else {
        printf("Posição inválida para o Navio 1!\n"); // Mensagem de erro se a posição não for permitida
    }
    


    // ** Verificando se navio 2 está dentro dos limites do tabuleiro - Vertical
    if (posicao_navio2_i + tamanho_navio2 > tamanho_tabuleiro)
    {
        posicao_permitida = 0; // Se a posição do navio 2 ultrapassar o tamanho do tabuleiro, não é permitido posicionar
    } else {
        // Verifica se já existe um navio na posição
        for (int i = 0; i < tamanho_navio2; i++) {
            if (tabuleiro[posicao_navio2_i + i][posicao_navio2_j] != 0) {
                posicao_permitida = 0; // Se já existe um navio na posição, não é permitido posicionar
                break;
            }
        }
    }
    
    // ** Inserindo o navio 2 no tabuleiro se a posição for permitida - Vertical
    // Definindo a posição do navio 2
    if (posicao_permitida) {
        for (int i = 0; i < tamanho_navio2; i++) {
            tabuleiro[posicao_navio2_i + i][posicao_navio2_j] = navio2[i]; // Insere o navio 2 no tabuleiro
            // printf("Navio 2 posicionado em: %c%d\n", coluna[posicao_navio2_j], linha[posicao_navio2_i + i]); // Exibe a posição do navio
        }
    } else {
        printf("Posição inválida para o Navio 2!\n"); // Mensagem de erro se a posição não for permitida
    }


    // ** Exibindo o tabuleiro e os navios no console
    printf("** TABULEIRO BATALHA NAVAL **\n");

    printf("\n"); // Pula linha em branco para melhor visualização
    printf("   "); // Espaço para as colunas
    
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
     
        
        
        
       



    

    
    

    

    



       
    
    // Sugestão: Posicione o navio 1 no tabuleiro, por exemplo, nas coordenadas (0, 0), (0, 1), (0, 2).
    
    

    
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
