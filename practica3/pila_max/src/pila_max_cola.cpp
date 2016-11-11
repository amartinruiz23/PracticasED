template <class T>

Pila_max<T>::Pila_max (){
  cola = Cola<Par>();
}

template <class T>

Pila_max<T>::Pila_max (const Pila_max<T>& p){
  cola = p.cola;
}

template <class T>

Pila_max<T>::~Pila_max (){
}

template <class T>

Pila_max<T>& Pila_max<T>::operator=(const Pila_max& p){
  cola = p.cola;
}

template <class T>

void Pila_max<T>::poner (T e){
  Par parparaponer;

  if(cola.vacia()){
    parparaponer.dato = e;
    parparaponer.max = e;
  }
  else{
    parparaponer.dato = e;
    if (e > cola.frente().max)
      parparaponer.max = e;
    else
      parparaponer.max = cola.frente().max;

  }
  cola.poner(parparaponer);
}

template <class T>

void Pila_max<T>::quitar(){
  Cola<Par> cola_aux;

  for (int i = 0; i < cola.num_elementos() - 1; i++){
    cola_aux.poner(cola.frente());
    cola.quitar();
  }

  cola = cola_aux;
}

template <class T>

Par<T> Pila_max<T>::tope() const{
  Cola<Par> cola_aux;
  cola_aux = cola;
  for (int i = 0; i < cola_aux.num_elementos() - 1; i++)
    cola_aux.quitar();
  return cola_aux.frente();
}
