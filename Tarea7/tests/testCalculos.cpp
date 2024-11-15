#include <gtest/gtest.h>
#include "../src/calculos.hpp"

using namespace std;

// Prueba válida para el método de sumar resistencias en serie
TEST(CalculosTest, ResistenciaSerieValida) {
    vector<double> resistencias = {100, 200, 300};
    EXPECT_DOUBLE_EQ(Calculos::resistenciaSerie(resistencias), 600.0);
}

// Prueba válida para el método de sumar resistencias en paralelo
TEST(CalculosTest, ResistenciaParaleloValida) {
    vector<double> resistencias = {10000, 1000};
    EXPECT_NEAR(Calculos::resistenciaParalelo(resistencias), 909.09, 0.01);
}

// Prueba válida para el método de sumar capacitancias en serie
// Como todos los métodos de cálculo para cada tipo de impedancia tienen el mismo template, no es necesario probarlos todos 
TEST(CalculosTest, CapacitanciaSerieValida) {
    vector<double> capacitancias = {100, 200};
    EXPECT_DOUBLE_EQ(Calculos::capacitanciaSerie(capacitancias), 300);
}

// Capacitancias en paralelo, con argumentos validos
TEST(CalculosTest, CapacitanciaParalelaValida) {
    vector<double> capacitancias = {100, 200};
    EXPECT_NEAR(Calculos::capacitanciaParalelo(capacitancias), 66.67, 0.01);
}

// Capacitancias en paralelo con argumentos invalidos
TEST(CalculosTest, CapacitanciaParalelaInvalida) {
    vector<double> capacitancias = {-10, 100.5};
    EXPECT_THROW(Calculos::validarValores(capacitancias), invalid_argument);
}

// Se prueba el manejo del error de lista vacía (no se brindaron argumentos para los valores de las resistencias, capacitancias, etc.)
TEST(CalculosTest, ListaVaciaLanzaExcepcion) {
    vector<double> vacio;
    EXPECT_THROW(Calculos::validarValores(vacio), invalid_argument);
}

// Se prueba validar valores no permitidos (números negativos)
TEST(CalculosTest, ValoresNegativosLanzanExcepcion) {
    vector<double> valoresInvalidos = {100, -50, 300};
    EXPECT_THROW(Calculos::validarValores(valoresInvalidos), invalid_argument);
}
