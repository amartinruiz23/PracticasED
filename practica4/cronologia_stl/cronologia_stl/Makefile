# Antonio Martín Ruíz y Álvaro López Jiménez

SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -c

all: $(BIN)/union_cronologia $(BIN)/filtrado_por_clave $(BIN)/filtrado_por_intervalo $(BIN)/estadisticas

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/union_cronologia:
	$(CXX) $(SRC)/union_cronologia.cpp $(SRC)/cronologia.cpp $(SRC)/eventohistorico.cpp -o $(BIN)/union_cronologia $(CPPFLAGS)

$(BIN)/filtrado_por_clave:
	$(CXX) $(SRC)/filtrado_por_clave.cpp $(SRC)/cronologia.cpp $(SRC)/eventohistorico.cpp -o $(BIN)/filtrado_por_clave $(CPPFLAGS)

$(BIN)/filtrado_por_intervalo:
	$(CXX) $(SRC)/filtrado_por_intervalo.cpp $(SRC)/cronologia.cpp $(SRC)/eventohistorico.cpp -o $(BIN)/filtrado_por_intervalo $(CPPFLAGS)

$(BIN)/estadisticas:
	$(CXX) $(SRC)/estadisticas.cpp $(SRC)/cronologia.cpp $(SRC)/eventohistorico.cpp -o $(BIN)/estadisticas $(CPPFLAGS)
# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
