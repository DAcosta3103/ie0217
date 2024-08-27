#include <iostream>
#include <fstream>

class Archivo {
    private:
        std::fstream archivo;
    
    public:
        Archivo(std::string nombre_archivo){
            archivo.open(nombre_archivo, std::ios::in | std::ios::out | std::ios::app);
            if(!archivo.is_open()) {
                std::cot << "No se puede abrir el archivo " << nombre_archivo << std::endl;
            }
        }

        // En este código, la función del destructor es cerrar el archivo una vez este ya no esté abierto, de esta manera limpiando y liberando recursos

        ~Archivo() {
            if (archivo.is_open()){
                archivo.close
            }
        }
};

int main() {
    Archivo mi_archivo("datos.txt");

    // hacer algo con el archivo

    return 0;
}