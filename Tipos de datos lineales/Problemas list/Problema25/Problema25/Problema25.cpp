// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

template < class T >
T Mysearch(T const& ini1, T const& fin1, T const& ini2, T const& fin2) {

    T it = ini1;
    T aux1, aux2;
    bool equal = true;

    while (it != fin1) {

        aux1 = it;
        aux2 = ini2;

        while (equal && aux1 != fin1 && aux2 != fin2) {
            if (*aux1 != *aux2) equal = false;
            else {
                aux1++;
                aux2++;
            }

        }

        if (equal && aux2 == fin2) return it;
        else {
            equal = true;
            it++;
        }

    }

    return fin1;
}

template < class T >
void cargarLista(list <T> &list ,int n) {
    T aux;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        list.push_back(aux);
    }
}

template < class T >
void mostrarLista(list <T> list) {

    for (T elem : list) cout << elem << " ";

    cout << endl;
}

bool resuelveCaso() {
   
    int n1, n2;

    cin >> n1 >> n2;

    if (n1 == 0) return false;

    list <int> lista1;
    list <int> lista2;

    cargarLista(lista1, n1);
    cargarLista(lista2, n2);
   
    auto it = lista1.begin();

    while( it != lista1.end()) {

        it = Mysearch(it, lista1.end(), lista2.begin(), lista2.end());
            
        auto it2 = lista2.begin();

        while (it != lista1.end() && it2 != lista2.end()) {
           
            it = lista1.erase(it); //it++
            it2++;
        }

  
    }
   
    mostrarLista(lista1);

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

