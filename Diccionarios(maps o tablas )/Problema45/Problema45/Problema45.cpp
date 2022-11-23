// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>



using namespace std;

class ordDeportes {
public:
    bool operator ()(pair<string ,int>  const& d1, pair<string ,int> const& d2) {
        return (d1.second > d2.second) || d1.second == d2.second && d1.first < d2.first;
    }
};


bool resuelveCaso() {

    string cadena, deporte;
    cin >> cadena;

    if (!cin) return false;

    unordered_map <string, unordered_set<string> > deportes; // clave : nombre deporte  , valor : nombre de estudiantes
    unordered_map <string, string > estudiantes; // clave : nombre estudiante : , valor : primer deporte

    while (cadena != "_FIN_") {
        
        if (cadena[0] >= 'A' && cadena[0] <= 'Z') {
            deporte = cadena;
            deportes[deporte] = {};
        }
        else {
           
            auto it = estudiantes.find(cadena);

            if (it == estudiantes.end()) {// si no esta
                estudiantes.insert({ cadena, deporte}); 
                deportes[deporte].insert(cadena);
            }
            else {

                if (it->second != deporte )  deportes[it->second].erase(cadena);  //y el deporte no es el mismo
            }
           
        }

        cin >> cadena;
    }

    vector <pair<string, int> > sol; 

    for (auto it : deportes)  sol.push_back({ it.first,it.second.size() });
    
    sort(sol.begin(), sol.end(), ordDeportes());

    for (auto it : sol) cout << it.first << " " << it.second << endl;

    cout << "---" << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

 
    while(resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}