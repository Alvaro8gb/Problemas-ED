#ifndef PELICULA
#define PELICULA

#include <iostream>
#include <stdexcept>
#include <string>
#include "Hora.h"

class Pelicula {
private:
    Hora horaInicio, duracion, horaFin;
    std::string nombre;
public:
    Pelicula() : horaInicio(Hora()), duracion(Hora()), nombre("") {}; //sobrescritura del constructor por defecto

    Pelicula(Hora ini, Hora duracion, std::string name) :  horaInicio(ini),duracion(duracion), horaFin(duracion + ini) ,nombre(name) { };

    Hora getHoraInicio() const{
        return horaInicio;
    }
    Hora getHoraFin() const {
        return horaFin;
    }
    Hora getDuracion() const {
        return duracion;
    }
    std::string getNombre() const {
        return nombre;
    }
    // Operadores de comparacion
    bool operator < (Pelicula const& p) const {
       bool cmp = horaFin < p.getHoraFin();

       if (horaFin == p.getHoraFin()) cmp = nombre < p.getNombre();

       return cmp;
    }
};

inline std::ostream& operator << (std::ostream& out, Pelicula const& p) {
    out << p.getHoraFin() << " " << p.getNombre() << '\n';
    return out;
}
inline std::istream& operator >> (std::istream& in, Pelicula& p) {
    Hora h, d;
    std::string n;
   
    in >> h >> d;
    std::getline(std::cin, n);

    p = Pelicula(h, d, n);

    return in;
}

#endif
