
class evento{
  int anio;
  vector<string> sucesos;

  public:

  evento::evento(){
    anio = 0;
  }

  evento::evento(const evento& e){
    anio = e.getanio();
    sucesos = e.getsucesos();
  }

  evento::~evento(){
    anio = 0;
    ~sucesos;
  }

  evento::&evento operator=(evento& e){
    anio = e.getanio();
    sucesos = e.getsucesos();
    return *this; //????
  }

  evento::int getanio(const evento& e){
    return anio;
  }

  evento::vector getsucesos(const evento& e){
    return sucesos;
  }

  evento::string getsuceso(const evento& e, int n){
    return sucesos.at(n-1); //at devuelve una referencia al elemento en la posición indicada del vector. Lanza excepción si fuera de rango.
  }

  evento::void aniadesuceso(string s, int p){
    sucesos.insert(p-1, s);
  }

  evento::void eliminasuceso(int n){
    suceso.erase(n-1);
  }

};
