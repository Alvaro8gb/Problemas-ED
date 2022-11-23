#ifndef ACADEMIA_CHINO
#define ACADEMIA_CHINO

#include <unordered_map>
#include <set>
#include <stdexcept>
#include <vector>
#include <list>


class Urgencias {
private:
    const int _GRAVEDAD_MAX = 3, _GRAVEDAD_MIN = 1;
    using Paciente = std::string;

    using TablaPacientes = std::unordered_map <Paciente,std::pair <int, std::list <Paciente> ::iterator >> ;  // clave :nombre Paciente y valor : gravedad e iterador a la lista

    TablaPacientes tablaPacientes;
    std::set <Paciente> pacientesRecuperados;
    std::vector<std::list<Paciente>> pacientesEsperando;

    void validarGravedad(int gravedad) const { // O(1)
        if (gravedad < _GRAVEDAD_MIN || gravedad > _GRAVEDAD_MAX) throw std::domain_error("Gravedad incorrecta");
    }

    TablaPacientes::iterator findPaciente(Paciente p) {// O(1)

        auto it = tablaPacientes.find(p);

        if (it == tablaPacientes.end()) throw std::domain_error("Paciente inexistente");

        return it;

    }

public:
    Urgencias() : pacientesEsperando(_GRAVEDAD_MAX) { };

    void nuevo_paciente(Paciente p, int gravedad) { // O(1)

        if (tablaPacientes.count(p)) throw std::domain_error("Paciente repetido");

        validarGravedad(gravedad); // O(1)

        int gravedadVector = gravedad - 1;

        pacientesEsperando[gravedadVector].push_back(p); // O(1)
        auto it = --pacientesEsperando[gravedadVector].end();

        tablaPacientes[p] = { gravedad, it }; // O(1)

    }

    int gravedad_actual(Paciente p) {// O(1)

        auto it = findPaciente(p);// O(1)
        return it->second.first;
    }

    Paciente siguiente() {

        auto it = pacientesEsperando.end();
   
        while(it != pacientesEsperando.begin() ) {
            it--;
            if (!it->empty()) {
    
                Paciente p = it->front();
                it->pop_front();
                tablaPacientes.erase(p);
                return p;
            }
        }

         throw std::domain_error("No hay pacientes");
    }
    void mejora(Paciente p) {

        auto it = findPaciente(p);
        auto& gravedadActual = it->second.first;
        int gravedadVector = gravedadActual - 1;

        pacientesEsperando[gravedadVector].erase(it->second.second);


        if (gravedadActual == _GRAVEDAD_MIN) {
            pacientesRecuperados.insert(p);
            tablaPacientes.erase(p);
        }
        else {
            gravedadVector--;
            pacientesEsperando[gravedadVector].push_front(p);
            tablaPacientes[p] = { gravedadActual - 1 , pacientesEsperando[gravedadVector].begin() };
        }
    }

    std::vector<Paciente> recuperados() { // O(n) donde n es el numero de pacientes recuperados
        std::vector<Paciente> listaRecuperados(pacientesRecuperados.size());
        int i = 0;
        for (Paciente const& e : pacientesRecuperados) {
            listaRecuperados[i] = e;
            i++;
        }

        return listaRecuperados;
    }

};

#endif


