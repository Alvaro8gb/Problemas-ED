//ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include "oficinaEmpleo.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    string op;

    cin >> op;
    if (!cin) return false;

    OficinaDeEmpleo ofi;
    string persona,empleo;

    while (op != "FIN") {

        try {
            if (op == "altaOficina") {

                cin >> persona >> empleo;
                ofi.altaOficina(persona, empleo);
            }
            else if (op == "ofertaEmpleo") {
                cin >> empleo;
                persona = ofi.ofertaEmpleo(empleo);
                cout << empleo <<": " << persona << "\n";
            }
            else if (op == "listadoEmpleos") {
                cin >> persona;

                vector<string> empleos = ofi.listadoEmpleos(persona);

                std::cout << persona <<":";

                for (string empleo : empleos) cout << " " << empleo ;

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

    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}