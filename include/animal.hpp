#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "matriz.hpp"
#include <utility>

using namespace std;

class Animal {
public:
    Animal(int x, int y);

    int getPassosPercorridos() const;

    
    void mover(Matriz& matriz);
    bool estaSeguro() const; 
    void registrarEstado() const; 

    
    pair<int, int> getPosicao() const; 

private:
    int posX; 
    int posY; 
    int passosPercorridos;
    int encontrosComAgua; 
    int iteracaoSemMovimento; 

    pair<int, int> melhorPosicao(const Matriz& matriz); 
    bool podeMover(int x, int y, const Matriz& matriz) const; 
};

#endif
