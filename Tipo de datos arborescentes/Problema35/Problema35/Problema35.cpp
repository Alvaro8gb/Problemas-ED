// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "bintree_eda.h"


using namespace std;

class par {
public :
    bool operator()(int const& n) {
        return n % 2 == 0;
    }
};

 struct tSol {
    int longAct, longMax;
};
 inline std::ostream& operator << (std::ostream& out, tSol const& sol) {
     out << sol.longMax << "\n";

     return out;
 }

template <typename T, typename P>
tSol longCaminoMasLargo(bintree <T> const& binaryTree,P prop) {

    if (binaryTree.empty()) return { 0,0 };
    else {

        tSol izq = longCaminoMasLargo(binaryTree.left(), prop);
        tSol der = longCaminoMasLargo(binaryTree.right(), prop);

        if (prop(binaryTree.root())) return { max(izq.longAct , der.longAct) + 1, max({izq.longAct + der.longAct + 1,der.longMax ,izq.longMax}) };
        else return { 0,max(der.longMax ,izq.longMax) };

    }

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {

    bintree <int> binaryTree = leerArbol(-1);

    cout << longCaminoMasLargo( binaryTree,par());
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