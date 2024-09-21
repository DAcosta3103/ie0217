#include <iostream>
#include "FileReader.hpp"
#include "TextProcessor.hpp"
#include "RegexUtils.hpp"
#include "Exceptions.hpp"

using namespace std;

/**
 * @brief Función main
 * 
 * @param argc Representa el numero de argumentos pasados en la linea de comandos 
 * @param argv Un arreglo que contiene los argumentos pasados en la linea de comandos
 * @return 0
 */
int main(int argc, char* argv[]) {

    // se verifica que se pasó más de un solo argumento
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <archivo_texto>" << endl;   // mensaje de error para el caso contrario
        return 1;
    }

     // se guarda la ruta del archivo pasado como argumento.
    string filePath = argv[1];
    vector<string> lines;    // contenedor para almacenar las líneas leídas del archivo.

    // se comienzan a manejar excepciones
    try {
        // creamos un objeto FileReader que leerá el archivo y almacenará las líneas en el vector "lines".
        FileReader<vector<string>> fileReader(filePath);
        fileReader.readFile(lines);
        
        cout << "Archivo leído correctamente. Total de líneas: " << lines.size() << endl;   // se imprime en terminal el total de líneas leídas

        // Procesar el texto utilizando una lambda que cuenta las líneas
        int lineCount = 0;
        processText(lines, [&](const string& line) {
            if (!line.empty()) {
                lineCount++;
            }
        });
        cout << "Líneas no vacías: " << lineCount << endl;  // se imprime en pantalla la cantidad de líneas no vacías

        // Buscar un patrón con expresiones regulares
        string pattern = "\\d+";  // Busca cualquier número en las líneas
        vector<string> matchedLines = regexSearch(lines, pattern);
        cout << "Líneas que contienen números: " << matchedLines.size() << endl;

        // Reemplazar los números con una etiqueta
        regexReplace(lines, pattern, "[Número]");
        cout << "Números reemplazados en las líneas." << endl;

    // se captura la excepción de si el archivo no fue encontrado
    } catch (const FileNotFoundException& e) {
        cerr << e.what() << endl;
        return 1;
    // se captura la excepción de tipo regex
    } catch (const RegexException& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
