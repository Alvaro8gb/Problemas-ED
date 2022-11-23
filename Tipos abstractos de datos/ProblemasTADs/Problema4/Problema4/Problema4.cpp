//A´LVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "Polinomio.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    Polinomio p;
    int numValores;

    std::cin >> p;

    if (!std::cin) return false;

    std::cin >> numValores;

    std::vector <int> valores(numValores);

    for (int& x : valores) {
        std::cin >> x;
        std::cout << p.evaluar(x) << " ";
       
    }


    std::cout <<"\n";
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