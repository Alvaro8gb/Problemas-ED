// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cctype>


using namespace std;

using tabla = map <string, vector <int> >; // nombre palabra  y numero de apariciones en cada linea i

void tratarFrase(string frase, tabla& mapa ,int size, int numeroLinea) {

    string palabra{};
    for (char c : frase) {


        if (c != ' ') palabra += tolower(c);
        else{


            if (palabra.size() > 2) {

                if (mapa.count(palabra) == 0) {
                    vector <int> v(size);
                    mapa[palabra] = v;

                }
              
                mapa[palabra][numeroLinea] += 1;
               
            }

            palabra = "";
        }
    }

    if (palabra.size() > 2) {

        if (!mapa.count(palabra)) {
            vector <int> v(size);
            mapa[palabra] = v;

        }

        mapa[palabra][numeroLinea] += 1;

    }

}

void mostrarLineasEnLasQueEsta(vector<int> const & lineas) {

    for (int i = 0; i < lineas.size(); i++)  if (lineas[i] != 0) cout << i+1  << " ";

    cout << endl;

}

bool resuelveCaso() {

    int n;
    cin >> n;

    if (n == 0) return false;

    tabla mapa;

    string frase;
    cin.ignore();


    for (int i = 0; i < n; i++) {

        getline(cin, frase);
        tratarFrase(frase,mapa,n,i);

    }

    for (auto it : mapa) {
        cout << it.first << " ";
        mostrarLineasEnLasQueEsta(it.second);
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