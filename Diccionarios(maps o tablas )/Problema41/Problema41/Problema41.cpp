// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include <string>
#include <map>


using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {

    int n;
    cin >> n;

    if (n == 0) return false;

    map <string, int > mapa;

    string nombre,resultado;
    cin.ignore();

    for (int i = 0; i < n; i++) {
    
        getline(cin, nombre);
       
        getline(cin, resultado);

        if (resultado == "CORRECTO" )   mapa[nombre] += 1;
        else if(resultado == "INCORRECTO" ) mapa[nombre] -= 1;

    }

    for (auto it : mapa) if(it.second != 0)  cout << it.first << ", " << it.second << endl;
    

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