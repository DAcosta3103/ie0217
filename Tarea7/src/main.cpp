#include "inventario.hpp"
#include "calculos.hpp"
#include <iostream>

using namespace std;

int main() {
    Inventario inventario;  // Instancia para manejar el inventario de componentes.
    int opcion = 0;

    do {
        // Mostrar opciones del menú
        cout << "\n¡Bienvenido al sistema de gestión de inventario y cálculo de circuitos!\n";
        cout << "1. Agregar componente al inventario\n";
        cout << "2. Reducir cantidad de un componente\n";
        cout << "3. Listar componentes del inventario\n";
        cout << "4. Buscar un componente por nombre\n";
        cout << "5. Realizar cálculos de circuitos\n";
        cout << "6. Salir\n";
        cout << "Por favor, elija una opción para continuar: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre, categoria, descripcion;
                int cantidad;

                cout << "\nIngrese el nombre del componente: ";
                cin.ignore();  // Limpiar el buffer
                getline(cin, nombre);

                cout << "Ingrese la categoría del componente (Resistencia, Capacitor, Inductor): ";
                getline(cin, categoria);

                cout << "Ingrese la cantidad disponible: ";
                cin >> cantidad;

                cout << "Ingrese una descripción del componente: ";
                cin.ignore();  // Limpiar el buffer
                getline(cin, descripcion);

                try {
                    inventario.agregarComponente(nombre, categoria, cantidad, descripcion);
                    cout << "Componente agregado exitosamente.\n";
                } catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }

            case 2: {
                string nombre;
                int cantidad;

                cout << "\nIngrese el nombre del componente que desea reducir: ";
                cin.ignore();
                getline(cin, nombre);

                cout << "Ingrese la cantidad a reducir: ";
                cin >> cantidad;

                try {
                    inventario.reducirComponente(nombre, cantidad);
                    cout << "Cantidad reducida exitosamente.\n";
                } catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }

            case 3:
                cout << "\nComponentes en el inventario:\n";
                inventario.listarComponentes();
                break;

            case 4: {
                string nombre;

                cout << "\nIngrese el nombre del componente que desea buscar: ";
                cin.ignore();
                getline(cin, nombre);

                inventario.buscarComponente(nombre);
                break;
            }

            case 5: {
                int opcionCalculo;
                vector<double> valores;

                cout << "\nSeleccione el tipo de cálculo:\n";
                cout << "1. Resistencia en serie\n";
                cout << "2. Resistencia en paralelo\n";
                cout << "3. Capacitancia en serie\n";
                cout << "4. Capacitancia en paralelo\n";
                cout << "5. Inductancia en serie\n";
                cout << "6. Inductancia en paralelo\n";
                cin >> opcionCalculo;

                cout << "Ingrese los valores separados por espacio (finalice con 0):\n";
                double valor;
                while (cin >> valor && valor != 0) {
                    valores.push_back(valor);
                }

                try {
                    double resultado = 0.0;

                    switch (opcionCalculo) {
                        case 1:
                            resultado = Calculos::resistenciaSerie(valores);
                            break;
                        case 2:
                            resultado = Calculos::resistenciaParalelo(valores);
                            break;
                        case 3:
                            resultado = Calculos::capacitanciaSerie(valores);
                            break;
                        case 4:
                            resultado = Calculos::capacitanciaParalelo(valores);
                            break;
                        case 5:
                            resultado = Calculos::inductanciaSerie(valores);
                            break;
                        case 6:
                            resultado = Calculos::inductanciaParalelo(valores);
                            break;
                        default:
                            cerr << "Opción no válida.\n";
                            continue;
                    }

                    cout << "El resultado del cálculo es: " << resultado << endl;
                } catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }

            case 6:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "\nOpción no válida. Intente de nuevo.\n";
                break;
        }

    } while (opcion != 6);

    return 0;
}
