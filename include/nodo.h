#ifndef NODO_H
#define NODO_H
  #include <vector>

template <typename T>
  class Nodo {
    protected:
      //Datos
      T dato;
  		Nodo* padre;
      std::vector<Nodo*> hijos;
      //Funciones de manipulacion
      //Constructor nodo hijo
      Nodo(Nodo* padre, T dato);

  	public:
      //Getters
      Nodo* getPadre() {return padre;}
      int getNumHijos() {return hijos.size();}
      Nodo* getHijo(int hijo) {return hijos[hijo];}
      T getDato() {return dato;}
      //Predicados
      bool esRaiz() {return getPadre()==nullptr;}
      bool esHoja() {return getNumHijos()==0;}
      //Funciones de manipulacion
      //Constructor nodo padre
      Nodo(T dato);
      //Destructor recursivo
      ~Nodo();
      //Creador de hijos
      Nodo* crearHijo(T dato);
      //Eliminadores de hijos
      void eliminarHijo(int hijo);
      void eliminarHijos();
  };

  //Implementacion de las funciones genericas
  //  no me preguntes por que es así, C++ exige sacrificios
  #include "nodoGenericImpl.cpp"
#endif
