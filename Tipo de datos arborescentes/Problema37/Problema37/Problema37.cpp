// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "bintree_eda.h"


using namespace std;

struct tSol {
    bool pareado;
    int numNodosPares;
};
inline std::ostream& operator << (std::ostream& out, tSol const& sol) {
   
    if (sol.pareado) out << "SI\n";
    else out << "NO\n";

    return out;
}

tSol pareado(bintree <int> const& binaryTree) {

    if (binaryTree.empty()) return { true,0 };
    else {

        tSol izq = pareado(binaryTree.left());
        tSol der = pareado(binaryTree.right());

        int numNodosPares = izq.numNodosPares + der.numNodosPares;
        if (binaryTree.root() % 2 == 0) numNodosPares++;

        return { izq.pareado && der.pareado && abs(izq.numNodosPares - der.numNodosPares) <= 1 ,numNodosPares };
    }

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {

    bintree <int> binaryTree = leerArbol(-1);

    cout << pareado(binaryTree);
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