//ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

template <class T>
class bintree_ext : public bintree < T > {
    using Link = typename bintree < T > ::Link;

    struct tSol {
        int altura, diametro;
    };

public:

    bintree_ext() : bintree < T >() {}
    bintree_ext(bintree_ext < T > const& l, T const& e, bintree_ext < T > const& r) : bintree < T >(l, e, r) {}


    int diametro() {

        tSol sol = diametro(this->raiz);
        return sol.diametro;

    }

private :

    int maxDeTres(int n1, int n2, int n3) {
        if (n1 >= n2) return n1 > n3 ? n1 : n3;
        else return n2 > n3 ? n2 : n3; // n2 > n1
    }

    tSol diametro(Link r) {
        if (r == nullptr) return{ 0,0 };
        else {
            tSol izq = diametro(r->left);
            tSol der = diametro(r->right);

            return{ std::max(izq.altura,der.altura) + 1, maxDeTres(izq.diametro,der.diametro,izq.altura + der.altura + 1) };
        }
    }


};

template < typename T >
inline bintree_ext < T > leerArbol_ext(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un arbol vacio
        return {};
    }
    else { // leer recursivamente los hijos
        bintree_ext < T > iz = leerArbol_ext(vacio);
        bintree_ext < T > dr = leerArbol_ext(vacio);
        return { iz, raiz, dr };
    }
}
void resuelveCaso() {

    bintree_ext <char> binaryTree = leerArbol_ext('.');

    std::cout << binaryTree.diametro() << std::endl;

}
int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos .txt
#endif

    int numCasos;
    std::cin >> numCasos;

    for (int i = 0; i < numCasos; i++) resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system(" PAUSE ");
#endif

    return 0;
}
