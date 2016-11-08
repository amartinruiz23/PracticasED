#include "pila_max_cola.h"

Pila_max (){
  cola = Cola();
}

Pila_max (const Pila_max& p){
  cola = p.cola;
}

~Pila_max (){
  ~cola;
}

Pila_max& operator=(const Pila_max& p){
  cola = p.cola;
}

bool vacia() const { return cola.vacia()==0; }

void poner (T e){}

void quitar(){}

T tope() const{}
