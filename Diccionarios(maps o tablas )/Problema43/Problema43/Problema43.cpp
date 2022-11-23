// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <sstream>


using namespace std;

using diccionario = map <string, int >; // clave : cadena de letras minusculas , valor: numero de apariciones de la palabra

diccionario crearDiccionario(string linea) {
    diccionario dic;
    string palabra;
    int valor;

    stringstream ss(linea) ;

    while (ss >> palabra >> valor) {

        dic[palabra] = valor;
    }

   
    return dic;
}
void mostrarVector(char type,vector <string>const& v) {

    if (!v.empty()) {

        cout << type << " ";
        for (string x : v) cout << x << " ";
        cout << endl;

    }
  
}

void resolver(diccionario const & dic1, diccionario const& dic2) {

    auto it1 = dic1.begin(), it2 = dic2.begin();

    vector <string> nuevo;
    vector <string> borrado;
    vector <string> cambios;

    while (it1 != dic1.end() && it2 != dic2.end()) {

        if (it2->first < it1->first) {
            nuevo.push_back(it2->first);
            it2++;
        }
        else if (it2->first > it1->first) {
            borrado.push_back(it1->first);
            it1++;
        }
        else { //(*it2).first == (*it1).first) 

            if (it2->second != it1->second) cambios.push_back(it2->first);

            it1++;
            it2++;
        }
    }

    while (it1 != dic1.end()) {
        borrado.push_back(it1->first);
        it1++;
    }

    while (it2 != dic2.end()) {
        nuevo.push_back(it2->first);
        it2++;
    }

    if (nuevo.empty() && borrado.empty() && cambios.empty()) cout << "SIN CAMBIOS\n";
    else {
        mostrarVector('+', nuevo);
        mostrarVector('-', borrado);
        mostrarVector('*', cambios);
    }

}

void resuelveCaso() {

    string linea ;

    getline(cin, linea);
    diccionario dic1 = crearDiccionario(linea);

    getline(cin, linea);
    diccionario dic2 = crearDiccionario(linea);

    resolver(dic1, dic2);

    cout << "---\n";

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