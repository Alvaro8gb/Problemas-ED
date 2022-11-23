#ifndef CARNET_PUNTOS
#define CARNET_PUNTOS

#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <list>

class Carnet_puntos {
private:
    const int MAX_PUNTOS = 15;

    using Dni = std::string;
    using TablaConductores = std::unordered_map <Dni, std::pair<int, std:: list<Dni> ::iterator >>;  // clave : dni && valor: puntos
    using TablaPuntos = std::unordered_map <int, std::list<Dni>>;


    TablaConductores tablaConductores;
    std::vector<std::list<Dni>> conductoresConPuntos;

    TablaConductores::iterator findConductor(Dni dni) { // O(1)

        auto it = tablaConductores.find(dni);

        if (it == tablaConductores.end()) throw std::domain_error("Conductor inexistente");

        return it;
    }
    void comprobarPuntos(int puntos) const{ // O(1)
        if (puntos < 0 || puntos > MAX_PUNTOS)  throw std::domain_error("Puntos no validos");
    }
    void cambiarPuntosConductor(bool sancionado,int puntos, Dni dni) { // O(1)

        auto it = findConductor(dni);

        auto& puntosInfractor = it->second.first;
        auto& iteradorLista = it->second.second;
        int puntoAntiguos = puntosInfractor;

        if(!sancionado)  puntosInfractor = std::min(MAX_PUNTOS, puntosInfractor + puntos);
        else puntosInfractor = std::max(0, puntosInfractor - puntos);

        if (puntoAntiguos != puntosInfractor) { //Solo me mueve si ha cambiado el numero de puntos

            conductoresConPuntos[puntoAntiguos].erase(iteradorLista); // O(1)

            conductoresConPuntos[puntosInfractor].push_back(dni);// O(1)

            auto itLista = --conductoresConPuntos[puntosInfractor].end();

            iteradorLista = itLista;
        }
    }

public:

    Carnet_puntos() : conductoresConPuntos(MAX_PUNTOS + 1) { } //sobrescritura del constructor por defecto

    void nuevo(Dni dni) { // O(1)

        if (tablaConductores.count(dni)) throw std::domain_error("Conductor duplicado");

        conductoresConPuntos[MAX_PUNTOS].push_back(dni);

        auto it = --conductoresConPuntos[MAX_PUNTOS].end();

        tablaConductores.insert({ dni, {MAX_PUNTOS, it } });

    }
    void recuperar(Dni dni, int  puntos) {// O(1)
       cambiarPuntosConductor(false, puntos, dni);
    }

    void quitar(Dni dni, int  puntos) { // O(1)
        cambiarPuntosConductor(true, puntos, dni);
    }

    int consultar(Dni dni) { //  O(1)
        auto it = findConductor(dni);
        return it->second.first;
    }

    int cuantos_con_puntos(int puntos) const { // O( 1 )
       
        comprobarPuntos(puntos);
        return conductoresConPuntos[puntos].size();
    }

    std::list <Dni> lista_por_puntos(int puntos) { // 0(n) n es el numero de conductores con esos puntos
        comprobarPuntos(puntos);
        return conductoresConPuntos[puntos];
    }
 
};


#endif

