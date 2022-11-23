#ifndef CARNET_PUNTOS
#define CARNET_PUNTOS

#include <unordered_map>
#include <vector>
#include <stdexcept>

class Carnet_puntos {
private:
    const int MAX_PUNTOS = 15;

    using Dni = std::string;
    using TablaConductores = std::unordered_map <Dni, int>;  // clave : dni && valor: puntos

    TablaConductores tabla;
    std::vector <int> cuantos_conPuntos;

    TablaConductores::iterator findConductor(Dni dni) {

        auto it = tabla.find(dni);

        if (it == tabla.end()) throw std::domain_error("Conductor inexistente");

        return it;
    }

public:

    Carnet_puntos() : cuantos_conPuntos(MAX_PUNTOS + 1, 0) { }//sobrescritura del constructor por defecto

    void nuevo(Dni dni) { // O(1)

        if (tabla.count(dni)) throw std::domain_error("Conductor duplicado");

        tabla.insert({ dni, MAX_PUNTOS });
        cuantos_conPuntos[MAX_PUNTOS]++;

    }

    void quitar(Dni dni, int  puntos) { // O(1)

        auto it = findConductor(dni);

        auto& puntosInfractor = tabla[dni];
        cuantos_conPuntos[puntosInfractor]--;
        puntosInfractor = std::max(0, puntosInfractor - puntos);
        cuantos_conPuntos[puntosInfractor]++;

    }

    int consultar(Dni dni) { //  O(1)
        auto it = findConductor(dni);
        return it->second;
    }

    int cuantos_con_puntos(int puntos) const { // O(1)
        if (puntos < 0 || puntos > MAX_PUNTOS)  throw std::domain_error("Puntos no validos");
        else return cuantos_conPuntos[puntos];
    }

};


#endif

