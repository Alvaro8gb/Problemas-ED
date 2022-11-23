// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include <string>
#include "gestor_libros.h"

using namespace std;


bool resuelveCaso() {

    int numOp;
    cin >> numOp;

    if (!cin)return false;

    Gestor_Libros gestor_libros;

    string operacion,libro;
    int numEjemplares;

    for(int i = 0; i < numOp; i++ ){
        cin >> operacion;
      
        try {

            if (operacion == "estaLibro") {
                cin.ignore(1);
                getline(cin, libro);

                bool esta = gestor_libros.estaLibro(libro);
                if (esta) cout << "El libro " << libro << " esta en el sistema\n";
                else cout << "No existe el libro " << libro << " en el sistema\n";
            }
            else if (operacion == "numEjemplares") {
                cin.ignore(1);
                getline(cin, libro);

                try {
                    numEjemplares = gestor_libros.numEjemplares(libro);
                    cout << "Existen " << numEjemplares << " ejemplares del libro " << libro << endl;
                }
                catch (invalid_argument e) {
                    cout << "No existe el libro " << libro << " en el sistema" << endl;
                }

            }
            else if (operacion == "top10") {
                cout << "TOP10" << endl;
                vector<string> top10 = gestor_libros.top10();

                for (auto it : top10) cout << "    " << it << endl;

            }
            else if (operacion == "comprar") {
                cin.ignore(1);
                getline(cin, libro);
                gestor_libros.comprar(libro);
            }
            else if (operacion == "nuevoLibro") {
                cin >> numEjemplares;
                cin.ignore(1);
                getline(cin, libro);

                gestor_libros.nuevoLibro(numEjemplares, libro);
            }
            else if (operacion == "elimLibro") {
                cin.ignore(1);
                getline(cin, libro);
                gestor_libros.elimLibro(libro);

            }
        }
        catch (invalid_argument ia ) {
            cout << ia.what() << endl;
        }
        catch (out_of_range o ) {
            cout << o.what() << endl;
        }
    
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