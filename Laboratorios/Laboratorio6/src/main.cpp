#include <iostream>
#include "FileReader.hpp"
#include "TextProcessor.hpp"
#include "RegexUtils.hpp"
#include "Exceptions.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <archivo_texto>" << endl;
        return 1;
    }

    string filePath = argv[1];
    vector<string> lines;

    try {
        FileReader<vector<string>> fileReader(filePath);
        fileReader.readFile(lines);
        
        cout << "Archivo leído correctamente. Total de líneas: " << lines.size() << endl;

        // Procesar el texto utilizando una lambda que cuenta las líneas
        int lineCount = 0;
        processText(lines, [&](const string& line) {
            if (!line.empty()) {
                lineCount++;
            }
        });
        cout << "Líneas no vacías: " << lineCount << endl;

        // Buscar un patrón con expresiones regulares
        string pattern = "\\d+";  // Busca cualquier número en las líneas
        vector<string> matchedLines = regexSearch(lines, pattern);
        cout << "Líneas que contienen números: " << matchedLines.size() << endl;

        // Reemplazar los números con una etiqueta
        regexReplace(lines, pattern, "[Número]");
        cout << "Números reemplazados en las líneas." << endl;

    } catch (const FileNotFoundException& e) {
        cerr << e.what() << endl;
        return 1;
    } catch (const RegexException& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
