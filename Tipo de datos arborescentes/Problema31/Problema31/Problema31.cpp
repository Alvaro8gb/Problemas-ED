// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    bool zurdo;
    int numDescendientes;
   
};
inline std::ostream& operator << (std::ostream& out, tSol const& sol) {
    if(sol.zurdo)   out << "SI"<< '\n';
    else  out << "NO" << '\n';

    return out;
}
template <class T >
tSol esZurdo(bintree <T> const& binaryTree) {

    if (binaryTree.empty()) return { true,0 };
    else {

        tSol izq = esZurdo(binaryTree.left());
        tSol der = esZurdo(binaryTree.right());

        if (izq.numDescendientes == 0 && der.numDescendientes == 0) return {true,1};
        else return {  izq.zurdo && der.zurdo && izq.numDescendientes  > der.numDescendientes, izq.numDescendientes + der.numDescendientes + 1 };

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {

    bintree <char> binaryTree = leerArbol('.');

    cout << esZurdo(binaryTree);

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