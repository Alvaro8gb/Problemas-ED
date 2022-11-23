//A´LVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "set.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
template <typename T>
void resolverGenerico(T fin,size_t k) {

    set <T> conjuntoOrdenado = set <T>();
    T elemt;

    std::cin >> elemt;
    while (elemt != fin && std::cin) {
        try {
            if (conjuntoOrdenado.size() < k) {
                conjuntoOrdenado.insert(elemt);
            }
            else {

                if (elemt > conjuntoOrdenado.min() ){
                    conjuntoOrdenado.insert(elemt);
                    conjuntoOrdenado.erase_min();
                }

            }
        }
        catch (std::domain_error& de) {
            std::cout << de.what(); << std::endl;
        }
        std::cin >> elemt;
    }
    conjuntoOrdenado.print();
   
}
bool resuelveCaso() {
    // leer los datos de la entrada

     char tipo;
     size_t k;

     std::cin >> tipo >> k;
     if (!std::cin) return false;
    
     if (tipo == 'N') resolverGenerico((long long int) (- 1), k);
     else if (tipo == 'P') resolverGenerico((std::string)("FIN"), k);

    std::cout << "\n";

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
