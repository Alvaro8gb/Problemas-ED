// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include "deque_eda.h"

template <class T>
class ListaAmpliada : public deque<T> {
    using Nodo = typename deque<T>::Nodo;
public:

    void mostrarElementos() const {

        Nodo* sig = this->fantasma;

        sig = sig->sig;

        while (sig != this->fantasma) {
            std::cout << sig->elem << " "; // sig->elem == (* sig).elem 
            sig = sig->sig;
        }

        std::cout << std::endl;

        /*
        sig = this->fantasma;
        sig = sig->ant;
        
        while (sig != this->fantasma) {
            std::cout << sig->elem << " ";
            sig = sig->ant;
        }

        std::cout << std::endl;
        */
    }
    void inplaceMerge_linkedList(ListaAmpliada <T>& listB) {

        Nodo* sigA = this->fantasma;
        Nodo* sigB = listB.fantasma;
        Nodo* aux = nullptr;

        if (!listB.empty() && !this->empty()) {

            sigA = sigA->sig;
            sigB = sigB->sig;

            if (sigB->elem <= sigA->elem) {

                aux = sigB->sig;
                (this->fantasma)->sig = sigB;
                sigB->ant = this->fantasma;

                sigB->sig = sigA;
                sigA->ant = sigB;

                sigB = aux;
            }
            else {
                sigA = sigA->sig;
            }

            while (sigB != listB.fantasma && sigA != this->fantasma) {
                if (sigB->elem <= sigA->elem) {
                   
                    aux = sigB->sig;
                    (sigA->ant)->sig = sigB;
                    sigB->ant = sigA->ant;
                    sigB->sig = sigA;
                    sigA->ant = sigB;

                    sigB = aux;

                }
                else {
                    sigA = sigA->sig;
                }

            }
           
            if (sigB != listB.fantasma) {
                (sigA->ant)->sig = sigB;
                sigB->ant = sigA->ant;
               (this->fantasma)->ant = (listB.fantasma)->ant;
               (listB.fantasma->ant)->sig = this->fantasma;
            }

        }
        else if (!listB.empty()) { // listA.empty()
            aux = this->fantasma;
            this->fantasma = listB.fantasma;
            listB.fantasma = aux;
        }

        this->nelems += listB.nelems;

        (listB.fantasma)->sig = (listB.fantasma)->ant = listB.fantasma;
        listB.nelems = 0;

    }
};



void resuelveCaso() {

    ListaAmpliada<int> listaA;
    ListaAmpliada<int> listaB;

    int num;

    std::cin >> num;
    while (num != 0) {
        listaA.push_back(num);
        std::cin >> num;
    }
    std::cin >> num;
    while (num != 0) {
        listaB.push_back(num);
        std::cin >> num;
    }

    //No terminado faltan arreglar punteros ant

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
