#ifndef CALCULOS_HPP
#define CALCULOS_HPP

#include <vector>
#include <stdexcept>
#include <numeric> // Para accumulate
#include <cmath>   // Para pow

using namespace std;

class Calculos {
    public:
        static double resistenciaSerie(const vector<double>& resitencias);
        static double resistenciaParalelo(const vector<double>& resitencias);  

        static double capacitanciaSerie(const vector<double>& capacitancias);
        static double capacitanciaParalelo(const vector<double>& capacitancias);  

        static double inductanciaSerie(const vector<double>& inductancias);
        static double inductanciaParalelo(const vector<double>& inductancias);  

        static void validarValores(const vector<double>& valores);
};

#endif // CALCULOS_HPP