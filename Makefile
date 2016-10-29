SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CXXFLAGS = -Wall -g -I$(INC) -c


all: $(BIN)/pruebacronologia

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebacronologia: $(OBJ)/evento.o $(OBJ)/cronologia.o
	$(CXX) -o $(BIN)pruebacronologia $(OBJ)/evento.o $(OBJ)/cronologia.o

$(OBJ)/evento.o: $(SRC)/evento.cpp $(INC)/evento.h
	$(CXX) $(CXXFLAGS) $(SRC)/evento.cpp -o $(OBJ)/evento.o

$(OBJ)/cronologia.o: $(SRC)/cronologia.cpp $(INC)/cronologia.h
	$(CXX) $(CXXFLAGS) $(SRC)/cronologia.cpp -o $(OBJ)/cronologia.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
