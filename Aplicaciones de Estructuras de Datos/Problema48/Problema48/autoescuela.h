#ifndef AUTOESCUELA
#define AUTOESCUELA

#include <unordered_map>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>

class Autoescuela {
private:
    using Profesor = std::string;
    using Alumno = std::string;
    using datosAlumno = std::pair <int, std::string>;
    using alumnosProfesorOrdenado = std::set<Alumno>;

    using TablaProfesores = std::unordered_map <Profesor, alumnosProfesorOrdenado>;  // clave : nombreProfesor && valor: conjuntoAlumnos
    using TablaAlumnos = std::unordered_map <Alumno, datosAlumno>; // clave : nombreAlumno valor : par puntuacion y nombre Profesor

    TablaAlumnos tablaAlumnos; 
    TablaProfesores tablaProfesores;

    /* k es el numero de alumnos de ese profesor*/

    TablaAlumnos::iterator findAlumno(Alumno alumno) { // O(1)

        auto it = tablaAlumnos.find(alumno);

        if (it == tablaAlumnos.end()) throw std::domain_error("El alumno " + alumno + " no esta matriculado.");

        return it;
    }

    void eraseAlumnoDeProfesor(Alumno alumno, Profesor profesor) {  //O (log k)

        auto it = tablaProfesores.find(profesor); // O(1)

        if(it != tablaProfesores.end()) it->second.erase(alumno); // O( log k ) 

    }
    void registrarAlumno(Alumno alumno,Profesor profesor) { // O (log k)

        auto it = tablaAlumnos.find(alumno); //O(1)

        if (it == tablaAlumnos.end()) tablaAlumnos.insert({ alumno,{0,profesor} }); // O(1)
        else {
            auto& profesorActual = it->second.second;
            if (profesorActual != profesor) {
                eraseAlumnoDeProfesor(alumno, profesorActual); //O( log k)
                profesorActual = profesor;
            }
        }
    }

    void registrarProfesor(Alumno alumno, Profesor profesor) {
        auto it = tablaProfesores.find(profesor); //O (1)

        if (it == tablaProfesores.end()) tablaProfesores.insert({ profesor,{alumno} }); // O(1)
        else it->second.insert(alumno); // O(log k)
    }

public:
    Autoescuela() {}; //sobrescritura del constructor por defecto

    void alta(Alumno const& alumno, Profesor const& profesor) {// O(log k)

        registrarProfesor(alumno, profesor);// O(log k)
        registrarAlumno(alumno, profesor);// O(log k)

    }
    bool esAlumno(Alumno const& alumno, Profesor const& profesor) { // O(log k)
 
        auto it = tablaProfesores.find(profesor); // O(1)

        if (it == tablaProfesores.end()) return false;

        auto const& alumnosProfesor = it->second;

        return alumnosProfesor.find(alumno) != alumnosProfesor.end();  // O(log k)
    }
   
    int puntuacion(Alumno const& alumno) {//O(1)

        auto it = findAlumno(alumno); 
        
        auto const & puntuacionAlumno = it->second.first;

        return puntuacionAlumno;
    }
    void actualizar(Alumno const& alumno, int n) { // O(1)

        auto it = findAlumno(alumno); 

        auto& puntuacionAlumno = it->second.first;
   
        puntuacionAlumno += n;
    }

    std::vector<std::string> examen(Profesor const &profesor, int puntuacion) {

        auto it = tablaProfesores.find(profesor); //O(1)

        if (it == tablaProfesores.end()) return {};

        auto const& alumnosProfesor = it->second;
        std::vector <std::string> alumnosExamen;

        for (Alumno const& a : alumnosProfesor) { // O (k)
         
            auto it = findAlumno(a); // O (1)
            auto const& putuacionAlumno = it->second.first;

            if (putuacionAlumno >= puntuacion) alumnosExamen.push_back(a);  // O (1)
               
        }

        return alumnosExamen;
    }

    void aprobar(Alumno const & alumno) { // O (log k)

       auto it = findAlumno(alumno);

       auto const& profesor = it->second.second;
       eraseAlumnoDeProfesor(alumno, profesor); // O (log k)

       tablaAlumnos.erase(alumno); // O(1)
    }

};

#endif


