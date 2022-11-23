#ifndef HORA
#define HORA

#include <iostream>
#include <iomanip>
#include <stdexcept>

class Hora {
public:
    Hora() : horas(0), minutos(0), segundos(0) {}; //sobrescritura del constructor por defecto

    Hora(int h, int m, int s) : horas(h), minutos(m), segundos(s) {
        if(h >=MAX_HORAS || s >= MAX_MINUTOS_SEGUNDOS || m >= MAX_MINUTOS_SEGUNDOS) throw std::invalid_argument("ERROR");     
    };

    Hora& operator = (Hora const& h) { // operador de asignacion
        if (this != &h) { //No sea la misma dirección de memoria
            horas = h.horas;
            minutos = h.minutos;
            segundos = h.segundos;
        }
        return *this;
    }

    int get_horas() const {
        return horas;
    };
    int get_minutos() const {
        return minutos;
    };
    int get_segundos() const {
        return segundos;
    }
 
    // Operadores de comparacion
    bool operator < (Hora const& h) const {
        if (horas < h.horas) return true;
        else if (horas > h.horas) return false;
        else if (minutos < h.minutos) return true;
        else if (minutos > h.minutos) return false;
        else if (segundos < h.segundos) return true;
        else return false;
    }
    bool operator == (Hora const& h) const {
        return horas == h.horas && minutos == h.minutos && segundos == h.segundos;
    }
    bool operator <= (Hora const& h) const {
        return *this < h || *this == h;
    }
    bool operator > (Hora const& h) const {
        return !(*this <= h);
    }
    bool operator >= (Hora const& h) const {
        return !(*this < h);
    }

private:

    int horas, minutos, segundos;
    const int MAX_HORAS = 24;
    const int MAX_MINUTOS_SEGUNDOS = 60;
};

inline std::ostream& operator << (std::ostream& out, Hora const& h) {
    out << std::setfill('0') << std::setw(2) <<  h.get_horas() << ':' << std::setfill('0') << std::setw(2) << h.get_minutos() << ':' << std::setfill('0') << std::setw(2) << h.get_segundos() << '\n';
    return out;
}
inline std::istream& operator >> (std::istream& in, Hora& hora) {
    int h, m, s; 
    char aux;

    in >> h >> aux >> m >> aux >> s ;

    hora = Hora(h, m, s);
    return in;
}

#endif