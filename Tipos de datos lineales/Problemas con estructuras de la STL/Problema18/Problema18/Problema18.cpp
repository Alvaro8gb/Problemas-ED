// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include <queue>
#include <deque>
#include <stack>
#include <string>

bool serVocal(char const& c) {

    if (c == 'A' || c == 'a') return true;
    if (c == 'E' || c == 'e') return true;
    if (c == 'I' || c == 'i') return true;
    if (c == 'O' || c == 'o') return true;
    if (c == 'U' || c == 'u') return true;

    return false;
}
std::string resolver(std::string const& msgCifrado) {

    std::stack <char> pila;
    std::queue <char> cola;

    /* X" -> X' */
    int i = 0;
    for (int i = 0; i < msgCifrado.length();i++) {
        if (i %2 == 0) cola.push(msgCifrado[i]);
        else pila.push(msgCifrado[i]);
    }

    while (!pila.empty()) {
        cola.push(pila.top());
        pila.pop();
    }
    
    /* X' -> X */

    std::queue <char> cola2;
    
    while (!cola.empty()) {
        if (serVocal(cola.front())) {
            while(!pila.empty()) {
                cola2.push(pila.top());
                pila.pop();
            }
            cola2.push(cola.front());
        }
        else pila.push(cola.front());

        cola.pop();    
    }

    while (!pila.empty()) {
        cola2.push(pila.top());
        pila.pop();
    }

    std::string msg = "";

    while (!cola2.empty()) {
        msg += cola2.front();
        cola2.pop();
    }

    return msg;
}
bool resuelveCaso() {

    std::string msgCifrado;
    std::getline(std::cin, msgCifrado);

    if (!std::cin) return false;

    std::cout << resolver(msgCifrado) << std::endl;

    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
