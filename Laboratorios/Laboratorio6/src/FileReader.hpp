#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

class FileNotFoundException : public std::runtime_error {
public:
    explicit FileNotFoundException(const std::string& message)
        : std::runtime_error(message) {}
};

template <typename Container>
class FileReader {
public:
    FileReader(const std::string& filePath) : filePath(filePath) {}

    void readFile(Container& container) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw FileNotFoundException("Error: No se pudo abrir el archivo " + filePath);
        }

        std::string line;
        while (std::getline(file, line)) {
            container.push_back(line);
        }

        file.close();
    }

private:
    std::string filePath;
};

#endif // FILEREADER_HPP
