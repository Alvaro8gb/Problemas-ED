// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "carnet_puntos.h"

using namespace std;

bool resuelveCaso() {

    string operacion;


    cin >> operacion;

    if (!cin)return false;

    Carnet_puntos conductores;

    string dni;
    int puntos;
    int aux;

    while (operacion != "FIN") {

        try {

            if (operacion == "nuevo") {
                cin >> dni;
                conductores.nuevo(dni);
            }
            else if (operacion == "cuantos_con_puntos") {
                cin >> puntos;
                
                aux = conductores.cuantos_con_puntos(puntos);
                cout << " Con " << puntos << " puntos hay " << aux << endl;
            }
            else if (operacion == "quitar") {
                cin >> dni;
                cin >> puntos;
                conductores.quitar(dni, puntos);
            }
            else if (operacion == "consultar") {
                cin >> dni;
                aux = conductores.consultar(dni);
                cout << " Puntos de " << dni << ": " << aux << endl;
            }

        }
        catch (std::domain_error de) {
            cout << " ERROR: " << de.what() << endl;
        }

        cin >> operacion;
       
    }

    cout << " ---\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

   while(resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}