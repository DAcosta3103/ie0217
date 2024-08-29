#ifndef CONVERSOR_DE_UNIDADES_H_
#define CONVERSOR_DE_UNIDADES_H_

#include <string>
using namespace std;

// Enumeraciones para las opciones de unidades
enum struct OpcionesLongitud {
    metro = 1,
    kilometro,
    milimetro,
    centimetro,
    milla,
    pie,
    pulgada
};

enum struct OpcionesPeso {
    gramo = 1,
    kilogramo,
    miligramo,
    libra,
    tonelada,
    onza
};

enum struct OpcionesTemperatura {
    celsius = 1,
    fahrenheit,
    kelvin
};

// Funciones para convertir opciones a strings
string unidadString(OpcionesLongitud op); 
string unidadString(OpcionesPeso op); 
string unidadString(OpcionesTemperatura op); 

// Funciones para ejecutar las conversiones
void convertirUnidadesLongitud(); 
void convertirUnidadesPeso(); 
void convertirUnidadesTemperatura();

// Función para mostrar el menú principal
void menuPrincipal();

#endif // CONVERSOR_DE_UNIDADES_H_