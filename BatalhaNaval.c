#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAM 10

// Valor usado para representar um navio
#define NAVIO 3

// Função para verificar se a posição está livre
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, char tipo[]) {
    // direcao: 0 = horizontal, 1 = vertical, 2 = diagonal principal, 3 = diagonal secundária
    for (int i = 0; i < 3; i++) {
        int l = linha;
        int c = coluna;

        if (direcao == 0) c += i;
        else if (direcao == 1) l += i;
        else if (direcao == 2) { l += i; c += i; }
        else if (direcao == 3) { l += i; c -= i; }

        // Verifica se está fora do tabuleiro
        if (l < 0 || l >= TAM || c < 0 || c >= TAM) return 0;

        // Verifica se já tem um navio
        if (tabuleiro[l][c] != 0) return 0;
    }
    return 1;
}

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao) {
    for (int i = 0; i < 3; i++) {
        if (direcao == 0) tabuleiro[linha][coluna + i] = NAVIO;               // Horizontal
        else if (direcao == 1) tabuleiro[linha + i][coluna] = NAVIO;         // Vertical
        else if (direcao == 2) tabuleiro[linha + i][coluna + i] = NAVIO;     // Diagonal principal
        else if (direcao == 3) tabuleiro[linha + i][coluna - i] = NAVIO;     // Diagonal secundária
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Tabuleiro 10x10:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};  // Inicializa com 0 (água)

    // Coordenadas e direções definidas no código (sem entrada do usuário)
    // Formato: linha, coluna, direção
    int navios[4][3] = {
        {1, 1, 0},  // Horizontal
        {4, 2, 1},  // Vertical
        {0, 0, 2},  // Diagonal principal
        {0, 9, 3}   // Diagonal secundária
    };

    // Posiciona os navios
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int direcao = navios[i][2];

        if (podePosicionar(tabuleiro, linha, coluna, direcao, "")) {
            posicionarNavio(tabuleiro, linha, coluna, direcao);
        } else {
            printf("Erro: não foi possível posicionar o navio %d (linha %d, coluna %d, direcao %d).\n", i + 1, linha, coluna, direcao);
        }
    }

    // Exibe o tabuleiro final
    printf("\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
