// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include "deque_eda.h"
#include <fstream>


template <class T>
class ListaAmpliada : public deque<T> {
    using Nodo = typename deque<T>::Nodo;
public:

    void mostrarElementos() const {

        Nodo* sig = this->fantasma;

        sig = sig->sig;

        while (sig != this->fantasma) {
            std::cout << sig->elem << " ";
            sig = sig->sig;
        }


        /* Codigo para ver que no se ha roto al doble quue
        *         
        sig = this->fantasma;          
        sig = sig->ant;
        * 
        while (sig != this->fantasma) {
            std::cout << sig->elem << " ";
            sig = sig->ant;
        }
        */
        std::cout << std::endl;

    }
    void invertirNodos() {

        Nodo* sig = this->fantasma;
        Nodo* aux = nullptr;
        Nodo* sigFantasma = sig->sig;

        
        if (this->nelems > 1) {
          
            sig->sig = sig->ant; //que el siguiente del fantasma sea el anterior

            //Pasamos al siguiente
            sig = sig->ant;
           
            while (sig != this->fantasma) { //invertimos del ultimo al primero

                aux = sig->ant; 

                sig->ant = sig->sig;  

                sig->sig = aux;
                
                sig = aux;

            }  

            sig->ant = sigFantasma; // que el anterior del fantasma sea el siguiente

        }
    }
};

bool resuelveCaso() {
    int n;
    ListaAmpliada<int> lista;

    std::cin >> n;
    if (!std::cin) return false;

   while(n !=0) {
        lista.push_back(n);
        std::cin >> n;
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
