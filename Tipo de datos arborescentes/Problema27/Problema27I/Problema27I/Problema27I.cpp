//ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

template <class T>
class bintree_ext : public bintree < T > {
    using Link = typename bintree < T > ::Link;
public:

    bintree_ext() : bintree < T >() {}
    bintree_ext(bintree_ext < T > const& l, T const& e, bintree_ext < T > const& r) : bintree < T >(l, e, r) {}

    std::vector <T> hojas() {

        std::vector<T> v;
        
        if (this->raiz != nullptr) calcularHojas(this->raiz,v);

        return v;
    }
    
   

private :

    bool calcularHojas(Link r,std::vector <T>& v) {

        if (r == nullptr) return true;
        else {

            bool izq = calcularHojas(r->left, v);
            bool der = calcularHojas(r->right, v);

            if (izq && der) v.push_back(r->elem);

            return false;

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

    bintree_ext < int > binariTree;

    binariTree = leerArbol_ext(-1);

   std:: vector <int> v = binariTree.hojas();
   
   for (int x : v) std::cout << x << " ";

   std::cout << std::endl;

}
int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos .txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system(" PAUSE ");
#endif

    return 0;
}
