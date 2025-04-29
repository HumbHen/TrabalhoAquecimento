#include "incendio.hpp"


Incendio::Incendio(Matriz& matriz) : matriz(matriz) {
    proximoEstado = matriz.getDados(); // Inicializando o estado com os dados atuais
}

void Incendio::executarIteracao() {
    proximoEstado = matriz.getDados();

    for (int i = 0; i < matriz.getLinhas(); ++i) {
        for (int j = 0; j < matriz.getColunas(); ++j) {
            atualizarCelula(i, j, false, 0); // Exemplo sem vento
        }
    }

    matriz.setDados(proximoEstado); // Atualiza o estado da matriz
}

void Incendio::atualizarCelula(int x, int y, bool influenciaVento, int direcaoVento) {
    int estadoAtual = matriz.getDados()[x][y];

    if (estadoAtual == 1 && existeVizinhoEmChamas(x, y, influenciaVento, direcaoVento)) {
        proximoEstado[x][y] = 2; // Árvore saudável entra em chamas
    } else if (estadoAtual == 2) {
        proximoEstado[x][y] = 3; // Árvore em chamas vira queimada
    }
}

bool Incendio::existeVizinhoEmChamas(int x, int y, bool influenciaVento, int direcaoVento) {
    static const vector<pair<int, int>> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Direções ortogonais

    for (const auto& [dx, dy] : direcoes) {
        int nx = x + dx;
        int ny = y + dy;

        if (nx >= 0 && nx < matriz.getLinhas() && ny >= 0 && ny < matriz.getColunas()) {
            if (matriz.getDados()[nx][ny] == 2) {
                // Verificar influência do vento
                if (influenciaVento) {
                    // Exemplo: considera a direção do vento (0 para cima, 1 para baixo, etc.)
                    if ((direcaoVento == 0 && dx == -1) || 
                        (direcaoVento == 1 && dx == 1) || 
                        (direcaoVento == 2 && dy == -1) || 
                        (direcaoVento == 3 && dy == 1)) {
                        return true;
                    }
                } else {
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
            if (valor == 2) { // Verifica se há algum valor igual a 2 (árvore em chamas)
                return true;
            }
        }
    }
    return false;
}
