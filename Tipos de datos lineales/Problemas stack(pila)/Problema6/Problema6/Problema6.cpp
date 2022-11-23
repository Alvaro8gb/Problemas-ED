// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

bool resolver(string const& cad) {

    stack <char> pila;

    for (char c : cad) {
        if (c == '(' ||  c=='[' || c == '{' ) pila.push(c);
        else if (c == ')' || c == ']' || c == '}') {

            if (pila.empty()) return false;
            else {
                if ( !( pila.top() == '(' && c == ')') && !( pila.top() == '[' && c == ']' ) && !(pila.top() =='{' && c == '}')) return false;
                pila.pop();
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

    if (resolver(cad)) cout << "SI\n";
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