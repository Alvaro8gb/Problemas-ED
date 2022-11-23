#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Pelicula.h"

bool resuelveCaso() {
	int numPeliculas;

	std::cin >> numPeliculas ;

	if (numPeliculas == 0) return false;

	std::vector <Pelicula> listaPeliculas(numPeliculas);	
		
	try {

		for (Pelicula& p : listaPeliculas) std::cin >> p;

	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}

	std::sort(listaPeliculas.begin(), listaPeliculas.end());

	for (Pelicula& p : listaPeliculas) std::cout << p;
	
	std::cout << "---\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos .txt
#endif
	while (resuelveCaso()) {} // Resolvemos todos los casos


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system(" PAUSE ");
#endif
	return 0;
}