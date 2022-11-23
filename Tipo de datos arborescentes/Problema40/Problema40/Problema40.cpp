// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "set.h"


using namespace std;

/* 

Arbol binario de busqueda :
el elemento en cada nodo es mayor que todos sus descendientes izquierdos
y menor que todos sus descendientes derechos


*/


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {

    int n;
    cin >> n;

    if (n == 0) return false;

    set <int> conjuntoOrdenado;

    int elem;

    for (int i = 0; i < n; i++) {
        cin >> elem;
        conjuntoOrdenado.insert(elem);
    }
  
    //for (auto it = conjuntoOrdenado.begin(); it != conjuntoOrdenado.end(); ++it) cout << *it <<" -" << std::endl;
    int casos;
    cin >> casos;

    for (int i = 0; i < casos; i++) {
        cin >> elem;
        pair < bool, int > sol = conjuntoOrdenado.lower_bound(elem);

        if (sol.first) cout << sol.second << std::endl;
        else cout << "NO HAY\n";

    }

   
    cout << "---\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}