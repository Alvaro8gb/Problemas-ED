// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;


struct tSol {
    int altura, diametro;
};
inline std::ostream& operator << (std::ostream& out, tSol const& sol) {
    out << sol.diametro << '\n';
    return out;
}
template <class T>
tSol diametro(bintree <T> const& binaryTree) {

    if (binaryTree.empty()) return{ 0,0 };
    else {

        tSol izq = diametro(binaryTree.left());
        tSol der = diametro(binaryTree.right());

        return{ max(izq.altura,der.altura) + 1, max({izq.diametro,der.diametro,izq.altura + der.altura + 1}) };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {

    bintree <char> binaryTree = leerArbol('.');

    cout << diametro(binaryTree);
   
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