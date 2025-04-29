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

    vector<vector<int>> getDados() const;
    void setDados(const vector<vector<int>>& novosDados);
    int getLinhas() const;
    int getColunas() const;

private:
    int linhas;
    int colunas;
    int posX;
    int posY;
    vector<vector<int>> dados;
};

#endif