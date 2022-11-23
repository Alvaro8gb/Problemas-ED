#ifndef COMPLEJO
#define COMPLEJO

#include <iostream>
#include <iomanip>
#include <cmath>

template <typename T >
class Complejo {
private:
	T a, b;

public:
	Complejo() :a(0),b(0) { } //constructor sin argumentos
	Complejo(T a,T b): a(a),b(b){} //contructor con argumentos

	T getA() const {return a;}
	T getB()  const {return b;}

	Complejo <T> operator + (Complejo <T> const& c) const {
		return Complejo(a + c.getA(), b + c.getB());
	}
	Complejo <T> operator * (Complejo <T> const& c) const {
		return Complejo(a*c.getA()-b*c.getB(), a*c.getB() + c.getA()*b );
	}
	T mod() const {
		return std::sqrt(a*a + b*b);
	}

};

template <typename T>
inline std::ostream& operator << (std::ostream& out, Complejo<T> const &c) {
	out << std::fixed << std::setprecision(2)  << c.getA() << " " << std::fixed << std::setprecision(2) << c.getB();
	return out;
}
template <typename T>
inline std::istream& operator >> (std::istream& in, Complejo<T> & c) {
	T a, b;

	in >> a >> b;

	c = Complejo <T> (a, b);

	return in;
}

#endif
