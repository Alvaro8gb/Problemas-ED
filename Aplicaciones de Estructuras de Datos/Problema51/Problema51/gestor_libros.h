#ifndef GESTOR_LIBROS
#define GESTOR_LIBROS

#include <unordered_map>
#include <stdexcept>
#include <list>
#include <map>
#include <vector>

class Gestor_Libros {
private:

    using Libro = std::string;

    using infoLibro = struct {
        int numEjemplares;
        int numLibrosVendidos;
        std::list <Libro> ::iterator it;
    };

    using TablaLibros = std::unordered_map <Libro, infoLibro>;
    using TablaLibrosVendidos = std::map<int, std::list<Libro>>; //clave: numero de libros vendidos y valor lista de libros con esa cantida de librosVendidos

    TablaLibros tablaLibros;
    TablaLibrosVendidos tablaLibrosVendidos;

    TablaLibros::iterator findLibro(Libro libro) {
        auto it = tablaLibros.find(libro);

        if (it == tablaLibros.end()) throw std::invalid_argument("Libro no existente");

        return it;
    }

public:

    Gestor_Libros() { } //creacion de un gestor de libros vacios

    void nuevoLibro(int numEjemplares, Libro libro) {
        tablaLibros[libro].numEjemplares += numEjemplares;
    }
    
    void comprar(Libro libro) {

        auto it = findLibro(libro);
        auto& infoLibro = it->second;

        if (infoLibro.numEjemplares == 0) throw std::out_of_range("No hay ejemplares");

        if (infoLibro.numLibrosVendidos == 0) { // No estaba
            infoLibro.numLibrosVendidos++;
            tablaLibrosVendidos[infoLibro.numLibrosVendidos].push_back(libro);
            auto itLista = --tablaLibrosVendidos[infoLibro.numLibrosVendidos].end();
            infoLibro.it = itLista;
        }
        else {

            tablaLibrosVendidos[infoLibro.numLibrosVendidos].erase(infoLibro.it);

            infoLibro.numLibrosVendidos++;

            tablaLibrosVendidos[infoLibro.numLibrosVendidos].push_back(libro);
            auto itLista = --tablaLibrosVendidos[infoLibro.numLibrosVendidos].end();
            infoLibro.it = itLista;
        }

        infoLibro.numEjemplares--;

    }

    bool estaLibro(Libro libro) {
        return tablaLibros.count(libro);
    }

    void elimLibro(Libro libro) {
        
        auto it = tablaLibros.find(libro);

        if (it != tablaLibros.end()) {
 
            auto const & infoLibro = it->second;
            if(infoLibro.numLibrosVendidos != 0) tablaLibrosVendidos[infoLibro.numLibrosVendidos].erase(infoLibro.it);
            tablaLibros.erase(libro);
        }
        
    }
    int numEjemplares(Libro libro) {
        auto it = findLibro(libro);
        return it->second.numEjemplares;
    }

    std::vector<Libro> top10() {

        auto it = tablaLibrosVendidos.end();
        std::vector<Libro> top10 ;
        int i = 0;

        while (i < 10 && it != tablaLibrosVendidos.begin() ) {
            it--;
            auto itList = it->second.end();

            while (i < 10 && itList != it->second.begin()) {
                itList--;
                top10.push_back(*itList);
                i++;   
            }
        }

        return top10;
    }

};


#endif


