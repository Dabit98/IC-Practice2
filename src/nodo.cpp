#include "nodo.h"

#include <iostream>

//Funciones de manipulacion
//Constructor nodo hijo
Nodo::Nodo(Nodo* padre) {
  std::cout << "CREADO NODO " << this << std::endl;
  std::cout << "\tHIJO DE " << padre << std::endl;
  this->padre = padre;
}

//Constructor nodo padre
Nodo::Nodo() {
  std::cout << "CREADO NODO " << this << std::endl;
  this->padre = NULL;
}
//Destructor recursivo
Nodo::~Nodo() {
  eliminarHijos();
  std::cout << "BORRADO NODO " << this << std::endl;
}
//Creador de hijos
Nodo* Nodo::crearHijo() {
  Nodo* hijo = new Nodo(this);
  hijos.push_back(hijo);
  return hijo;
}
//Eliminadores de hijos
void Nodo::eliminarHijo(int hijo) {
  Nodo* borrar = hijos[hijo];
  hijos.erase(hijos.begin()+hijo);
  delete borrar;
}
void Nodo::eliminarHijos() {
  while(!hijos.empty()){
    delete hijos.back();
    hijos.pop_back();
  }
}
