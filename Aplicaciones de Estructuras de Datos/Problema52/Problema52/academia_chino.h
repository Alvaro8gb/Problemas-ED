#ifndef ACADEMIA_CHINO
#define ACADEMIA_CHINO

#include <unordered_map>
#include <set>
#include <stdexcept>
#include <vector>
#include <list>

class AcademiaChino {
private:
    const int _MAX_GRUPOS = 6;
    using Estudiante = std::string;

    using TablaEstudiantes = std::unordered_map <Estudiante,std::pair<int ,std::list<Estudiante> ::iterator>>;  // clave :nombre Alumno y valor grupo y si esta grauado

    std::set <Estudiante> alumnosGraduados;
    std::vector<std::list<Estudiante>> novatos;
    TablaEstudiantes tablaEstudiantes;

     void validarGrupo(int grupo) const{ // O(1)
         if (grupo < 1 || grupo > 6) throw std::domain_error("Grupo incorrecto");
     }

     TablaEstudiantes::iterator findEstudiante(Estudiante e) {// O(1)

         auto it = tablaEstudiantes.find(e);

         if (it == tablaEstudiantes.end()) throw std::domain_error("Estudiante no existente");

         if (it->second.first == -1) throw std::domain_error("Estudiante ya graduado");

         return it;

     }

public:
    AcademiaChino(): novatos(_MAX_GRUPOS) { }; 

    void nuevo_estudiante(Estudiante e, int grupo) { // O(1)

        if (tablaEstudiantes.count(e)) throw std::domain_error("Estudiante existente");

        validarGrupo(grupo); // O(1)

        int grupoVector = grupo-1;

        novatos[grupoVector].push_front(e); // O(1)

        tablaEstudiantes[e] = { grupo,novatos[grupoVector].begin() }; // O(1)
     
    }
 
    int grupo_estudiante(Estudiante e ) {// O(1)
     
        auto it = findEstudiante(e);// O(1)
        return it->second.first;
    }

    void promocionar(Estudiante e) { // O(long n) n numero de graduados de la academia

        auto it = findEstudiante(e); // O(1)
   
        auto & grupoActual = it->second.first;

        int grupoVector = it->second.first - 1;

        novatos[grupoVector].erase(it->second.second);   // O(1)

        if (grupoActual == _MAX_GRUPOS) {
            alumnosGraduados.insert(e); // O(log n)
            tablaEstudiantes[e] = {-1, novatos[grupoVector].end() };  // O(1)
        }
        else {
            grupoVector++;
            novatos[grupoVector].push_front(e);
            tablaEstudiantes[e] = { grupoActual + 1,novatos[grupoVector].begin() };
        }
       
    }

    std::vector<Estudiante> graduados() { // O(n) donde n es el numero de graduados de la academia
        std::vector<Estudiante> listaGraduados(alumnosGraduados.size() ) ;
        int i = 0;
        for (Estudiante const& e : alumnosGraduados) {
            listaGraduados[i] = e;
            i++;
        }

        return listaGraduados;
    }

    Estudiante novato(int grupo) const {// O(1)
        validarGrupo(grupo);

        auto const & novatosGrupo = novatos[grupo - 1];  // O(1)

        if (novatosGrupo.empty() )  throw std::domain_error("Grupo vacio");
       
        return novatosGrupo.front();
    }
};

#endif


