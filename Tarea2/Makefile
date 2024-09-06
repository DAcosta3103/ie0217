# Define el compilador y los flags
CC := g++
CFLAGS := -Wall -Wextra -std=c++17

# Directorios
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
DOC_DIR := docs

# Archivos fuente
SOURCES := $(SRC_DIR)/main.cpp
HEADERS := $(SRC_DIR)/Cliente.hpp $(SRC_DIR)/Producto.hpp $(SRC_DIR)/Tienda.hpp

# Archivos objeto
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Ejecutable
EXECUTABLE := $(BIN_DIR)/tiendaVirtual

# Regla principal
all: $(EXECUTABLE) docs

# Compila el ejecutable del programa
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

# Compila los archivos fuente en objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Genera la documentación con Doxygen
docs:
	@mkdir -p $(DOC_DIR)
	doxygen Doxyfile

# Limpia los archivos generados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(DOC_DIR)

# Ejecuta el programa
run: $(EXECUTABLE)
	$(EXECUTABLE)