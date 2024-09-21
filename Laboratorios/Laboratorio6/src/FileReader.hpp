#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

/**
 * @brief Clase FileNotFoundException, la cual es derivada de runtime_error
 * 
 * Esta excepción se lanzará si ocurre un problema al abrir un archivo.
 * 
 */
class FileNotFoundException : public std::runtime_error {
public:
    /**
     * @brief Construtor para la clase File Not Found Exception
     * 
     * @param message Mensaje a imprimir cuando suceda el error
     */
    explicit FileNotFoundException(const std::string& message)
        : std::runtime_error(message) {}
};

/**
 * @brief Plantilla de clase FileReader
 * 
 * Esta clase se encarga de leer archivos y almacenar las líneas del archivo en el contenedor proporcionado.
 * @tparam Container 
 */
template <typename Container>
class FileReader {
public:
    /**
     * @brief Construtor para la clase File Reader
     * 
     * @param filePath Ruta del archivo que se desea leer
     */
    FileReader(const std::string& filePath) : filePath(filePath) {}

    /**
     * @brief Función para leer los archivos y almacenarlos en container
     * 
     * @param container Contenedor donde se almacenará lo leído
     */
    void readFile(Container& container) {
        // Creamos un objeto ifstream para abrir el archivo en modo lectura.
        std::ifstream file(filePath);

        // Si el archivo no se pudo abrir, lanzamos una excepción FileNotFoundException con un mensaje de error.
        if (!file.is_open()) {
            throw FileNotFoundException("Error: No se pudo abrir el archivo " + filePath);
        }


        std::string line;         // Variable para almacenar cada línea leída del archivo.

        // Con el bucle leemos linea por linea y almacenamos de la misma manera
        while (std::getline(file, line)) {
            container.push_back(line);
        }

        file.close();
    }

private:
    std::string filePath;        // Variable que almacena la ruta del archivo que se va a leer.
};

#endif // FILEREADER_HPP
