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

      int sumaNodos() {
          return sumaNodos(this->raiz);
      }
      int numNodos() {
          return numNodos(this->raiz);
      }
      int altura() {
          return altura(this->raiz);
      }
      int numHojas() {
          return numHojas(this->raiz);
      }

private:
    
    int sumaNodos(Link r) {

        if (r == nullptr) return 0;
        else {
            int Izda = sumaNodos(r->left);
            int Drch = sumaNodos(r->right);

            return  Izda + Drch + r->elem;
        }
    }

    int numNodos(Link r) {
        if (r == nullptr) return 0;
        else {

            int numNodosLeft = numNodos(r->left);
            int numNodosRight = numNodos(r->right);

            return numNodosLeft + numNodosRight + 1;
        }
    }

    int altura(Link r) {
        if (r == nullptr) return 0;
        else {

            int alturaLeft = altura(r->left);
            int alturaRight = altura(r->right);

            return max(alturaLeft, alturaRight) + 1;;
        }
    }

    int numHojas(Link r) {
        if (r == nullptr) return 0;
        else {

            int numHojasLeft = numHojas(r->left);
            int numHojasRight = numHojas(r->right);

            int numHojas = numHojasLeft + numHojasRight;

            if (numHojasLeft == 0 && numHojasRight == 0) numHojas++;

            return numHojas;
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
        return { iz, raiz, dr};
    }
}
void resuelveCaso() {

    bintree_ext < char > binariTree;

    binariTree = leerArbol_ext('.');

    std::cout << binariTree.numNodos() << " " << binariTree.numHojas() << " " << binariTree.altura() <<"\n";

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
