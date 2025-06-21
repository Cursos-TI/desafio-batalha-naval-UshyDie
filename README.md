# Batalha Naval - MateCheck

Este projeto simula um tabuleiro de Batalha Naval com funcionalidades de posicionamento de navios e aplicação de habilidades especiais com máscaras geométricas (cone, cruz, octaedro). Foi desenvolvido em C como parte de um desafio de lógica e estruturas de dados.

---

##  Funcionalidades

* Gera um tabuleiro 10x10 inicializado com água (valor 0)
* Aplica habilidades especiais (cone, cruz, octaedro) com máscaras 5x5
* Posiciona navios com tamanho 3 em diferentes direções:

  * Horizontal
  * Vertical
  * Diagonal Principal
  * Diagonal Secundária
* Valida posicionamento (fora dos limites e sobreposições)
* Exibe o tabuleiro com representação visual dos navios e habilidades

---

##  Constantes do Jogo

| Constante            | Valor | Significado                            |
| -------------------- | ----- | -------------------------------------- |
| `TAMANHO_TABULEIRO`  | 10    | Tamanho da matriz principal (10x10)    |
| `TAMANHO_NAVIO`      | 3     | Quantidade de células por navio        |
| `VALOR_NAVIO`        | 3     | Valor que representa o navio na matriz |
| `TAMANHO_HABILIDADE` | 5     | Tamanho da máscara de habilidades      |
| `VALOR_HABILIDADE`   | 1     | Valor aplicado pelas habilidades       |

---

##  Exemplo de Saída do Tabuleiro

```bash
** TABULEIRO BATALHA NAVAL **
   A B C D E F G H I J
1  0 0 0 0 0 0 0 0 0 3
2  0 0 0 0 0 0 0 0 3 0
3  1 0 1 0 0 0 0 3 0 0
4  1 1 1 0 0 0 3 0 0 0
5  1 0 1 0 0 3 0 0 0 0
6  1 1 1 0 0 0 0 0 0 0
7  0 1 0 1 0 0 0 1 0 0
8  0 0 1 0 1 0 0 1 0 0
9  0 0 0 1 0 1 0 1 0 0
10 0 0 0 0 0 0 0 0 0 0
```

Legenda:

* `0` = água
* `1` = célula atingida por habilidade
* `3` = parte de navio

---

##  Como Compilar e Executar

1. Compile com o GCC:

   ```bash
   gcc -o batalha batalha_naval.c
   ```
2. Execute no terminal:

   ```bash
   ./batalha
   ```

Funciona em ambientes Linux, WSL, GitHub Codespaces, VS Code com terminal.

---

##  Habilidades Disponíveis

### Habilidade: Cone

* Aplica uma máscara triangular invertida (ponta para baixo)
* Posicionada na coordenada (2,2)

### Habilidade: Octaedro

* Aplica uma forma em losango
* Posicionada na coordenada (7,2)

### Habilidade: Cruz

* Aplica uma cruz vertical e horizontal
* Posicionada na coordenada (6,7)

---

##  Validações e Regras

* Nenhuma habilidade ou navio pode ultrapassar os limites do tabuleiro
* Habilidades só são aplicadas se não sobrepõem outras estruturas
* Cada navio ocupa 3 espaços e tem sua direção definida
* Direções: `HORIZONTAL`, `VERTICAL`, `DIAGONAL_PRINCIPAL`, `DIAGONAL_SECUNDARIA`

---

##  Licença

Projeto educativo sem fins comerciais.

---



