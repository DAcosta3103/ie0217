# Define el compilador y los flags
CC := g++
CFLAGS := -Wall -Wextra -std=c++17

# Directorios
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Archivos fuente
CONVERSOR_SOURCES := $(SRC_DIR)/conversorDeUnidades.cpp $(SRC_DIR)/mainConversorDeUnidades.cpp
CALCULADORA_SOURCES := $(SRC_DIR)/calculadoraEstadisticas.cpp $(SRC_DIR)/mainCalculadoraEstadisticas.cpp

# Archivos objeto
CONVERSOR_OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CONVERSOR_SOURCES))
CALCULADORA_OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CALCULADORA_SOURCES))

# Ejecutables
CONVERSOR_EXECUTABLE := $(BIN_DIR)/conversor
CALCULADORA_EXECUTABLE := $(BIN_DIR)/calculadora

# Argumentos para el programa de calculadora de estadísticas, se pueden cambiar a conveniencia
CALCULADORA_ARGS := 2 5 3 7 10 3 

# Regla principal
all: $(CONVERSOR_EXECUTABLE) $(CALCULADORA_EXECUTABLE)

# Compila el ejecutable del conversor de unidades
$(CONVERSOR_EXECUTABLE): $(CONVERSOR_OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(CONVERSOR_OBJECTS)

# Compila el ejecutable de la calculadora de estadísticas
$(CALCULADORA_EXECUTABLE): $(CALCULADORA_OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(CALCULADORA_OBJECTS)

# Compila los archivos fuente en objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpia los archivos generados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Ejecuta los programas en orden
run: all
	@echo "Ejecutando conversor de unidades..."
	$(CONVERSOR_EXECUTABLE)
	@echo "Ejecutando calculadora de estadísticas con argumentos $(CALCULADORA_ARGS)..."
	$(CALCULADORA_EXECUTABLE) $(CALCULADORA_ARGS)
