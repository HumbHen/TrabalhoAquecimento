#include "matriz.hpp"
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

    // Simulação de uma iteração - neste exemplo, só salva como está
    matriz.salvarEstado("output.dat");

    cout << "Estado salvo em output.dat" << endl;

    return 0;
}