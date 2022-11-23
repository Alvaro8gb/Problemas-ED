// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;


template <typename T>
bool resuelveCaso(bintree <T> const& binaryTree,vector <T> &v) {

    if (binaryTree.empty()) return true; 
    else {

        bool izq = resuelveCaso(binaryTree.left(),v);
        bool der =  resuelveCaso(binaryTree.right(),v);

        if (izq && der) v.push_back(binaryTree.root());
       
        return false;
        
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    bintree <int> binariTree;

    binariTree = leerArbol(-1);

    vector <int> v;

    if(!binariTree.empty())  resuelveCaso(binariTree,v);

    for (int x : v) cout << x << " ";
    cout << endl;

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