// ALVARO GARCIA BARRAGAN
// A28

#include <iostream>
#include <fstream>
#include "academia_chino.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    string operacion;
    cin >> operacion;

    if (!cin) return false;

    AcademiaChino academia = AcademiaChino();
    string dni;
    int grupo;
   

    while (operacion != "FIN") {

        try {

            if (operacion == "nuevo_estudiante") {
                std::cin >> dni >> grupo;
                academia.nuevo_estudiante(dni, grupo);
            }
            else if (operacion == "promocionar") {
                
                std::cin >> dni;
                academia.promocionar(dni);
      
            }
            else if (operacion == "grupo_estudiante") {

                std::cin >> dni;
                grupo = academia.grupo_estudiante(dni);
                std::cout << dni << " esta en el grupo " << grupo << "\n";
            }
            else if (operacion == "graduados") {
               
                vector<string> lista = academia.graduados();
                std::cout << "Lista de graduados: ";
                for (std::string s : lista) std::cout << s << " ";
                std::cout << "\n";
            }
            else if (operacion == "novato") {
                
                cin >> grupo;
                dni = academia.novato(grupo);
                cout << "Novato de " << grupo << ": " << dni << "\n";

            }

        }catch (std::domain_error& e) {
            std::cout << "ERROR: " << e.what() << "\n";
        }

        std::cin >> operacion;
    }
    std::cout << "---\n";
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