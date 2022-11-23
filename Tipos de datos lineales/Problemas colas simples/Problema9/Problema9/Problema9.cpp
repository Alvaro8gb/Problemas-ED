// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include "queue_eda.h"
#include <fstream>


template <class T>
class ListaAmpliada : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
public:

    void mostrarElementos() const {

        Nodo* sig = this->prim;

        while (sig != nullptr) {
            std::cout << sig->elem  <<" "; // sig->elem == (* sig).elem 
            sig = sig->sig;
        }

        std::cout << std::endl;

    }
    void duplicarNodos() {

        Nodo* sig ;
        Nodo* act = this->prim;

        while (act != nullptr) {
            
            sig = new Nodo(act->elem, act->sig); //creamos nuevo nodo 
            act->sig = sig; // hacemos que el actual apunte al nuevo
            act = sig->sig; 
            
        }
    }
};



bool resuelveCaso() {
    int num;
    ListaAmpliada<int> lista;

    std::cin >> num;
    if (!std::cin) return false;

    while (num != 0) {
        lista.push(num);
        std::cin >> num;
    }
     
    lista.duplicarNodos();
    lista.mostrarElementos();

    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
