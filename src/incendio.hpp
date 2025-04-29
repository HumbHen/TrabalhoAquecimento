#ifndef INCENDIO_HPP
#define INCENDIO_HPP

#include "matriz.hpp"
#include <vector>

using namespace std;

class Incendio {
public:
    Incendio(Matriz& matriz); // Construtor que recebe a matriz
    void aplicarRegras(bool influenciaVento, int direcaoVento);
    void executarIteracao();
    bool temFogo (const Matriz& matriz);

private:
    Matriz& matriz;
    vector<vector<int>> proximoEstado; // Estado atualizado da matriz

    void atualizarCelula(int x, int y, bool influenciaVento, int direcaoVento);
    bool existeVizinhoEmChamas(int x, int y, bool influenciaVento, int direcaoVento);
};

#endif
