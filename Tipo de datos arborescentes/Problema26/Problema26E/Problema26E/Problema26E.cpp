// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int numNodos, numHojas, altura;
};

inline ostream& operator << (std::ostream& out, tSol const& sol) {
     out << sol.numNodos << ' ' << sol.numHojas << " " << sol.altura << ' ' << '\n';
     return out;
 }
template <typename T>
tSol resuelveCaso(bintree <T> const &binaryTree) {
    
    if (binaryTree.empty()) return { 0,0,0 };
    else { 

        tSol left = resuelveCaso(binaryTree.left());
        tSol right = resuelveCaso(binaryTree.right());
        tSol sol;

        sol.altura = max(left.altura,right.altura)+1;

        sol.numNodos = left.numNodos + right.numNodos + 1;

        sol.numHojas = left.numHojas + right.numHojas;

        if (left.numHojas == 0 && right.numHojas == 0) sol.numHojas++;
  
        return sol;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    bintree <char> binariTree;

    binariTree = leerArbol('.');

    cout << resuelveCaso(binariTree);

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

    for (int i = 0; i < numCasos; i++) resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}