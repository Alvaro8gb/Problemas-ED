// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "autoescuela.h"

using namespace std;

bool resuelveCaso() {

    string operacion;

    cin >> operacion;

    if (!cin) return false;

    Autoescuela autoescuela;

    string alumno,profesor;
    int puntuacion,aux;

    while (operacion != "FIN") {
      
        try {

            if (operacion == "alta") {
                cin >> alumno >> profesor;
                autoescuela.alta(alumno, profesor);
            }
            else if (operacion == "es_alumno") {

                cin >> alumno >> profesor;
                bool esAlumno = autoescuela.esAlumno(alumno, profesor);
                string cad = esAlumno ? "" : " no";

                cout << alumno << cad << " es alumno de " << profesor << endl;
            }
            else if (operacion == "examen") {
                cin >> profesor >> puntuacion;
                std::vector <string>  alumnosAExamen = autoescuela.examen(profesor, puntuacion);

                cout << "Alumnos de " << profesor << " a examen:\n";

                for (auto it : alumnosAExamen) cout << it << endl;
            }
            else if (operacion == "puntuacion") {
                cin >> alumno;
                aux = autoescuela.puntuacion(alumno);
                cout << "Puntuacion de " << alumno << ": " << aux << endl;
            }
            else if (operacion == "actualizar") {
                cin >> alumno >> puntuacion;

                autoescuela.actualizar(alumno, puntuacion);
            }
            else if (operacion == "aprobar") {
                cin >> alumno;
                autoescuela.aprobar(alumno);
            }

        }
        catch (std::domain_error de) {
            cout << "ERROR"  << endl;
        }

        cin >> operacion;
   
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