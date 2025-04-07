#include <stdio.h>

// Constantes para o tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se é possível posicionar o navio sem sair dos limites ou sobrepor outro
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int vertical) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = vertical ? linha + i : linha;
        int c = vertical ? coluna : coluna + i;

        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO || tabuleiro[l][c] != 0) {
            return 0; // Fora dos limites ou já ocupado
        }
    }
    return 1;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int vertical) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = vertical ? linha + i : linha;
        int c = vertical ? coluna : coluna + i;
        tabuleiro[l][c] = 3;
    }
}

// Função para imprimir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializar o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (fixas, conforme o enunciado)
    int linhaNavio1 = 2, colunaNavio1 = 4; // Horizontal
    int linhaNavio2 = 5, colunaNavio2 = 7; // Vertical

    // Validar e posicionar o navio horizontal
    if (podePosicionar(tabuleiro, linhaNavio1, colunaNavio1, 0)) {
        posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, 0);
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
    }

    // Validar e posicionar o navio vertical
    if (podePosicionar(tabuleiro, linhaNavio2, colunaNavio2, 1)) {
        posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, 1);
    } else {
        printf("Erro ao posicionar navio vertical!\n");
    }

    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
