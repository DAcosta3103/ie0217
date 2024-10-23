# Define el compilador y los flags
CC := g++
CFLAGS := -Wall -Wextra -std=c++17

# Directorios
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# Archivos fuente para main
MAIN_SOURCES := $(SRC_DIR)/main.cpp

# Archivos fuente para main10Iteraciones
MAIN10_SOURCES := $(SRC_DIR)/main10Iteraciones.cpp

# Archivos objeto
MAIN_OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(MAIN_SOURCES))
MAIN10_OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(MAIN10_SOURCES))

# Ejecutables
MAIN_EXECUTABLE := $(BIN_DIR)/main
MAIN10_EXECUTABLE := $(BIN_DIR)/main10

# Regla principal - ejecuta el archivo main.cpp
all: $(MAIN_EXECUTABLE)
	@echo "Ejecutando programa main..."
	$(MAIN_EXECUTABLE)

# Regla para compilar y ejecutar main10Iteraciones.cpp
10: $(MAIN10_EXECUTABLE)
	@echo "Ejecutando programa main10Iteraciones..."
	$(MAIN10_EXECUTABLE)

# Compila el ejecutable de main.cpp
$(MAIN_EXECUTABLE): $(MAIN_OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJECTS)

# Compila el ejecutable de main10Iteraciones.cpp
$(MAIN10_EXECUTABLE): $(MAIN10_OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(MAIN10_OBJECTS)

# Compila los archivos fuente de main.cpp en objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpia los archivos generados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
