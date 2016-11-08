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

void poner (T e){
  Par parparaponer;
  Cola cola_aux;
  
  parparaponer.dato = e;
  if (e > cola.frente().max)
    parparaponer.max = e;
  else
    parparaponer.max = cola.frente().max;

  cola_aux.poner(parparaponer);

  for (int i = 0; i < )
}

void quitar(){

}

T tope() const{
  cola_aux = cola;
  for (int i = 0; i < cola_aux.num_elementos() - 1; i++)
    cola_aux.quitar();
  return cola_aux.frente();
}
