#include "incendio.hpp"
#include "config.hpp"

Incendio::Incendio(Matriz& matriz) : matriz(matriz) {
    proximoEstado = matriz.getDados(); 
}

void Incendio::executarIteracao() {
    proximoEstado = matriz.getDados(); 

    for (int i = 0; i < matriz.getLinhas(); ++i) {
        for (int j = 0; j < matriz.getColunas(); ++j) {
            atualizarCelula(i, j); 
        }
    }

    matriz.setDados(proximoEstado); 
}

void Incendio::atualizarCelula(int x, int y) {
    int estadoAtual = matriz.getDados()[x][y];

    if (estadoAtual == 1) {
        
        if (existeVizinhoEmChamas(x, y)) {
            proximoEstado[x][y] = 2; // Árvore saudável (1) vira árvore em chamas (2)
        }
    } else if (estadoAtual == 2) {

        proximoEstado[x][y] = 3; // Árvore em chamas (2) vira árvore queimada (3)
    }
}

bool Incendio::existeVizinhoEmChamas(int x, int y) {
    static const vector<pair<int, int>> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    auto dados = matriz.getDados();

    for (const auto& [dx, dy] : direcoes) {
        int nx = x + dx;
        int ny = y + dy;

        if (nx >= 0 && nx < matriz.getLinhas() && ny >= 0 && ny < matriz.getColunas()) {
            if (dados[nx][ny] == 2) { 
                if (influenciaVento) { 

                    for (int direcao : direcaoVento) {
                        if ((direcao == 0 && dx == 1) || // Vento para cima
                            (direcao == 1 && dx == -1) ||  // Vento para baixo
                            (direcao == 2 && dy == 1) || // Vento para a esquerda
                            (direcao == 3 && dy == -1)) {  // Vento para a direita
                            return true;
                        }
                    }
                } else {
                    // Sem vento
                    return true;
                }
            }
        }
    }
    return false;
}

bool Incendio::temFogo(const Matriz& matriz) {
    auto dados = matriz.getDados(); 
    for (const auto& linha : dados) {
        for (int valor : linha) {
            if (valor == 2) { // Verifica se tem fogo
                return true;
            }
        }
    }
    return false; // Retorna falso se não achar fogo
}
