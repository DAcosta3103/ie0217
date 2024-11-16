#ifndef CALCULOS_HPP
#define CALCULOS_HPP

#include <vector>
#include <stdexcept>
#include <numeric> // Para accumulate
#include <cmath>   // Para pow

using namespace std;

class Calculos {
    public:
        static double resistenciaSerie(const vector<double>& resistencias);
        static double resistenciaParalelo(const vector<double>& resistencias);  

        static double capacitanciaSerie(const vector<double>& capacitancias);
        static double capacitanciaParalelo(const vector<double>& capacitancias);  

        static double inductanciaSerie(const vector<double>& inductancias);
        static double inductanciaParalelo(const vector<double>& inductancias);  

        static void validarValores(const vector<double>& valores);

        
        static double capacitanciaEquivalenteSerieParalelo(const vector<double>& serie, const vector<double>& paralelo);
};

#endif // CALCULOS_HPP