// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int numEquipos, numExcursionistas;
};
inline std::ostream& operator << (std::ostream& out, tSol const& sol) {
    out << sol.numEquipos << " " << sol.numExcursionistas << '\n';
    return out;
}
tSol resolver(bintree <int> const& binaryTree) {

    if (binaryTree.empty()) return { 0,0 };
    else {

        tSol izq = resolver(binaryTree.left());
        tSol der = resolver(binaryTree.right());

        if (izq.numEquipos == 0 && der.numEquipos == 0 && binaryTree.root() != 0) return { 1,binaryTree.root() };
        

        return{ izq.numEquipos + der.numEquipos, max(izq.numExcursionistas,der.numExcursionistas) + binaryTree.root()};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {

    bintree <int> binaryTree = leerArbol(-1);

    cout << resolver(binaryTree) ;

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