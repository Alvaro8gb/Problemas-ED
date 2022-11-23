// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

string resolver(string const& cad) {

    list <char> list;

    auto it = list.begin();

    for (char c : cad) {

        switch (c) {
        case '-':
            it = list.begin();
            break;
        case '+':
            it = list.end();
            break;
        case '*':
            if(it != list.end()) it++;
            break;
        case '3':
            if(it != list.end()) it = list.erase(it);
            break;
        default:
            list.insert(it, c);
            break;
        }   
    }

    string msg = "";
    for (char c : list) msg += c;

    return msg;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    string cad;

    getline(cin, cad);

    if (!cin) return false;

    cout << resolver(cad) << endl;
  
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