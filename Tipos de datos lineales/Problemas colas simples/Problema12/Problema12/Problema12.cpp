// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include "queue_eda.h"

template <class T>
class ListaAmpliada : public  queue<T> {
    using Nodo = class queue<T>::Nodo;
public:

    void mostrarElementos() const {

        Nodo* sig = this->prim;

        while (sig != nullptr) {
            std::cout << sig->elem << " "; // sig->elem == (* sig).elem 
            sig = sig->sig;
        }

        std::cout << std::endl;

    }
    void inplaceMerge_linkedList(ListaAmpliada <T> &listB) {

        Nodo* sigA = this->prim;
        Nodo* sigB = listB.prim;
        Nodo* ant = nullptr;
        Nodo* aux = nullptr;

        if (!listB.empty() && !this->empty()) {

            if (sigB->elem <= sigA->elem) {
                
                this->prim = sigB;

                aux = sigB->sig;
                sigB->sig = sigA;

                ant = sigB;
                sigB = aux; 
            }
            else {
                ant = sigA;
                sigA = sigA->sig;
               
            }

            while (sigB != nullptr && sigA != nullptr) {
                if (sigB->elem <= sigA->elem) {

                    aux = sigB->sig;
                    ant->sig = sigB;
                    sigB->sig = sigA;

                    ant = sigB;
                    sigB = aux;
                    
                }
                else {
                    ant = sigA;
                    sigA = sigA->sig;
                }
            }

            if (sigB != nullptr) {
                ant->sig = sigB;
                this->ult = listB.ult;
            }
            else this->ult = ant;
              
        }
        else if (!listB.empty()) {
            this->prim = listB.prim;
            this->ult = listB.ult;
        }

        this->nelems += listB.nelems;
        listB.prim = listB.ult = nullptr;
        listB.nelems = 0;
        
    }      
};

void resuelveCaso() {

    ListaAmpliada<int> listaA;
    ListaAmpliada<int> listaB;

    int num;

    std::cin >> num;
    while (num != 0) {
        listaA.push(num);
        std::cin >> num;
    }
    std::cin >> num;
    while (num != 0) {
        listaB.push(num);
        std::cin >> num;
    }

    listaA.inplaceMerge_linkedList(listaB);
    listaA.mostrarElementos();
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    int numCasos;
    std::cin >> numCasos;
   
    for (int i = 0; i < numCasos; i++) resuelveCaso();//Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
