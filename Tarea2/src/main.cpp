#include "Tienda.hpp"

using namespace std;

int main() {
    Tienda tienda;  // declaramos nuesta tienda
    int opcion = 0;
    int id;
    double precio, peso, descuento;
    string nombre, nombreProducto;
    bool opcionValida;

    
    // a continuación se escribe el menú principal 

    do {
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
            
                Cliente* cliente = nullptr;
                Producto* producto = nullptr;

                cout << "\nIngrese el nombre del cliente dueño del carrito al cual desea añadir un producto: ";
                cin >> nombre;

                // loop para recorrer el vector de clientes y buscar el cliente elegido
                for (Cliente* clnt: tienda.clientes) {
                    if (clnt->getNombre() == nombre) {
                        cliente = clnt;
                        break;
                    } 
                }

                if (cliente) {
                    cout << "\nIngrese el nombre del producto que desea añadir al carrito: ";
                    cin >> nombreProducto;

                    // loop para recorrer el vector de productos disponibles y buscar el producto por añadir
                    for (Producto* prdct: tienda.productosDisponibles) {
                        if (prdct->getNombre() == nombreProducto) {
                            producto = prdct;
                            cliente->agregarProducto(producto);
                            cout << "El producto ha sido agregado exitósamente." << endl;
                            break;
                        }
                    } 
                } else {
                        cout << "El cliente no se pudo encontrar en la base de datos." << endl;
                }

                if (!producto) { cout << "El producto no se pudo encontrar en la base de datos." << endl; }

                opcionValida = true;
                break;

            case 4:
                cout << "Ingrese el nombre del cliente cuyo carrito quiere procesar para compra: ";
                cin >> nombre;

                tienda.procesarCompra(nombre);
                opcionValida = true;
                break;

            case 5:
                cout << "Saliendo del menú..." << endl;
                break;



            default: 
                cout << "\nOpción no válida. Intente de nuevo." << endl;
                opcionValida = false;
                break;
        }

    } while (!opcionValida || opcion != 5);  

}