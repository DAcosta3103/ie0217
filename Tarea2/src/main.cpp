#include "Tienda.hpp"

using namespace std;

int main() {
    Tienda tienda;  // declaramos nuesta tienda
    int opcion = 0;
    int id;
    double precio, peso, descuento;
    string nombre;
    bool opcionValida;

    
    // a continuación se escribe el menú principal 

    cout << "¡Bienvenido al menú de la tienda virtual Fashion La Bajura!\n";
    cout << "1. Agregar producto\n";
    cout << "2. Registrar cliente\n";
    cout << "3. Agregar producto al carrito\n";
    cout << "4. Procesar compra\n";
    cout << "5. Salir\n";
    cout << "Por favor, elija una opción para continuar.\n";
    cin >> opcion;


        switch (opcion) {
            case 1: 
                int tipoProducto;
                cout << "Qué tipo de producto desea agregar?\n";
                cout << "1. Producto físico\n";
                cout << "2. Producto virtual\n";
                cout << "Por favor elija el número respectivo a la opción que desea.\n";
                cin >> tipoProducto;

                cout << "Ingrese el nombre del producto: ";
                cin << nombre;

                cout << "Ingrese el precio del producto: ";
                cin << precio;

                if (tipoProducto == 1) {
                    cout << "Ingrese el ID del producto: ";
                    cin >> id;
                    tienda.agregarProducto(new ProductoDigital(nombre, precio, id));
                } else {
                    cout << "Ingrese el peso del producto: ";
                    cin >> peso;
                    tienda.agregarProducto(new ProductoFisico(nombre, precio, peso));
                }

                opcionValida = true;
                break;
                
            case 2:
                int tipoCliente;
                cout << "Qué tipo de cliente desea agregar?\n";
                cout << "1. Cliente regular\n";
                cout << "2. Cliente físico\n";
                cout << "Por favor elija el número respectivo a la opción que desea.\n";
                cin >> tipoCliente;

                cout << "Ingrese el nombre del cliente: ";
                cin << nombre;

                if (tipoCliente == 1) {
                    tienda.agregarCliente(new ClienteRegular(nombre));
                } else {
                    cout << "\nIngrese el porcentaje de descuento que la tienda le otorga al cliente (ejemplo: 50 para 50%, se aceptan decimales): ";
                    cin >> descuento;
                    tienda.agregarCliente(new ClientePremium(nombre, descuento));
                }

                opcionValida = true;
                break;

            case 3:
                cout << "\nIngrese el nombre del cliente dueño del carrito al que desea añadir un producto: ";
                cin >> nombre;
                


        } while (!opcionValida);  

}