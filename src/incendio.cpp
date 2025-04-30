#include "incendio.hpp"
#include "config.hpp" // Inclui configurações globais definidas em config.hpp

Incendio::Incendio(Matriz& matriz) : matriz(matriz) {
    proximoEstado = matriz.getDados(); // Inicializa o estado com os dados atuais
}

void Incendio::executarIteracao() {
    proximoEstado = matriz.getDados(); // Copia o estado atual para ser atualizado

    for (int i = 0; i < matriz.getLinhas(); ++i) {
        for (int j = 0; j < matriz.getColunas(); ++j) {
            atualizarCelula(i, j); // Atualiza cada célula conforme as regras
        }
    }

    matriz.setDados(proximoEstado); // Atualiza a matriz com o novo estado
}

void Incendio::atualizarCelula(int x, int y) {
    int estadoAtual = matriz.getDados()[x][y];

    // Aplica as regras de propagação
    if (estadoAtual == 1) {
        // Árvore saudável entra em chamas se houver vizinho em chamas
        if (existeVizinhoEmChamas(x, y)) {
            proximoEstado[x][y] = 2; // Árvore saudável (1) vira árvore em chamas (2)
        }
    } else if (estadoAtual == 2) {
        // Árvore em chamas torna-se queimada
        proximoEstado[x][y] = 3; // Árvore em chamas (2) vira árvore queimada (3)
    }
}

bool Incendio::existeVizinhoEmChamas(int x, int y) {
    static const vector<pair<int, int>> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Direções ortogonais
    auto dados = matriz.getDados();

    for (const auto& [dx, dy] : direcoes) {
        int nx = x + dx;
        int ny = y + dy;

        // Verifica se a célula vizinha está dentro dos limites
        if (nx >= 0 && nx < matriz.getLinhas() && ny >= 0 && ny < matriz.getColunas()) {
            if (dados[nx][ny] == 2) { // Se a célula vizinha está em chamas (2)
                if (influenciaVento) { 
                    // Considera o impacto do vento (somente direções especificadas)
                    for (int direcao : direcaoVento) {
                        if ((direcao == 0 && dx == 1) || // Vento para cima
                            (direcao == 1 && dx == -1) ||  // Vento para baixo
                            (direcao == 2 && dy == 1) || // Vento para a esquerda
                            (direcao == 3 && dy == -1)) {  // Vento para a direita
                            return true;
                        }
                    }
                } else {
                    // Sem vento: qualquer vizinho em chamas propaga o fogo
                    return true;
                }
            }
        }
    }
    return false;
}

bool Incendio::temFogo(const Matriz& matriz) {
    auto dados = matriz.getDados(); // Copia os dados da matriz
    for (const auto& linha : dados) {
        for (int valor : linha) {
            if (valor == 2) { // Verifica se há pelo menos uma célula com fogo ativo (2)
                return true;
            }
        }
    }
    return false; // Retorna falso se nenhuma célula em chamas for encontrada
}
