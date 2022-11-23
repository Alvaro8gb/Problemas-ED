#ifndef MONOMIO
#define MONOMIO
#include <string>

class Monomio {

private:
	 int coeficiente, exponente;
public:
	Monomio() :coeficiente(0), exponente(0) {}

	Monomio(int c, int e) : coeficiente(c), exponente(e) {}

	int getCoeficiente()const { return coeficiente; }
	int getExponente() const { return exponente; }

	void setCoeficente(int c) {
		coeficiente = c;
	}
	bool operator < (Monomio const& m) const {
		return exponente < m.getExponente();
	}
	bool operator > (Monomio const& m) const {
		return exponente > m.getExponente();
	}
	bool operator == (Monomio const& m) const {
		return coeficiente == m.getCoeficiente() && exponente == m.getExponente();
	}
	std::string toString() const {
		return std::to_string(coeficiente) + "x^" + std::to_string(exponente);
	}
};

#endif