#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <vector>
#include <string>

using namespace std;

class Matriz {
public:
    Matriz();
    bool carregarArquivo(const string& nomeArquivo = "input.dat");
    void salvarEstado(const string& nomeArquivo) const;
    void imprimir() const;

private:
    int linhas;
    int colunas;
    int posX;
    int posY;
    vector<vector<int>> dados;
};

#endif