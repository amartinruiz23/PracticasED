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

cronologia& operator+(const cronologia& c){
  bool sumados = 0;
  for (int i = 0, i < c.eventos.size(), i++){
    for (int j = 0; j < eventos.size(), j++){
      if ( c.eventos[i] == eventos[j]{
        eventos[i] = c.eventos[i] + eventos[j];
        sumados = TRUE;
      }
    }
    if (!sumados){
      aniadirevento(c.eventos[i]);
      sumados = FALSE;
    }
  }
  ordenar();
  return *this;
}

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

evento cronologia::buscaevento (int anio){
  evento vacio;
  for (int i = 0; i < eventos.size(); i++){
    if(eventos[i].getanio() == anio)
      return eventos[i];
  }
  return vacio;
}

vector buscaevento (const string& s){}

vector geteventos(){
  return eventos;
}
