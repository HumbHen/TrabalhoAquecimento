#include "matriz.hpp"
#include <fstream>
#include <iostream>

Matriz::Matriz() : linhas(0), colunas(0), posX(0), posY(0) {}

bool Matriz::carregarArquivo(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return false;
    }

    arquivo >> linhas >> colunas >> posX >> posY;

    dados.resize(linhas, vector<int>(colunas, 0));

    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (!(arquivo >> dados[i][j])) {
                cerr << "Erro ao ler a matriz." << endl;
                return false;
            }
        }
    }

    arquivo.close();
    return true;
}

void Matriz::salvarEstado(const string& nomeArquivo) const {
    ofstream arquivo(nomeArquivo, ios::app); // modo append
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita: " << nomeArquivo << endl;
        return;
    }

    for (const auto& linha : dados) {
        for (const auto& valor : linha) {
            arquivo << valor << " ";
        }
        arquivo << "\n";
    }
    arquivo << "\n"; // separação entre iterações

    arquivo.close();
}

void Matriz::imprimir() const {
    for (const auto& linha : dados) {
        for (const auto& valor : linha) {
            cout << valor << " ";
        }
        cout << endl;
    }
}
