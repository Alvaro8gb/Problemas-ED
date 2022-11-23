// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

bool esEtiquetaAbierta(string e) {
    if (e == "<p>") return true; 
    else if (e == "<i>") return true;
    else if (e == "<q>") return true;
    else if (e == "<b>") return true;

    return false;
}
bool esEtiquetaCerrada(string e) {
    if (e == "</p>") return true;
    else if (e == "</i>") return true;
    else if (e == "</q>") return true;
    else if (e == "</b>") return true;

    return false;
}

 int convertToIndex(char c) {

     if (c == 'p') return 0;
     if (c == 'b') return 1;
     if (c == 'i') return 2;
     if (c == 'q') return 3;

     return -1;
}
bool resolver(string const& cad, vector <int> &contadores) {

    stack <char> pila;

    for (int i = 0; i < cad.length();i++) {
       
        if (cad[i] == '<') {

            if (esEtiquetaAbierta(cad.substr(i, 3))) {
                pila.push(cad[i + 1]);
                i = i + 2;
            }
            else {

                if (pila.empty()) {
                    if (esEtiquetaCerrada(cad.substr(i, 4))) return false;
                }
                else {

                    if (esEtiquetaCerrada(cad.substr(i, 4))) {
                        if (cad[i + 2] == pila.top()) {
                            contadores[convertToIndex(pila.top())]++;
                            pila.pop();
                        }
                        else return false;

                        i = i + 3;
                    }
                }
            }
        }


    }

    if (!pila.empty()) return false;


    return true;

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    string cad;

    getline(cin, cad);

    if (!cin) return false;

    vector <int> contadores(4);

    for (int i = 0; i < contadores.size(); i++)  contadores[i] = 0;

    if (resolver(cad.substr(6, cad.length()), contadores)) {
        cout << "SI";
        for (int i = 0; i < contadores.size(); i++) cout << " " << contadores[i];
        cout << endl;
    }
    else cout << "NO\n";

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