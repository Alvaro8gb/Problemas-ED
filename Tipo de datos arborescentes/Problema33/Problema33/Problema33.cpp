// ALVARO GARCIA BARRAGAN
// A28


#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int mul, altura;

};
bool esPrimo(int const& n) {

    int divisor = 2; 

   
    if (n == 0 || n == 1 || n == 4) return false;

    while (divisor <= n/2) {

        if (n % divisor == 0)return false;
        else divisor++;
    }

    return true;
}
inline std::ostream& operator << (std::ostream& out, tSol const& sol) {
   
    if (sol.mul != -1) out << sol.mul << " " << sol.altura << endl;
    else out << "NO HAY\n";

    return out;
}

class multiploDe7NoPrimos {
public:
    bool operator () (int const& n) {
        return  n!= 7 && n % 7 == 0 ;
    }
};


template <typename T, typename P>
std::pair <bool, std::pair <T, int >> resolver(bintree <T> const& arbol, P propiedad) {

    bool encontrado = false;
    T nodo{};
    int nivel = 0;

    if (arbol.empty()) return { false , {} };
    else if (arbol.left().empty() && arbol.right().empty()) return { propiedad(arbol.root()) ,{ arbol.root() ,1} };

    std::queue <std::pair <int, bintree <T>>> cola;
    cola.push({ 1 , arbol });

    while (!cola.empty() && !encontrado) {
        auto const& par = cola.front();
        auto const& a = par.second;


        if (propiedad(a.root() )) {

            encontrado = true;
            nodo = a.root();
            nivel = par.first;

        }
        else {

            //Podamos ramas con numeros primos
           
            if (!a.left().empty() && !esPrimo(a.root()) )  cola.push({ par.first + 1, a.left() }); 

            if (!a.right().empty() && !esPrimo(a.root()))  cola.push({ par.first + 1, a.right() });
         
        }

        cola.pop();
    }
    return { encontrado ,{ nodo , nivel } };
}
template <class P>
tSol resolverRecursivo(bintree <int> const& binaryTree, P propiedad) {

    if (binaryTree.empty()) return { -1,0 };
    else {

        tSol izq = resolverRecursivo(binaryTree.left(),propiedad);
        tSol der = resolverRecursivo(binaryTree.right(),propiedad);

        if (propiedad(binaryTree.root())) return  { binaryTree.root(),1 };
        else {

            if (esPrimo(binaryTree.root())) return { -1,0 };
            else {

                if (der.mul != -1 && izq.mul != -1) {

                    if (izq.altura <= der.altura) return { izq.mul,izq.altura + 1 };
                    else  return { der.mul,der.altura + 1 };

                }
                else if (der.mul != -1) return{ der.mul,  der.altura + 1 };
                else  return { izq.mul ,izq.altura + 1 };
            }
        }
        
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resuelveCaso() {

    bintree <int> binaryTree = leerArbol(-1);

  
    cout << resolverRecursivo(binaryTree, multiploDe7NoPrimos()) ;

    pair <bool, pair <int, int >>  sol =  resolver(binaryTree, multiploDe7NoPrimos() );

    auto const& par = sol.second;
    
 
    if (sol.first) cout << par.first << " " << par.second << endl;
    else cout << "NO HAY\n";


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

    for (int i = 0; i < numCasos; i++)  resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}