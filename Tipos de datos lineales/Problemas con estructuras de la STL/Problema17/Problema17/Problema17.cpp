// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

bool resuelveCaso() {
    int numEle;

    std::cin >> numEle ;

    if (numEle == 0) return false;

    std::queue <int> cola;
    std::stack <int> pila;

    int num;

    for (int i = 0; i < numEle; i++) {
        std::cin >> num;

        if (num >= 0) cola.push(num);
        else pila.push(num); 
    }

    if (!pila.empty()) {

        do {
            cola.push(pila.top());
            pila.pop();
        } while (!pila.empty());

        while (cola.front() >= 0) {
            cola.push(cola.front());
            cola.pop();
        }
    }

    for (int i = 0; i < numEle; i++) {
        std::cout << cola.front() << " ";
        cola.pop();
    }
    std::cout << std::endl;

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
