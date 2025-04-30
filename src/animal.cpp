#include "animal.hpp"
#include <iostream>

Animal::Animal(int x, int y) : posX(x), posY(y), passosPercorridos(0), encontrosComAgua(0), iteracaoSemMovimento(0) {}

void Animal::mover(Matriz& matriz) {

    auto dados = matriz.getDados();
    if (dados[posX][posY] == 4) {

        encontrosComAgua++;
        dados[posX][posY] = 0;

        static const vector<pair<int, int>> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& [dx, dy] : direcoes) {
            int nx = posX + dx;
            int ny = posY + dy;
            if (nx >= 0 && nx < matriz.getLinhas() && ny >= 0 && ny < matriz.getColunas()) {
                if (dados[nx][ny] != 4) { 
                    dados[nx][ny] = 1;
                }
            }
        }

        matriz.setDados(dados);
        return;
    }

    auto novaPosicao = melhorPosicao(matriz);
    if (novaPosicao.first != posX || novaPosicao.second != posY) {
        
        posX = novaPosicao.first;
        posY = novaPosicao.second;
        passosPercorridos++;
        iteracaoSemMovimento = 0;
    } else {
        
        iteracaoSemMovimento++;
    }

    matriz.setDados(dados);
}

bool Animal::estaSeguro() const {
    return iteracaoSemMovimento <= 3;
}

pair<int, int> Animal::getPosicao() const {
    return {posX, posY};
}

pair<int, int> Animal::melhorPosicao(const Matriz& matriz) {
    auto dados = matriz.getDados();
    static const vector<pair<int, int>> direcoes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    pair<int, int> melhorPosicao = {posX, posY};
    int melhorPrioridade = 100; // Valor alto para definir prioridade (quanto menor, melhor)

    for (const auto& [dx, dy] : direcoes) {
        int nx = posX + dx;
        int ny = posY + dy;

        if (nx >= 0 && nx < matriz.getLinhas() && ny >= 0 && ny < matriz.getColunas()) {
            int valor = dados[nx][ny];
            int prioridade;

            // Define a prioridade com base no valor da célula
            if (valor == 4) prioridade = 1; // Melhor opção: água
            else if (valor == 0 || valor == 1) prioridade = 2; // Opções intermediárias: área vazia ou árvore saudável
            else if (valor == 3) prioridade = 3; // Pior opção: árvore queimada
            else prioridade = 100; // Valores não esperados

            if (prioridade < melhorPrioridade) {
                melhorPrioridade = prioridade;
                melhorPosicao = {nx, ny};
            }
        }
    }

    return melhorPosicao;
}

bool Animal::podeMover(int x, int y, const Matriz& matriz) const {
    auto dados = matriz.getDados();
    if (x < 0 || x >= matriz.getLinhas() || y < 0 || y >= matriz.getColunas()) {
        return false; // Fora dos limites da matriz
    }
    int valor = dados[x][y];
    return (valor == 0 || valor == 1 || valor == 4);
}

int Animal::getPassosPercorridos() const {
    return passosPercorridos;
}