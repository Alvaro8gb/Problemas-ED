// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include <list>
#include "Persona.h"


class Predicate {
private:
    int edadMin, edadMax;
public:

    Predicate(int edadMin, int edadMax) : edadMin(edadMin), edadMax(edadMax) {};

    bool operator() (Persona p) {
        return edadMin <= p.getEdad() && edadMax >= p.getEdad();
    }
};

template <typename T, typename Predicate>
void remove_if (std::list <T> &lista, Predicate pred) {

    auto it = lista.begin();

    while(it != lista.end()){

        if (!pred(*it)) it = lista.erase(it); // devuelve it++
        else  it++;
        
    }
}
template <typename T>
void mostrarLista(std::list <T>const& lista) {
    for (T elem : lista) std::cout << elem << "\n";
}

bool resuelveCaso() {
    int n, edadMin, edadMax;

    std::cin >> n >> edadMin >> edadMax;

    if (n == 0) return false;

    std::list <Persona> listaPersonas;

    Persona p;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> p;
        listaPersonas.push_back(p);
    }

    Predicate filtro_edad = Predicate(edadMin,edadMax);

    remove_if(listaPersonas,filtro_edad);

    mostrarLista(listaPersonas);

    std::cout << "---\n";

    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()); //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
