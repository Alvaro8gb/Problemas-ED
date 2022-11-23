//ALVARO GARCIA BARRAGAN
//A28

#include <iostream>
#include <fstream>
#include "Complejo.h"

bool resolver(Complejo <float> const& c,int n,Complejo <float> zn) {
	if (n == 0)return true;
	else {

		if (zn.mod() > 2) return false;
		else return resolver(c, n - 1, zn * zn + c);
	
	}
}
bool resuelveCaso() {
	
	int numIteraciones;
    Complejo <float> c;

	std::cin >> c >> numIteraciones;

	if(resolver(c, numIteraciones, Complejo <float>())) std::cout << "SI\n";
	else std::cout << "NO\n";

	return false;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos .txt
#endif
	int numCasos;

	std::cin >> numCasos;

	for (int i = 0; i < numCasos; i++)resuelveCaso();


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
#endif
	return 0;
}