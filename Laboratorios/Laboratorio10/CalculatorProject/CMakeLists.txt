cmake_minimum_required(VERSION 3.10)
project(CalculatorProject)

# Agregar los archivos fuente del proyecto
set(SOURCES src/Calculator.cpp)

# Crear el ejecutable para el proyecto principal
add_library(calculator_lib ${SOURCES})

# Incluir GoogleTest como subdirectorio
add_subdirectory(googletest)  # Esto debería apuntar a la carpeta de GoogleTest que clonamos

# Incluir directorios de GoogleTest
include_directories(googletest/googletest/include)

# Agregar GoogleTest y configurar las pruebas
enable_testing()
add_subdirectory(tests)
