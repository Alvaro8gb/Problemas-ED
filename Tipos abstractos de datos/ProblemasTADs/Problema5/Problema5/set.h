#ifndef SET
#define SET

#include <cstddef> // size_t
#include <stdexcept> // std :: domain_error
#include <utility> // std :: moveclass set
#include <algorithm> // std:: lower_bound
#include <iostream>

template < typename T >
class set { //clase conjunto
public:

    set(); // constructor
    set(set < T > const& other); // constructor por copia
    set < T >& operator = (set <T> const& other); // operador de asignacion
    ~set(); // destructor
    void insert(T e);
    bool contains(T e) const;
    void erase(T e);
    bool empty() const;
    size_t size() const;
    T min() const;
    void erase_min();
    void print() const;

private:
    size_t contador;
    size_t capacidad;
    T* datos; // sin repeticiones
    void amplia();
    void libera();
    void copia(set < T > const& other);
    void ordenarInsercion();
};

///******** Implementaciones ******///

template < typename T >
void  set < T > ::print() const {

   for (int i = contador-1; i >=0 ; i--) std::cout << datos[i] << " ";
   //for (int i = 0; i < contador ; i++) std::cout << datos[i] << " ";

}

// Constructor
template <typename T>
set <T> ::set() : contador(0), capacidad(8), datos(new T[capacidad]) {}

// Destructor
template < typename T >
set < T > ::~set() {
    libera();
}

// Op. privada que libera la memoria dinamica
template < typename T >
void set < T > ::libera() {
    delete[] datos;
}

// constructor por copia
template < typename T >
set <T> ::set(set <T> const& other) {
    copia(other);
}

// Op. privada que copia el contenido de un vector
template <typename T>
void set < T > ::copia(set < T >
    const& other) {
    capacidad = other.capacidad;
    contador = other.contador;
    datos = new T[capacidad];
    for (size_t i = 0; i < contador; ++i) datos[i] = other.datos[i];
}
// operador de asignacion
template < typename T >
set < T >& set < T > ::operator = (set < T >
    const& other) {
    if (this != &other) {
        libera();
        copia(other);
    }
    return *this;
}

// Operacion para anyadir elementos
template <typename T>
void  set < T > ::insert(T e) {
    if (!contains(e)) {
        if (contador == capacidad) amplia();
           datos[contador] = e;
           ordenarInsercion();
           contador++;    
          
    }
    else throw std::domain_error("El elemento ya esta ");
}
// Op. privada que amplia la memoria del vector
template < typename T >
void set < T > ::amplia() {
    T* nuevos = new T[2 * capacidad];
    for (size_t i = 0; i < capacidad; ++i) nuevos[i] = std::move(datos[i]);
    delete[] datos;
    datos = nuevos;
    capacidad *= 2;
}
// Operacion que comprueba si un elemento pertenece al conjunto
template < typename T >
bool set <T> ::contains(T e) const { return  std::binary_search( datos, datos+contador,e, std::greater<T>()); }
// Operacion que elimina un elemento del conjuto
// Lanza una excepcion si el elemento no esta
template < typename T >
void set < T > ::erase(T e) {
    size_t i = 0;

    auto it = std::lower_bound(datos, datos + contador, e);

    if (it == datos + contador) throw std::domain_error("El elemento no esta ");
    else {
        size_t pos = it - datos;

        for (size_t i = pos; i < contador - 1; i++) {
            datos[i] = datos[i + 1];
        }
        --contador;
    }

}
// Comprueba si el conjunto esta vacio
template < typename T >
bool set < T > ::empty() const {
    return contador == 0;
}

// Obtiene el numero de elementos del conjunto
template < typename T >
size_t set < T > ::size() const {
    return contador;
}
template < typename T >
T set < T > ::min() const {
    if (contador == 0) throw std::domain_error("No existe minimo ");

    return datos[contador-1];
}
template < typename T >
void set < T > ::erase_min() {
 --contador;
}
template <typename T>
void set <T> ::ordenarInsercion() {

    T tmp = datos[contador];
    int  i = contador - 1;
    bool fin = false;

    if (contador > 0) {
        while (!fin && i >= 0) {
      
            if (datos[i] > tmp ) fin = true;
            else --i;
        }
       
        for (int  j = contador-1; j > i; j--) {
                datos[j+1] = datos[j];
        }
        datos[i+1] = tmp;
    }   
}

#endif 