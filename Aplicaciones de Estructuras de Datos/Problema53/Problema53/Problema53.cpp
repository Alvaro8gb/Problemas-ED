//ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include "urgencias.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    string op;

    cin >> op;
    if (!cin)return false;

    Urgencias salaDeEspera;
    string dni;
    int gravedad;

    while( op != "FIN") {
        
        try {
            if (op == "nuevo_paciente") {
  
                cin >> dni >> gravedad;
                salaDeEspera.nuevo_paciente(dni, gravedad);
            }
            else if (op == "gravedad_actual") {
                cin >> dni;
                gravedad = salaDeEspera.gravedad_actual(dni);
                cout << "La gravedad de " << dni << " es " << gravedad << "\n";
            }
            else if (op == "siguiente") {
                std::string x = salaDeEspera.siguiente();
                std::cout << "Siguiente paciente: " << x << "\n";
            }
            else if (op == "mejora") {
                cin >> dni;
                salaDeEspera.mejora(dni);
            }
            else if (op == "recuperados") {
                vector<string> recuperados = salaDeEspera.recuperados();
                cout << "Lista de recuperados: ";
                for (string recuperado : recuperados) {
                    cout << recuperado << " ";
                }
                cout << endl;
            }

        }
        catch (domain_error e) {
            cout << "ERROR: " << e.what() << "\n";
        }

        cin >> op;
    }
    std::cout << "---" << std::endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso()) ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}