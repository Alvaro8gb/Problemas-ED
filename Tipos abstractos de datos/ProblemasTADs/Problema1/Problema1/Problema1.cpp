#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Hora.h"

bool resuelveCaso(){
	int numTrenes,numHoras;

	std::cin >> numTrenes >> numHoras;

	if (numTrenes == 0) return false;

	std::vector <Hora> proximosTrenes(numTrenes);

	for (Hora& h : proximosTrenes) std::cin >> h;

	Hora horaAConsultar;

	for (int i = 0; i < numHoras; i++) {

		try {

			std::cin >> horaAConsultar;

			auto it = std::lower_bound(proximosTrenes.begin(), proximosTrenes.end(), horaAConsultar); //busqueda binaria

			if (it == proximosTrenes.end()) std::cout << "NO\n";
			else std::cout << *it;

		}
		catch (std::invalid_argument& ia) {
			std::cout << ia.what() << '\n';
		}
	}

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