# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2   # Wall: warning all
SRCDIR = src
OBJDIR = obj
BINDIR = bin
TARGET = $(BINDIR)/text_processor.exe

# Archivos fuente y objetos
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Reglas
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET) data/file1.txt

.PHONY: all clean run
