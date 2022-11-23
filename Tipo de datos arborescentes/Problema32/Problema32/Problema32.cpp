// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int alturaAct, alturaMax;
};

inline std::ostream& operator << (std::ostream& out, tSol const& sol) {
    out << sol.alturaMax << "\n";

    return out;
}
tSol alturaMaxArbolCompleto(bintree <char> const& binaryTree) {

    if (binaryTree.empty()) return { 0,0 };
    else {

        tSol izq = alturaMaxArbolCompleto(binaryTree.left());
        tSol der = alturaMaxArbolCompleto(binaryTree.right());

        int alturaActual = min(der.alturaAct, izq.alturaAct) + 1; // puede ser que un lado sea mas largo que otro

        if (izq.alturaAct == der.alturaAct) return { alturaActual , max({alturaActual ,izq.alturaMax,der.alturaMax}) };
        else return { alturaActual ,max(der.alturaMax ,izq.alturaMax) };

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {

    bintree <char> binaryTree = leerArbol('.');

  
    cout << alturaMaxArbolCompleto(binaryTree);

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int numCasos;

    cin >> numCasos;

    for (int i = 0; i < numCasos; i++)  resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}