#include "calculos.hpp"
#include <iostream>

using namespace std;

// método para validar los valores
void Calculos::validarValores(const vector<double>& valores) {  // se recibe una lista con valores de tipo doubles
    if (valores.empty()) {
        throw invalid_argument("No se puede tener una lista vacía.");
    }

    // se verifica que no está vacía, entonces se recorre la lista
    for (const auto& valor : valores) {
        if (valor <= 0) {
            throw invalid_argument("Todos los valores deben ser mayores a cero.");
        }
    }
}
// metodos para resistencias 

double Calculos::resistenciaSerie(const vector<double>& resistencias) {
    validarValores(resistencias);
    // se recorre todo el vector y se suman los valores con la función accumulate
    return accumulate(resistencias.begin(), resistencias.end(), 0.0);
}

double Calculos::resistenciaParalelo(const vector<double>& resistencias) {
    validarValores(resistencias);
    double suma = 0.0;

    for (const auto& resistencia : resistencias) {
        suma += 1.0/resistencia;
    }
    return 1.0/suma;
} 

// metodos para capacitancias

double Calculos::capacitanciaSerie(const vector<double>& capacitancias) {
    validarValores(capacitancias);
    // se recorre todo el vector y se suman los valores con la función accumulate
    return accumulate(capacitancias.begin(), capacitancias.end(), 0.0);
}

double Calculos::capacitanciaParalelo(const vector<double>& capacitancias) {
    validarValores(capacitancias);
    double suma = 0.0;

    for (const auto& capacitancia : capacitancias) {
        suma += 1.0/capacitancia;
    }
    return 1.0/suma;
} 

// metodos para inductancias 

double Calculos::inductanciaSerie(const vector<double>& inductancias) {
    validarValores(inductancias);
    // se recorre todo el vector y se suman los valores con la función accumulate
    return accumulate(inductancias.begin(), inductancias.end(), 0.0);
}

double Calculos::inductanciaParalelo(const vector<double>& inductancias) {
    validarValores(inductancias);
    double suma = 0.0;

    for (const auto& inductancia : inductancias) {
        suma += 1.0/inductancia;
    }
    return 1.0/suma;
} 