#include "matriz.hpp"
#include "incendio.hpp"
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

    cout << endl;

    for (int i = 1; i <= numInt; i++ ) {

        incendio.executarIteracao();

        cout << "Estado após " << i << " interacoes, a propagação do incêndio: " << endl;
        matriz.imprimir();
    
        // Salva estado atualizado
        matriz.salvarEstado("output.dat");

        cout << " \n------------------------\n " << endl;

        if (!incendio.temFogo(matriz)) {
            cout << "Incêndio extinto após " << i << " interações." << endl;
            break;
        }

    }

    return 0;
}
