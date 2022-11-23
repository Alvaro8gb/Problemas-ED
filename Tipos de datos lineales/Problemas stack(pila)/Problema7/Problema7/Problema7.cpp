// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <stack>
#include <fstream>

using namespace std;
struct tFecha {
    string f;
    int numMuertos;
};

inline ostream& operator << (std::ostream& out, tFecha const& f) {
    out << f.f ;
    return out;
}
inline istream& operator >> (std::istream& in, tFecha & f) {
   
    in >> f.f >> f.numMuertos;
    return in;
}

// función que resuelve el problema
void resolver(int const& n) {

    stack <tFecha> pila;
    tFecha f;

    cin >> f; 

    cout << "NO HAY\n";
    pila.push(f);

    for (int i = 1; i < n; i++) {
       
        cin >> f;

       if (pila.top().numMuertos <= f.numMuertos){
            
            pila.pop();
            while (!pila.empty() && pila.top().numMuertos <= f.numMuertos) pila.pop();
            
            if(!pila.empty() && pila.top().numMuertos > f.numMuertos) cout << pila.top() << endl;
            else cout << "NO HAY\n";

       }
       else cout << pila.top() << endl;
        
       pila.push(f);
    }
}

bool resuelveCaso() {
    int n;
    cin >> n;

    if (!cin) return false;
    resolver(n);

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
        while(resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}