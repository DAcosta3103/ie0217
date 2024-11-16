cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(Tarea7)

# Configuración de GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Habilitar cobertura de código
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

# Archivos fuente principales
set(SOURCE_FILES
    src/inventario.cpp
    src/calculos.cpp
)

# Configuración de la prueba para Inventario
add_executable(testInventario tests/testInventario.cpp ${SOURCE_FILES})
target_link_libraries(testInventario ${GTEST_LIBRARIES} gtest_main pthread)

# Configuración de la prueba para Cálculos
add_executable(testCalculos tests/testCalculos.cpp ${SOURCE_FILES})
target_link_libraries(testCalculos ${GTEST_LIBRARIES} gtest_main pthread)

# Configuración de la prueba funcional
add_executable(FunctionalTest tests/functionalTesting.cpp ${SOURCE_FILES})
target_link_libraries(FunctionalTest ${GTEST_LIBRARIES} gtest_main pthread)

# Configuración de la prueba de capacitancia equivalente
add_executable(testCapacitancia tests/testTDD.cpp ${SOURCE_FILES})
target_link_libraries(testCapacitancia ${GTEST_LIBRARIES} gtest_main pthread)