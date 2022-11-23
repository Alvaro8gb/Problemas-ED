#ifndef POLINOMIO
#define POLINOMIO

#include <iostream>
#include <cmath>
#include <vector>
#include "Monomio.h"


using namespace std;

class Polinomio {
	
private:

	vector<Monomio> polinomio;

	//Coste n , ya que esta practicamente ordenado
	void ordenacionInsercion() {
		Monomio tmp;
		int j;

		for (int i = 1; i < polinomio.size(); i++){
			tmp = polinomio[i];
			j = i - 1;
			while (j >= 0 && polinomio[j] > tmp)
			{
				polinomio[j + 1] = polinomio[j];
				j--;
			}

			polinomio[j + 1] = tmp;
		}
	}
	//coste logn
	int buscar(Monomio x, int ini, int fin) {
		if (ini == fin) return polinomio.size();
		else {
			int m = (ini + fin) / 2;
			if (x < polinomio[m]) return buscar(x, ini, m);
			else if (x > polinomio[m]) return buscar(x, m + 1, fin);
			else return m;
		}

	}

	long long int elevar(long long int base, int expo) const {

		long long int res = 1;

		while (expo > 0) {
			res *= base;
			expo--;
		}
		return res;
	}

public:
	//Objeto funcion
	class comparadorExpo {
	public:
		bool operator ()(Monomio const& m1, Monomio  const& m2) const {
			return m1.getExponente() < m2.getExponente();
		}
	};

	Polinomio() {};
	Polinomio(vector<Monomio> const& polinomio) { this->polinomio = polinomio; };

	int getMonomioExponenete(int mon)const {
		return polinomio[mon].getExponente();
	}

	int getMonomioCoeficiente(int mon) const {
		return polinomio[mon].getCoeficiente();
	}
	int getSize() const {
		return polinomio.size();
	}
	void addMon(int c, int e) {
		
		if (c != 0) {

			Monomio m = Monomio(c, e);
			
			//int pos = buscar(m, 0, polinomio.size());
			auto it = std::lower_bound(polinomio.begin(), polinomio.end(),m, comparadorExpo());
			int pos = it - polinomio.begin();

			if (pos == polinomio.size() || it->getExponente() != m.getExponente()) {
				
				polinomio.push_back(m);
				ordenacionInsercion();
				
			}
			else polinomio[pos].setCoeficente(polinomio[pos].getCoeficiente() + c);
				
		}
	}

	 long long int evaluar(int x) const{

		long long int acumX, res;
		acumX = elevar(x, polinomio[0].getExponente());
		res = acumX * polinomio[0].getCoeficiente();

		for (int i = 1; i < polinomio.size();i++) {
			acumX *= elevar(x, polinomio[i].getExponente() - polinomio[i - 1].getExponente());
			res += acumX * polinomio[i].getCoeficiente();
		}

		return res;
	 }

	string toString() const {
		string p;
		for (int i = 0; i < polinomio.size() - 1; i++)  p += polinomio[i].toString() + " + ";
	
		p += polinomio[polinomio.size() - 1].toString();

		return p;
	}

};

inline std::ostream& operator << (std::ostream& out, Polinomio const& p) {
	
	out << p.toString();

	return out;
}

inline std::istream& operator >> (std::istream& in, Polinomio &p) {
 
	int c, e;
	Polinomio pol = Polinomio();

	in >> c >> e;
	while (!(c == 0 && e == 0) && in) {
		pol.addMon(c,e);
		in >> c >> e;
	};

	p = pol;
	
	return in;
}

#endif

