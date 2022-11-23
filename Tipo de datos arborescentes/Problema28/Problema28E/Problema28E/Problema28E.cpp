// ALVARO GARCIA BARRAGAN
// A28


#include <fstream>
#include "bintree_eda.h"

using namespace std;


template <typename T>
T minimoconIterador(bintree <T> const& binaryTree) {

    T min = binaryTree.root(); // en casa de vacio lanza excepcion

    for (T elem : binaryTree) min = elem < min ? elem : min;

    return min;
}

template <typename T>
T minimo(bintree <T> const& binaryTree) {
    if (binaryTree.empty()) throw new invalid_argument("Arbol vacio no existe minimo");
    else if (binaryTree.right().empty() && binaryTree.left().empty()) return binaryTree.root();
    else if (!binaryTree.right().empty() && binaryTree.left().empty()) {

        T minDer = minimo(binaryTree.right());
        return min(binaryTree.root(), minDer);

    }
    else if (!binaryTree.left().empty() && binaryTree.right().empty()) {

        T minIzq = minimo(binaryTree.left());
        return min(binaryTree.root(), minIzq);
    }
    else {
        T minIzq = minimo(binaryTree.left());
        T minDer = minimo(binaryTree.right());

        return min({ minIzq, minDer,binaryTree.root() });
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {

    char type;

    cin >> type;

    if (!cin)return false;

    if (type == 'N') {
        bintree <int> binaryTree = leerArbol(-1);
        //cout << minimoconIterador(binariTree) << endl;
        cout << minimo(binaryTree) << endl;
    }
    else if (type == 'P') {
        string delimitador(1, '#');
        bintree <string> binaryTree = leerArbol(delimitador);
        //cout << minimoconIterador(binariTree) << endl;
        cout << minimo(binaryTree) << endl;
    }
    else throw new domain_error("Tipo no detectado validos : N y P");
    
   
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
   
    
    while( resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}