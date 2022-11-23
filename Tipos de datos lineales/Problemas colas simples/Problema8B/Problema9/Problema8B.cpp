// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include "Hora.h"
#include "queue_eda.h"

class propHoraMayor12 {
public:
    const Hora doce = Hora(12, 0, 0);
    bool operator() (Hora h) {
        return h > doce;
    }
};

template <class T>
class ListaAmpliada : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
public:
    template <class comp>
    int contarElementos(comp propiedad) const {

        int cont = 0;
        Nodo* sig = this->prim;

        while (sig != nullptr) {
            if (propiedad(sig->elem)) cont++;
            sig = sig->sig;
        }

        return cont;
    }
};



bool resuelveCaso() {
    int numElem;
    std::cin >> numElem;
    if (numElem == 0) return false;

    ListaAmpliada<Hora> lista;
    for (size_t i = 0; i < numElem; ++i) {
        Hora h;
        std::cin >> h;
        lista.push(h);
    }
    int cont = lista.contarElementos(propHoraMayor12());

    std::cout << cont << '\n';

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
