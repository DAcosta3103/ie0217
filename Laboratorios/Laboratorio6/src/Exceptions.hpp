#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>



/**
 * @brief Clase ReadException, clase derivada de runtime_error
 * 
 */
class ReadException : public std::runtime_error {
    public:
        /**
         * @brief Construtor para la clase Read Exception
         * 
         * @param message Mensaje de error desplegado para la excepción de lectura
         */
        explicit ReadException(const std::string& message)
            : std::runtime_error(message) {}
};



#endif // EXCEPTIONS_HPP
