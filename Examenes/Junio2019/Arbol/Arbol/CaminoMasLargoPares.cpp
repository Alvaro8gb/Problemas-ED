// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;


struct tSol {
    int altura, diametroMax;
};
inline std::ostream& operator << (std::ostream& out, tSol const& sol) {
    out << sol.diametroMax << '\n';
    return out;
}
template <class T>
tSol caminoMasLargo(bintree <T> const& binaryTree) {

    if (binaryTree.empty()) return{ 0,0 };
    else {

        tSol izq = caminoMasLargo(binaryTree.left());
        tSol der = caminoMasLargo(binaryTree.right());

        if (binaryTree.root() % 2 == 0)  return { max(izq.altura, der.altura) + 1, max({izq.altura+ der.altura + 1,der.diametroMax,izq.diametroMax }) }; 
        else  return { 0, max(der.diametroMax,izq.diametroMax) };
        
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {

    bintree <int> binaryTree = leerArbol(-1);

    cout << caminoMasLargo(binaryTree);

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