#include "matriz.hpp"
#include "incendio.hpp"
#include "animal.hpp"
#include "config.hpp"
#include <iostream>

using namespace std;

int main() {

    Matriz matriz;

    if (!matriz.carregarArquivo()) {
        cerr << "Erro ao carregar o arquivo de entrada." << endl;
        return 1;
    }

    cout << "Matriz carregada com sucesso:" << endl;
    matriz.imprimir();

    Incendio incendio(matriz);

    Animal animal(2, 5);

    for (int i = 1; i <= numInt; i++) {
        cout << "\n------------------------\n" << endl;;

        // Movimentando animal
        animal.mover(matriz);

        // Verifica se o animal está em uma posição segura
        if (!animal.estaSeguro()) {
            cout << "Animal cercado" << i << endl;
            break;
        }

        incendio.executarIteracao();

        cout << "Estado da matriz após " << i << " interações:" << endl;
        matriz.imprimir();

        matriz.salvarEstado("output.dat");

        if (!incendio.temFogo(matriz)) {
            cout << "Incêndio extinto após " << i << " interações." << endl;
            break;
        }
    }

    cout << "\n------------------------\n" << endl;
    cout << "Simulação finalizada." << endl;
    cout << "Total de passos percorridos pelo animal: " << animal.getPassosPercorridos() << endl;
    cout << "Posição final do animal: (" << animal.getPosicao().first << ", " << animal.getPosicao().second << ")" << endl;

    return 0;
}
