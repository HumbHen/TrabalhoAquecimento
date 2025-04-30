#ifndef INCENDIO_HPP
#define INCENDIO_HPP

#include "matriz.hpp"
#include <vector>

using namespace std;

class Incendio {
public:
    Incendio(Matriz& matriz);
    void executarIteracao();
    bool temFogo (const Matriz& matriz);

private:
    Matriz& matriz;
    vector<vector<int>> proximoEstado;

    void atualizarCelula(int x, int y);
    bool existeVizinhoEmChamas(int x, int y);
};

#endif
