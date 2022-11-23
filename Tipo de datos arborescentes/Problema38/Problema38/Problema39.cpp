// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "bintree_eda.h"


using namespace std;

struct tSol {
    int  caudal, numTramosNavegables;
};
inline std::ostream& operator << (std::ostream& out, tSol const& sol) {

   out << sol.numTramosNavegables <<"\n";

    return out;
}

tSol tramosNavegabes(bintree <int> const& binaryTree) {

    if (binaryTree.empty()) return { 0,0 };
    else {

        tSol izq = tramosNavegabes(binaryTree.left());
        tSol der = tramosNavegabes(binaryTree.right());

        if (binaryTree.left().empty() && binaryTree.right().empty() && binaryTree.root() == 0) return { 1,0 };
      //  if (der.caudal == 0 &&  izq.caudal == 0 && binaryTree.root() == 0) return { 1,0 };


        int caudal = max(izq.caudal + der.caudal - binaryTree.root(), 0);

        if (izq.caudal >= 3 && der.caudal >= 3) return { caudal,izq.numTramosNavegables + der.numTramosNavegables + 2 };
        else if (izq.caudal >= 3) return { caudal,izq.numTramosNavegables + der.numTramosNavegables + 1 };
        else if (der.caudal >= 3) return { caudal,izq.numTramosNavegables + der.numTramosNavegables + 1 };
        else return { caudal,izq.numTramosNavegables + der.numTramosNavegables };

    }

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {

    bintree <int> binaryTree = leerArbol(-1);

    cout << tramosNavegabes(binaryTree);
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