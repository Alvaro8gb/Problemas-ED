
// ALVARO GARCIA BARRAGAN
// A28

//Bibiotecas inlcuidas en bintree :  <memory>   , <stdexcept> , <stack>  ,<vector>,  <queue>,  <iostream>

#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    bool completo, semiCompleto;
    int altura;
};

inline std::ostream& operator << (std::ostream& out, tSol const& sol) {
    if (sol.completo)   out << "COMPLETO" << '\n';
    else if (sol.semiCompleto)  out << "SEMICOMPLETO" << '\n';
    else out << "NADA\n";

    return out;
}

template <typename T>
tSol resolver(bintree <T> const& arbol) {

   if(arbol.empty()) return {true,true,0};
   else {

       tSol izq = resolver(arbol.left());
       tSol der = resolver(arbol.right());

       if (izq.altura == der.altura && izq.completo && der.completo) return { true,true,izq.altura + 1 };
       else if (izq.altura == der.altura + 1 && izq.semiCompleto && der.completo) return { false,true,izq.altura + 1 };
       else if (izq.altura == der.altura && izq.completo && der.semiCompleto) return { false,true,izq.altura + 1 };
       else return { false, false, 0 };
   }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {

    bintree <char> binaryTree = leerArbol('.');

   cout <<  resolver(binaryTree);
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