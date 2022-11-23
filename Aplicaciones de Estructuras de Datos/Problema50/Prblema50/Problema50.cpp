// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "iPud.h"

using namespace std;

bool resuelveCaso() {

    string operacion;


    cin >> operacion;

    if (!cin)return false;

    IPud iPud;

    string song,artista;
    int duracion;
    int n;

    while (operacion != "FIN") {

        try {

            if (operacion == "addSong") {
                cin >> song >> artista >> duracion;
                iPud.addSong(song, artista, duracion);
            }
            else if (operacion == "addToPlaylist") {
                cin >> song;
                iPud.addToPlaylist(song);
            }
            else if (operacion == "play") {
               song =  iPud.play();
               cout << song << endl;
            }
            else if (operacion == "deleteSong") {
                cin >> song;
                iPud.deleteSong(song);
            }
            else if (operacion == "recent") {
                cin >> n;

                list<string> recentSong = iPud.recent(n);
                if (recentSong.empty()) cout << "No hay canciones recientes" << endl;
                else {
                    cout << "Las " << recentSong.size() << " mas recientes \n";
                    for (auto it : recentSong) cout << "    " << it << endl;
                }
               
            }
            else if (operacion == "current") {
                iPud.current();
            }
            else if (operacion == "totalTime") {
                n = iPud.totalTime();
                cout << "Tiempo total " << n << endl;
            }
    
        }
        catch (exception de) {
            cout << "ERROR " << operacion << endl;
        }
   
        cin >> operacion;
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