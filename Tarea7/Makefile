# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g
SRCDIR = src
TARGET = main

# Archivos fuente y objetos
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Reglas
all: $(TARGET)
	@./$(TARGET) # Ejecuta el programa después de compilar

# Regla para compilar el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar cada archivo objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(SRCDIR)/*.o $(TARGET)

# PHONY targets
.PHONY: all clean
