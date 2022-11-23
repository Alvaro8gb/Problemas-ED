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
            std::cout << sig->elem << " "; // sig->elem == (* sig).elem 
            sig = sig->sig;
        }

        std::cout << std::endl;

    }
    void invertirNodos() {

        Nodo* sig = this->prim;
        Nodo* aux = nullptr;
        Nodo* ant = nullptr;


        if (!this->empty()) {

            this->ult = sig;

            ant = sig;

            aux = sig->sig;
            sig->sig = nullptr; // el primero pasa a ser el ultim
            sig = aux;

            while (sig != nullptr) {
                
                aux = sig->sig; //guardamos el siguente 

                sig->sig = ant;  //apuntamos al anterior

                //preparamos el siguiente nodo

                ant = sig; 
                sig = aux;
                
            }

            this->prim = ant;
              
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

    lista.invertirNodos();
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
