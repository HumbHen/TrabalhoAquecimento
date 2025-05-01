#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "matriz.hpp"
#include <utility>

const int iX = 2;
const int iY = 5;

using namespace std;

class Animal {
public:
    Animal(int x, int y);

    int getPassosPercorridos() const;
    int getEncontrosComAgua() const;

    
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
