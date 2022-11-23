// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"


using namespace std;

struct tSol {
    bool arbolDeBusqueda;
    int max,min;
   
};
inline std::ostream& operator << (std::ostream& out, tSol const& sol) {

    if(sol.arbolDeBusqueda) out << "SI\n";
    else out << "NO\n";

    return out;
}

tSol resolver(bintree <int> const& binaryTree) {

    if (binaryTree.empty()) return { true,{},{} };
    else if (binaryTree.left().empty() && binaryTree.right().empty()) return { true,binaryTree.root(),binaryTree.root() };
    else if (binaryTree.left().empty()) {
        tSol der = resolver(binaryTree.right());
        return { der.arbolDeBusqueda && binaryTree.root() < der.min , max(binaryTree.root() , der.max) , min(binaryTree.root() , der.min) };

    }
    else if (binaryTree.right().empty()) {
        tSol izq = resolver(binaryTree.left());
        return { izq.arbolDeBusqueda && binaryTree.root() > izq.max, max(binaryTree.root(),izq.max) , min(binaryTree.root() , izq.min) };

    }
    else {

        tSol izq = resolver(binaryTree.left());
        tSol der = resolver(binaryTree.right());
        
        return { izq.arbolDeBusqueda && der.arbolDeBusqueda && binaryTree.root() > izq.max && binaryTree.root() < der.min  ,  max( {izq.max, binaryTree.root() , der.max} ) ,  min( {der.min, binaryTree.root() , izq.min} ) };    
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {

    bintree <int> binaryTree = leerArbol(-1);

    cout << resolver(binaryTree);
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
