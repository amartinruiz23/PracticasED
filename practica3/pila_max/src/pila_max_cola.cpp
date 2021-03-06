/**
  * @file pila_max_cola.cpp
  * @brief Implementación del TDA Pila_max versión cola
  *
  */


template <class T>

Pila_max<T>::Pila_max (){
  cola = Cola<Par<T> >();
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
  Par<T> parparaponer;

	parparaponer.dato = e;

  if(cola.vacia())
    parparaponer.max = e;
  else{
    if (e > cola.frente().max)
      parparaponer.max = e;
    else
      parparaponer.max = cola.frente().max;

  }
  cola.poner(parparaponer); 
}

template <class T>

void Pila_max<T>::quitar(){
  Cola<Par<T> > cola_aux;
	int iteraciones = cola.num_elementos()-1 ;

  for (int i = 0; i < iteraciones; i++){
    cola_aux.poner(cola.frente());
    cola.quitar();
  }

  cola = cola_aux;
}

template <class T>

Par<T> Pila_max<T>::tope() const{
  Cola<Par<T> > cola_aux;
  cola_aux = cola;
  for (int i = 0; i < cola.num_elementos() - 1; i++)
    cola_aux.quitar();
  return cola_aux.frente();
}
