// ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>

template <typename T>
struct  tArrayDim {
    int contador;
    T* datos;
};

void erasePos(tArrayDim <int>& a, int pos) {

    for (int i = pos; i < a.contador - 1; i++)  a.datos[i] = a.datos[i + 1];
    
    a.contador--;
}

int resolver(tArrayDim <int>& a, int salto) {

    int i = 0;

    while (a.contador > 1) {
        i = (i + salto) % a.contador;
        erasePos(a, i);
    }

    return a.datos[0];
}
bool resuelveCaso() {
    int numEle,salto;

    std::cin >> numEle >> salto;

    if (numEle == 0) return false;

    tArrayDim <int> arrayDim;

    arrayDim.datos = new int[numEle];
    arrayDim.contador = numEle;

    for (int i = 0; i < numEle; i++) arrayDim.datos[i] = i+1;

    std::cout << resolver(arrayDim, salto)<< "\n";

    delete[] arrayDim.datos;

    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
