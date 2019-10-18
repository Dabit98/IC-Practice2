#include <iostream>

//Funciones de manipulacion
//Constructor nodo hijo
template <typename T>
Nodo<T>::Nodo(Nodo* padre, T dato) : Nodo<T>::Nodo(dato) {
  this->padre = padre;
}

//Constructor nodo padre
template <typename T>
Nodo<T>::Nodo(T dato) {
  this->padre = nullptr;
  this->dato = dato;
}

//Creador de hijos
template <typename T>
Nodo<T>* Nodo<T>::crearHijo(T dato) {
  Nodo<T>* hijo = new Nodo(this, dato);
  hijos.push_back(hijo);
  return hijo;
}

//Eliminadores de hijos
template <typename T>
void Nodo<T>::eliminarHijo(int hijo) {
  Nodo* borrar = hijos[hijo];
  hijos.erase(hijos.begin()+hijo);
  delete borrar;
}

template <typename T>
void Nodo<T>::eliminarHijos() {
  while(!hijos.empty()){
    delete hijos.back();
    hijos.pop_back();
  }
}

//Destructor recursivo
template <typename T>
Nodo<T>::~Nodo() {
  eliminarHijos();
  std::cout << "SE MUERE " << dato << std::endl;
}
