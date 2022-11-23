// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include "queue_eda.h"
#include <fstream>


template <class T>
class ListaAmpliada : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
public:

    void mostrarElementos() const {

        Nodo* sig = this->prim;

        while (sig != nullptr) {
            std::cout << sig->elem << " "; // sig->elem == (* sig).elem 
            sig = sig->sig;
        }

        

        std::cout << std::endl;

    }
    void invertirSegmento(int const& pos, int const& lng) {

        Nodo* sig = this->prim;
        int cont = 1;
        bool salir = false;
        
       // Buscamos el nodo a invertir
        while (sig != nullptr && !salir) {
            if (cont + 1 >= pos) salir = true;
            else {
                sig = sig->sig;
                cont++;
            }
        }

        invertirNodos(sig, pos,lng); // Mandamos el nodo anterior al segmento a invertir y la longitud del segmento
    }
    void invertirNodos(Nodo* first,int const& pos,int const&lng) {

        Nodo* sig = nullptr;
        Nodo* aux = nullptr;
        Nodo* ant = nullptr;
        Nodo* iniSeg = first;
        Nodo* finSeg = nullptr;

        int cont = 0;
        bool salir = false; 

        if (iniSeg != nullptr && lng > 1) {

            if (pos==1) { //invirtiendo desde el primer nodo
                finSeg = iniSeg;
                sig = iniSeg;
            }
            else {
                sig = iniSeg->sig; // Empezamos a invertir desde este nodo
                finSeg = sig; //guardamos el primer nodo a invertir
                ant = iniSeg;
            }
               
            while (sig != nullptr && !salir) {
                
                if (cont == lng) salir = true;
                else {
                    aux = sig->sig; //guardamos el siguente 

                    sig->sig = ant;  //apuntamos al anterior

                    //preparamos el siguiente nodo
                    ant = sig;
                    sig = aux;
                    cont++;
                }
                
            }
            
            
            if (sig == nullptr) {//que se haya recorrido toda la lista
                
                this->ult = finSeg;
                finSeg->sig = nullptr;// que el nuevo final apunte a nulo
               
                if (finSeg != iniSeg) iniSeg->sig = ant;  // que el primero sin invertir apunte al nuevo primero
            }
            else {
                iniSeg->sig = ant; // el inicio enganche al inicio del segInvertido
                finSeg->sig = sig; // renganchando con la parte no invertida
            }
            
            if(pos==1) this->prim = ant; // que prim apunte al nuevo primero
     
        }
    }
};

bool resuelveCaso() {
    int n;
    ListaAmpliada<int> lista;

    std::cin >> n;
    if (!std::cin) return false;
    int pos, lng,num;
    std::cin >> pos >> lng;

    //P + L - 1 <= N

    for (int i = 0; i < n; i++) {
        std::cin >> num;
        lista.push(num);
    }
    
    lista.invertirSegmento(pos, lng);
    lista.mostrarElementos();

    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
