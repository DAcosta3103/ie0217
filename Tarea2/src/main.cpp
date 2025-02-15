#include "Tienda.hpp"

using namespace std;


/**
 * @brief Función principal que ejecuta el menú de la tienda virtual.
 * 
 * Esta función contiene un menú interactivo que permite al usuario realizar varias operaciones
 * relacionadas con la tienda, tales como agregar productos, registrar clientes, añadir productos
 * al carrito y procesar compras. 
 * 
 * @return 0
 */
int main() {
    Tienda tienda;  /*!< declaramos nuesta tienda >*/ 
    int opcion = 0;
    int id;
    double precio, peso, descuento;
    string nombre, nombreProducto;
    bool opcionValida;            
    Cliente* cliente = nullptr;
    Producto* producto = nullptr;
    
    

    do {
        cout << "\n¡Bienvenido al menú de la tienda virtual Fashion La Bajura!\n";
        cout << "1. Agregar producto\n";
        cout << "2. Registrar cliente\n";
        cout << "3. Agregar producto al carrito\n";
        cout << "4. Procesar compra\n";
        cout << "5. Salir\n";
        cout << "Por favor, elija una opción para continuar.\n";
        cin >> opcion;

        /*!< se atiende cada caso con >*/ 
        switch (opcion) {
            
            case 1: 
                int tipoProducto;
                cout << "\nQué tipo de producto desea agregar?\n";
                cout << "1. Producto virtual\n";
                cout << "2. Producto físico\n";
                cout << "Por favor elija el número respectivo a la opción que desea.\n";
                cin >> tipoProducto;

                cout << "Ingrese el nombre del producto: ";
                cin >> nombre;

                cout << "Ingrese el precio del producto: ";
                cin >> precio;

                if (tipoProducto == 1) {
                    cout << "Ingrese el ID del producto: ";
                    cin >> id;
                    tienda.agregarProducto(new ProductoDigital(nombre, precio, id));
                    cout << "\nProducto agregado exitosamente." << endl;
                } else {
                    cout << "Ingrese el peso del producto: ";
                    cin >> peso;
                    tienda.agregarProducto(new ProductoFisico(nombre, precio, peso));
                    cout << "\nProducto agregado exitosamente." << endl;
                }

                opcionValida = true;
                break;
            
                
            case 2:
                    int tipoCliente;
                    cout << "\nQué tipo de cliente desea agregar?\n";
                    cout << "1. Cliente regular\n";
                    cout << "2. Cliente premium\n";
                    cout << "Por favor elija el número respectivo a la opción que desea.\n";
                    cin >> tipoCliente;

                    cout << "Ingrese el nombre del cliente: ";
                    cin >> nombre;

                    if (tipoCliente == 1) {
                        tienda.agregarCliente(new ClienteRegular(nombre));
                    } else {
                        cout << "\nIngrese el porcentaje de descuento que la tienda le otorga al cliente (0 < descuento < 1. Ejemplo: 0.5 para 50%): ";
                        cin >> descuento;
                        tienda.agregarCliente(new ClientePremium(nombre, descuento));
                    }
                    cout << "\nCliente agregado exitósamente." << endl;
                    opcionValida = true;
                    break;
               

            case 3:


                cout << "\nIngrese el nombre del cliente dueño del carrito al cual desea añadir un producto: ";
                cin >> nombre;

                /*!< loop para recorrer el vector de clientes y buscar el cliente elegido >*/ 
                for (Cliente* clnt: tienda.clientes) {
                    if (clnt->getNombre() == nombre) {
                        cliente = clnt;
                        break;
                    } 
                }
                
                if (!cliente) {
                    cout << "El cliente no se pudo encontrar en la base de datos." << endl;
                } else {
                    cout << "\nIngrese el nombre del producto que desea añadir al carrito: ";
                    cin >> nombreProducto;

                    /*!< loop para recorrer el vector de productos disponibles y añadir nuevos >*/ 
                    for (Producto* prdct: tienda.productosDisponibles) {
                        if (prdct->getNombre() == nombreProducto) {         
                            producto = prdct;
                            cliente->agregarProducto(producto);
                            cout << "El producto ha sido agregado exitósamente." << endl;
                            break;
                        }
                    } 
                } 
                    

                

                opcionValida = true;
                break;

            case 4:
                cout << "\nIngrese el nombre del cliente cuyo carrito quiere procesar para compra: ";
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

    } while (!opcionValida || opcion != 5);  /*!< se asegura que el menú termina hasta que se seleccione la opción de salir >*/ 
 
}