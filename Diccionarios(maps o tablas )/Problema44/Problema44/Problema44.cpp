// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>


using namespace std;


void resuelveCaso() {
 
    int n;
    cin >> n;

    unordered_map <int, int> map; // clave : elemento  y valor : pos en el intervalo

    int elem,pos = 0, longMax = 0;

    for (int i = 0; i < n; i++) {

        cin >> elem;

        auto it = map.insert({ elem,i });

        if(!it.second){// si ya estaba

            if (it.first->second >= pos)  pos = it.first->second + 1; // cambiamos la pos del intervalo
            
            it.first->second = i; // reasignamos posicion
        }

        longMax = max(i - pos + 1, longMax);
    }

    cout << longMax << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    int numCasos;
    cin >> numCasos;
    cin.ignore(1);

    for (int i = 0; i < numCasos; i++)resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}