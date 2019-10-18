#ifndef NODO_H
#define NODO_H
  #include <iostream>
  #include <vector>

  class Nodo {
    protected:
      //Datos
  		Nodo* padre;
      std::vector<Nodo*> hijos;
      //Funciones de manipulacion
      //Constructor nodo hijo
      Nodo(Nodo* padre);

  	public:
      //Getters
      Nodo* getPadre() {return padre;}
      int getNumHijos() {return hijos.size();}
      Nodo* getHijo(int hijo) {return hijos[hijo];}
      //Predicados
      bool esRaiz() {return getPadre()==NULL;}
      bool esHoja() {return getNumHijos()==0;}
      //Funciones de manipulacion
      //Constructor nodo padre
      Nodo();
      //Destructor recursivo
      ~Nodo();
      //Creador de hijos
      Nodo* crearHijo();
      //Eliminadores de hijos
      void eliminarHijo(int hijo);
      void eliminarHijos();
  };


#endif
