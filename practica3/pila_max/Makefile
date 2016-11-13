SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/usocolas $(BIN)/usopilas_max

$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o
	$(CXX) -o $(BIN)/usopilas_max $(OBJ)/usopilas_max.o

$(OBJ)/usopilas_max.o: $(SRC)/usopilas_max.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usopilas_max.cpp -o $(OBJ)/usopilas_max.o

$(BIN)/usocolas: $(OBJ)/usocolas.o
	$(CXX) -o $(BIN)/usocolas $(OBJ)/usocolas.o

$(OBJ)/usocolas.o: $(INC)/cola.h $(SRC)/usocolas.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usocolas.cpp  -o $(OBJ)/usocolas.o
    

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
