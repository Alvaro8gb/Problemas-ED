// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include <list>
#include <stack>

using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    int n;

    cin >> n;

    if (n == 0) return false;

    int num,cont = 1;

    stack <pair <int,int>> pila;

    cin >> num;

    pila.push({ num,0 });

    cout << 0;

    for (int i = 1; i < n; i++) {
        cin >> num;

        while (!pila.empty() && num >= pila.top().first) pila.pop();
        

        if (pila.empty()) cont = i;
        else cont = i - pila.top().second - 1;

        cout << " " << cont;
     
        pila.push({ num,i });
        
    }

    cout << endl;
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