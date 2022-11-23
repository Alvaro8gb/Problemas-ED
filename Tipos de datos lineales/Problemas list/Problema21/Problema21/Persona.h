#ifndef PERSONA
#define PERSONA

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>


class Persona {
    std::string nombre;
    int edad;

public:
    Persona() : nombre("sin nombre"),edad(0) {}; //sobrescritura del constructor por defecto

    Persona(std::string nombre,int edad) : nombre(nombre), edad(edad) {
        if (edad < 0) throw std::invalid_argument("Edad no valida");
    };

    Persona& operator = (Persona const& p) { // operador de asignacion
        if (this != &p) { //No sea la misma dirección de memoria
            nombre = p.nombre;
            edad = p.edad;
        }
        return *this;
    }

    int getEdad() const {
        return edad;
    };
    std::string getNombre() const {
        return nombre;
    };
};

inline std::ostream& operator << (std::ostream& out, Persona const& p) {
    out << p.getNombre();
    return out;
}
inline std::istream& operator >> (std::istream& in, Persona& p) {
    std::string nombre;
    int edad;
    char aux;

    in >> edad;

    in.get(aux);

    std::getline(in, nombre);

    p = Persona(nombre, edad);

    return in;
}

#endif