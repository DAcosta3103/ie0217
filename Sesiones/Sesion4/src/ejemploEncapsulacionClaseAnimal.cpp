#include <iostream>

using namespace std;

    class Animal {
       // Los atributos públicos se pueden accesar desde dónde sea y por quién sea 
        public:
            void setEdad(int age) {
                edad = age;
            }
            int getEdad() {
                return edad;
            }

        // Los atributos protegidos no se pueden accesar desde fuera de esta clase o una clase derivada
        protected:
        string nombre;

        // Los atributos privados solo se pueden accesar desde esta misma clase
        private:
        int edad;
    };


class Perro : public Animal {
// Para crear esta clase (Perro), heredo/derivo de la clase Animal

    public:
        void setNombre(string n) { 
            nombre = n;
        }
        string getNombre() {
            return nombre;
        }
};

int main() {
    Perro miPerro;      // 'miPerro' es una variable de clase Perro
    miPerro.setNombre("Toby");  // Podemos usar las funciones encargadas de nombres debido a que miPerro viene de una clase derivada a Animal
    miPerro.setEdad(3);

    cout << "Mi perro se llama " << miPerro.getNombre();        // 'nombre' es una variable protegida de la clase Animal
    cout << " y tiene " << miPerro.getEdad() <<  " anios." << endl;
}