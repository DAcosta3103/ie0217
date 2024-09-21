#ifndef REGEXUTILS_HPP
#define REGEXUTILS_HPP

#include <regex>
#include <string>
#include <vector>
#include <stdexcept>

/**
 * @brief Clase RegexException, derivada de runtime_error
 * 
 */
class RegexException : public std::runtime_error {
public:
    explicit RegexException(const std::string& message)
        : std::runtime_error(message) {}
};

/**
 * @brief Función que busca un patrón de expresión regular en cada línea de un vector de strings
 * 
 * @param lines Las líneas del archivo de texto
 * @param pattern El patrón de la expresión regular
 * @return std::vector<std::string> Vector de tipo string con las "coincidencias"
 */
std::vector<std::string> regexSearch(const std::vector<std::string>& lines, const std::string& pattern) {
    std::vector<std::string> matches;       // vector para las lineas que coinciden
    std::regex regexPattern;                // regex para almacenar el patrón

    try {
        // se intenta compilar el patrón de la expresión regular
        regexPattern = std::regex(pattern);
    } catch (const std::regex_error&) {
        throw RegexException("Error: Patrón de expresión regular inválido.");   // se maneja la excepción de regex
    }

    // se recorre el vector
    for (const auto& line : lines) {
        // si coincide, se guarda en el vector 'matches'
        if (std::regex_search(line, regexPattern)) {
            matches.push_back(line);
        }
    }

    return matches;
}

/**
 * @brief Función que reemplaza todas las coincidencias de un patrón de expresión regular por un texto de reemplazo en un vector de strings
 * 
 * @param lines Líneas del archivo de texto
 * @param pattern  El patrón de la expresión regular
 * @param replacement El string de reemplazo
 */
void regexReplace(std::vector<std::string>& lines, const std::string& pattern, const std::string& replacement) {
    std::regex regexPattern;

    try {
        regexPattern = std::regex(pattern);
    } catch (const std::regex_error&) {
        throw RegexException("Error: Patrón de expresión regular inválido.");
    }

    // se recorre el vector "lines" para reemplazar
    for (auto& line : lines) {
        line = std::regex_replace(line, regexPattern, replacement);
    }
}

#endif // REGEXUTILS_HPP
