#ifndef OFICINA_EMPLEO
#define OFICINA_EMPLEO

#include <unordered_map>
#include <set>
#include <stdexcept>
#include <vector>
#include <list>
#include <map>


class OficinaDeEmpleo {
private:

    using Persona = std::string;
    using Empleo = std::string;

    using TablaEmpleados = std::unordered_map <Persona, std::map <Empleo, std::list<Persona>::iterator > >;  // clave :nombre Persona y valor : ( mapa : clave :empleo y valor : iterador)
    using TablaEmpleos = std::unordered_map <Empleo, std::list<Persona>>;

    TablaEmpleados tablaEmpleados;
    TablaEmpleos tablaEmpleos;

    void borrarPersona(Persona p) { // O(n) n numero de empleos de la persona

        for (auto it : tablaEmpleados[p]) {
            auto const& empleo = it.first;

            tablaEmpleos[empleo].erase(it.second);
            if (tablaEmpleos[empleo].empty()) tablaEmpleos.erase(empleo);
        }

        tablaEmpleados.erase(p);
    }


public:
    OficinaDeEmpleo() { };

    void altaOficina(Persona nombre, Empleo empleo) { //O(1)

        if (!tablaEmpleados[nombre].count(empleo)){

            tablaEmpleos[empleo].push_back(nombre);
            auto it = --tablaEmpleos[empleo].end();
            tablaEmpleados[nombre][empleo] = it;
             
        }

    }
    Persona ofertaEmpleo(Empleo empleo) {// O(n) n es el numero de trabajos del empleado

        if (!tablaEmpleos.count(empleo))  throw std::domain_error("No existen personas apuntadas a este empleo");

        Persona nuevoEmpleado = tablaEmpleos[empleo].front();

        borrarPersona(nuevoEmpleado);

        return nuevoEmpleado;
    }
    std::vector <Empleo> listadoEmpleos(Persona persona) { // O(n) n es el numero de trabajos del empleado

        if (!tablaEmpleados.count(persona)) throw std::domain_error("Persona inexistente");

        std::vector <Empleo> empleos(tablaEmpleados[persona].size());

        int i = 0;

        for (auto it : tablaEmpleados[persona] ) empleos[i++] = it.first;
        
        return empleos;
    }

};

#endif



