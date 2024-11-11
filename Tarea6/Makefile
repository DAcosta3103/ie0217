# Makefile para compilar y ejecutar los programas en src/administracion y src/depuracion

# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++20 -pthread

# Directorios
SRC_DIR = src
ADMIN_DIR = $(SRC_DIR)/administracion
DEPUR_DIR = $(SRC_DIR)/depuracion

# Archivos fuente y ejecutables
ADMIN_SOURCES = $(ADMIN_DIR)/sistema.cpp $(ADMIN_DIR)/main.cpp
ADMIN_EXEC = $(ADMIN_DIR)/sistema

DATA_PROC_SOURCE = $(DEPUR_DIR)/DataProcessor.cpp
DATA_PROC_EXEC = $(DEPUR_DIR)/dataP

# Reglas
all: sistema dataP

sistema: $(ADMIN_SOURCES)
	$(CXX) $(CXXFLAGS) $(ADMIN_SOURCES) -o $(ADMIN_EXEC)
	./$(ADMIN_EXEC)  # Ejecutar el programa después de compilar

dataP: $(DATA_PROC_SOURCE)
	$(CXX) $(CXXFLAGS) $(DATA_PROC_SOURCE) -o $(DATA_PROC_EXEC)
	./$(DATA_PROC_EXEC)  # Ejecutar el programa después de compilar

# Limpieza de archivos binarios
clean:
	rm -f $(ADMIN_EXEC) $(DATA_PROC_EXEC)
