// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include "deque_eda.h"

using namespace std;
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
        
        std::cout << std::endl;
        /* Codigo para ver que no se ha roto al doble quue*/

        sig = this->fantasma;
        sig = sig->ant;

        while (sig != this->fantasma) {
            std::cout << sig->elem << " ";
            sig = sig->ant;
        }

        std::cout << "\n ------" <<std::endl;

    }
    void invertirSegmento(int const& pos, int const& lng) {

        Nodo* sig = this->fantasma;
        int cont = 1;

        sig = sig->sig;
        // Buscamos el nodo  a invertir
        while (cont  != pos) {
            sig = sig->sig;
            cont++;
        }

        if (lng > 1 && sig != nullptr) {

            Nodo* aux = nullptr;
            Nodo* iniSeg = sig->ant;
            Nodo* finSeg = sig;
            
            sig = sig->sig;
            cont = 1;
         
           finSeg->ant = sig;

            while (cont != lng && sig->sig!= this->fantasma) {

                aux = sig->sig;
                sig->sig = sig->ant;
                sig->ant = aux;

                sig = aux;
                cont++;
             
            }

            if (sig!=this->fantasma) {

                iniSeg->sig = sig->ant;
                (sig->ant)->ant = iniSeg;
                sig->ant = finSeg;
               
                finSeg->sig = sig;
                

            }
            else {
                
                finSeg->sig = this->fantasma;

                if (pos == 1) {
                    (this->fantasma)->sig = sig->ant;
                    (this->fantasma)->ant = finSeg;
                }
                else {

                    iniSeg->sig = sig->ant;
                   
                    (sig->ant)->ant = iniSeg;
                  

                }
                
            }
        }
       
    }
};

bool resuelveCaso() {
    int n;
    ListaAmpliada<int> lista;

    std::cin >> n;
    if (!std::cin) return false;
    int pos, lng, num;
    std::cin >> pos >> lng;

    //P + L - 1 <= N

    for (int i = 0; i < n; i++) {
        std::cin >> num;
        lista.push_back(num);
    }


    //No terminado

    lista.invertirSegmento(pos, lng);
    lista.mostrarElementos();

    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());//Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
