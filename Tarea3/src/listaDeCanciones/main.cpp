#include "lista.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {

    ListaEnlazada lista;
    lista.inicializar();
    int opcion;

    do {
        cout << "\nMenu Principal:\n";
        cout << "1. Insertar una nueva canción al inicio\n";
        cout << "2. Insertar una nueva canción al final\n";
        cout << "3. Insertar una nueva canción en una posición que elija\n";
        cout << "4. Eliminar una canción\n";
        cout << "5. Modificar los datos de una canción\n";
        cout << "6. Imprimir la lista de canciones\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        // declaramos las variables usadas para parámetros
        string nombre, artista;
        double duracion;
        int posicion;

        switch(opcion) {
            case 1:
                cout << "Ingrese el nombre de la canción: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el nombre del artista: ";
                getline(cin, artista);
                cout << "Ingrese la duración de la canción: ";
                cin >> duracion;
                lista.insertarInicio(Cancion(nombre, artista, duracion));
                break;
            case 2:
                cout << "Ingrese el nombre de la canción: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el nombre del artista: ";
                getline(cin, artista);
                cout << "Ingrese la duración de la canción: ";
                cin >> duracion;
                lista.insertarFinal(Cancion(nombre, artista, duracion));
                break;
            case 3:
                cout << "Ingrese el nombre de la canción: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el nombre del artista: ";
                getline(cin, artista);
                cout << "Ingrese la duración de la canción: ";
                cin >> duracion;
                cout << "Ingrese la posición para insertar: ";
                cin >> posicion;
                lista.insertarPosicion(Cancion(nombre, artista, duracion), posicion);
                break;
            case 4:
                cout << "Ingrese el nombre de la canción a eliminar: ";
                cin.ignore();
                getline(cin, nombre);
                lista.eliminarCancion(nombre);
                break;
            case 5:
                cout << "Ingrese el nombre de la canción a modificar: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el nuevo nombre de la canción: ";
                getline(cin, nombre);
                cout << "Ingrese el nombre del nuevo artista: ";
                getline(cin, artista);
                cout << "Ingrese la nueva duración de la canción: ";
                cin >> duracion;
                lista.modificarCancion(nombre, Cancion(nombre, artista, duracion));
                break;
            case 6:
                lista.imprimirLista();
                break;
            case 7:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 7);


    return 0;
}

