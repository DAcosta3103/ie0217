# Define el compilador y los flags
CC := g++
CFLAGS := -Wall -Wextra -std=c++17

# Directorios
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Archivos fuente para arbol
ARBOLES_SOURCES := $(SRC_DIR)/arbol/arbol.cpp $(SRC_DIR)/arbol/main.cpp

# Archivos fuente para lista de canciones
LISTA_SOURCES := $(SRC_DIR)/listaDeCanciones/lista.cpp $(SRC_DIR)/listaDeCanciones/main.cpp

# Archivos objeto
ARBOLES_OBJECTS := $(patsubst $(SRC_DIR)/arbol/%.cpp,$(OBJ_DIR)/arbol/%.o,$(ARBOLES_SOURCES))
LISTA_OBJECTS := $(patsubst $(SRC_DIR)/listaDeCanciones/%.cpp,$(OBJ_DIR)/listaDeCanciones/%.o,$(LISTA_SOURCES))

# Ejecutables
ARBOLES_EXECUTABLE := $(BIN_DIR)/arbol
LISTA_EXECUTABLE := $(BIN_DIR)/lista

# Regla principal
all: $(ARBOLES_EXECUTABLE) $(LISTA_EXECUTABLE)
	@echo "Ejecutando programa de arbol..."
	$(ARBOLES_EXECUTABLE)
	@echo "Ejecutando programa de lista de canciones..."
	$(LISTA_EXECUTABLE)

# Compila el ejecutable de arbol
$(ARBOLES_EXECUTABLE): $(ARBOLES_OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(ARBOLES_OBJECTS)

# Compila el ejecutable de lista de canciones
$(LISTA_EXECUTABLE): $(LISTA_OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(LISTA_OBJECTS)

# Compila los archivos fuente de arbol en objetos
$(OBJ_DIR)/arbol/%.o: $(SRC_DIR)/arbol/%.cpp
	@mkdir -p $(OBJ_DIR)/arbol
	$(CC) $(CFLAGS) -c $< -o $@

# Compila los archivos fuente de lista de canciones en objetos
$(OBJ_DIR)/listaDeCanciones/%.o: $(SRC_DIR)/listaDeCanciones/%.cpp
	@mkdir -p $(OBJ_DIR)/listaDeCanciones
	$(CC) $(CFLAGS) -c $< -o $@

# Limpia los archivos generados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
