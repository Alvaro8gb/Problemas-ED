// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include <list>


void mostrarLista(std::list <int> const & lista) {

    if (!lista.empty()) {// de atras hacia delante

        for (auto it = --lista.cend(); it != lista.cbegin(); it--)  std::cout << *it << " ";

        std::cout << *lista.begin();
    }

    std::cout << "\n";

    // mostrar de delante hacia detras

    //for (auto it = lista.cbegin(); it != lista.cend(); it++) std::cout << *it << " ";

    //for (int x :lista) std::cout << x << " ";

}
void duplicarNodosLista(std::list <int>& lista) {

    auto it = lista.begin();

    for (auto it = lista.cbegin(); it != lista.cend(); it++) lista.insert(it, *it);
}

bool resuelveCaso() {


    int elem;
    std::cin >> elem;
    
    if (!std::cin) return false;

    std::list <int> lista;

    while (elem != 0){  
        lista.push_front(elem);
        std::cin >> elem;
    }

    duplicarNodosLista(lista);
    mostrarLista(lista);

    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
