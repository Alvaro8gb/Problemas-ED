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
    
    T min() {
        return min(this->raiz);
    }

private:

    T menorDeTres(T e1, T e2, T e3) {
        if (e1 <= e2) return e1 < e3 ? e1 : e3;
        else return  e2 < e3 ? e2 : e3;
    }

    T min(Link r) {

        if (r == nullptr) throw new std::invalid_argument("Arbol vacio no existe minimo");
        else if (r->left == nullptr && r->right == nullptr) return r->elem;
        else if (r->right != nullptr && r->left == nullptr) {

            T minDer = min(r->right);
            return std::min(r->elem, minDer);

        }
        else if (r->right == nullptr &&  r->left != nullptr) {

            T minIzq = min(r->left);
            return std::min(r->elem, minIzq);
        }
        else {
            T minIzq = min(r->left);
            T minDer = min(r->right);

            return menorDeTres(minIzq, minDer, r->elem);
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
bool resuelveCaso() {

    char type;

    std::cin >> type;

    if (!std::cin)return false;

    if (type == 'N') {
        bintree_ext <int> binariTree = leerArbol_ext(-1);
        std::cout << binariTree.min() << std::endl;
    }
    else if (type == 'P') {
        std::string delimitador(1, '#');
        bintree_ext <std::string> binariTree = leerArbol_ext(delimitador);
        std::cout << binariTree.min() << std::endl;
    }
    else throw new std::invalid_argument("Tipo no detectado validos : N y P");


    return true;

}
int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos .txt
#endif

 while(resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system(" PAUSE ");
#endif

    return 0;
}
