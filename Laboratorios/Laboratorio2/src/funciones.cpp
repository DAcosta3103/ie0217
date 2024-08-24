#include <iostream>
#include <cstring>
#include "funciones.hpp"

using namespace std;

/**
 * @brief Agrega un nuevo libro a la colección.
 *
 * Esta función permite al usuario ingresar los detalles de un nuevo libro
 * (título, autor, ISBN y año de publicación) y lo almacena en el array de libros.
 *
 * @param libros            Array de estructuras Libro donde se almacenan los libros.
 * @param cantidadLibros    Referencia a un entero que indica la cantidad actual de libros en la colección.
 *                          Este valor se incrementará en uno después de agregar un nuevo libro.
 *
 * @return void
 */




void agregarLibro(Libro libros[], int &cantidadLibros) {
    cout << "Ingrese el titulo del libro: ";
    cin.ignore();
    cin.getline(libros[cantidadLibros].titulo, 100);

    cout << "Ingrese el autor del libro: ";
    cin.getline(libros[cantidadLibros].autor, 100);

    cout << "Ingrese el ISBN del libro: ";
    cin.getline(libros[cantidadLibros].ISBN, 13);

    cout << "Ingrese el año de publicacion del libro: ";
    cin >> libros[cantidadLibros].anioPublicacion;

    cantidadLibros++;
}

void mostrarLibros(Libro libros[], int cantidadLibros) {
    if(cantidadLibros == 0){
        cout << "No hay libros en la lista." << endl;
    } else {
        for (int i = 0; i < cantidadLibros; i++) {
            cout << i + 1 << "." << libros[i].titulo << " por " << libros[i].autor << " (ISBN: " << libros[i].ISBN << ", Año: " << libros[i].anioPublicacion << ")" << endl;
        }

    }

}

void buscarLibroPorTitulo(Libro libros[], int cantidadLibros) {
    char titulo[100];
    cout << "Ingrese el titulo del libro que sea buscar: ";
    cin.ignore();
    cin.getline(titulo, 100);

    bool encontrado = false;

    for (int i = 0; i < cantidadLibros; i++) {
        

        // Si los dos strings que le doy son iguales: la funcion retorna 0; si la primera es distinta como mayor o menor: retorna un numero distinto a 0
        if (strcmp(libros[i].titulo, titulo) == 0) {            // La funcion string compare compara el titulo y recibe lo que le acabamos de pedir al usuario que ingrese
            cout << "Libro encontrado: " << libros[i].titulo << " por " << libros[i].autor << endl;
            encontrado = true;
            break;
        }             

    }

    if (!encontrado) {
        cout << "El libro no ha sido encontrado." << endl;
    }

}

void buscarLibroPorISBN(Libro libros[], int cantidadLibros) {
    char ISBN[13];
    cout << "Ingrese el ISBN del libro que desea buscar: ";
    cin.ignore();
    cin.getline(ISBN, 13);
    bool encontrado = false;
    for (int i = 0; i < cantidadLibros; i++) {
        if (strcmp(libros[i].ISBN, ISBN) == 0) {
            cout << "Libro encontrado: " << libros[i].titulo << " por " << libros[i].autor << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Libro no encontrado." << endl;
    }
}

void eliminarLibros(Libro libros[], int &cantidadLibros) {
    char ISBN[13];
    cout << "ingrese el ISBN del libro que desea eliminar: ";
    cin.ignore();
    cin.getline(ISBN, 13);

    for (int i = 0; i < cantidadLibros; i++) {
        if (strcmp(libros[i].ISBN, ISBN) == 0) {
            for (int j = i; j < cantidadLibros - 1; j++) {
                libros[j] = libros[j + 1];
            } 
            cantidadLibros--;
            cout << "Libro eliminado." << endl;
            return;             // El return significa que hasta ahi llego la funcion. Con el return se sale totalmente de la funcion 'eliminarLibros'
        }
    }
    cout << "Libro no econtrado." << endl;
}