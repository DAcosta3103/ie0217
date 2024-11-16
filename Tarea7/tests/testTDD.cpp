#include <gtest/gtest.h>
#include "../src/calculos.hpp"

using namespace std;

// Prueba válida para capacitancia equivalente combinada en serie y paralelo
TEST(CalculosTest, CapacitanciaEquivalenteSerieParaleloValida) {
    vector<double> serie = {50, 50};   // Dos capacitores en serie
    vector<double> paralelo = {100, 100}; // Dos capacitores en paralelo



    EXPECT_DOUBLE_EQ(Calculos::capacitanciaEquivalenteSerieParalelo(serie, paralelo), 150);
}

// Prueba con una lista vacía para serie
TEST(CalculosTest, CapacitanciaEquivalenteSerieVacia) {
    vector<double> serie;  // Lista vacía
    vector<double> paralelo = {300, 400};

    EXPECT_THROW(Calculos::capacitanciaEquivalenteSerieParalelo(serie, paralelo), invalid_argument);
}

// Prueba con valores negativos en paralelo
TEST(CalculosTest, CapacitanciaEquivalenteParaleloNegativa) {
    vector<double> serie = {100, 200};
    vector<double> paralelo = {300, -400}; // Valor negativo en paralelo

    EXPECT_THROW(Calculos::capacitanciaEquivalenteSerieParalelo(serie, paralelo), invalid_argument);
}

// Prueba con ambas listas vacías
TEST(CalculosTest, CapacitanciaEquivalenteAmbasListasVacias) {
    vector<double> serie;    // Lista vacía
    vector<double> paralelo; // Lista vacía

    EXPECT_THROW(Calculos::capacitanciaEquivalenteSerieParalelo(serie, paralelo), invalid_argument);
}