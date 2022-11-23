// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

using infoRanking = pair < string, pair <int, int > > ; //nombre equipo y (aciertos,tiempo empleado)

class ordRanking {
public:
    bool operator ()(infoRanking  const& i1, infoRanking const& i2) {
        return  i1.second.first > i2.second.first || //mayor numero de problemas acertados
            i1.second.first == i2.second.first && i1.second.second < i2.second.second || // menor tiempo empleado
            i1.second.first == i2.second.first && i1.second.second == i2.second.second && i1.first < i2.first ; // orden alfabetico creciente
    }
};


void resuelveCaso() {

    string nombreEquipo;

    cin >> nombreEquipo;

    unordered_map <string, pair < pair < int,int> , unordered_map<string,int> >  > equipos; // clave : nombre equipo  &&  valor:  par con un par con tiempo empleado y problemas acertados y un conjunto con los problemas intentados

    //en el mapa anidado  la clave es : nombre del problema intentado y el valor : el tiempo de penalizacion . Si esta a -1 significa q ya lo ha resuelto

    string nombreProblema,resultado;
    int tiempoEnResolverlo;

    while (nombreEquipo != "FIN") {

        cin >> nombreProblema >> tiempoEnResolverlo >> resultado;

        auto & equipo = equipos[nombreEquipo];
        auto& problemasAcertados = equipo.first.first;
        auto& tiempoEmpleado = equipo.first.second;
        auto& tiempoPenalizacion = equipo.second[nombreProblema];

        if (resultado == "AC") {
            
            if (tiempoPenalizacion != -1) {
                tiempoEmpleado += tiempoEnResolverlo + tiempoPenalizacion;
                problemasAcertados++;
                tiempoPenalizacion = -1;
            }
                
        }
        else {// WA, TLE, etc
            if(tiempoPenalizacion != -1) tiempoPenalizacion += 20;
        }
           
        cin >> nombreEquipo;
    }

    vector < infoRanking > sol;

    for (auto const& it : equipos) sol.push_back( { it.first,it.second.first }); // volcamos mapa en vector
    
    sort(sol.begin(), sol.end(), ordRanking());
        
    for (infoRanking info : sol) cout << info.first << " " << info.second.first << " " << info.second.second << endl;

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

    for (int i = 0; i < numCasos; i++) resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}