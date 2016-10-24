

void cronologia::ordenar(){}

cronologia::cronologia(){} // Al tener solo un vector la clase, esta función es necesaria???

cronologia::cronologia(const cronologia& c){
  eventos = c.geteventos();
}

cronologia::~cronologia(){} //Igual que con constructor vacío

cronologia cronologia::subcronologia(int anio_inicio, int anio_final=2017){
  cronologia devolver;
  for (int i = 0, i < eventos.size(), i++){
    if (eventos[i].getanio() <= anio_inicio && eventos[i].getanio() >= anio_final)
      devolver.aniadirevento(eventos[i]);
  }
  return devolver;
}

cronologia& operator+(const cronologia& c){} // operator+ o funcion mezcla ??????????????????

bool cronologia::eliminarevento (int anio){
bool eliminado = 0;
  for (int i = 0, i < eventos.size(), i++){
    if (eventos[i].getanio() == anio){
      eventos.erase(i);
      eliminado = 1;
    }
  }
  return eliminado;
}

bool cronologia::aniadirevento (evento& e){
}

evento cronologia::buscaevento (int anio){}

vector buscaevento (const string& s){}

vector geteventos(){
  return eventos;
}
