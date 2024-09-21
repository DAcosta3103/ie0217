#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>



class ReadException : public std::runtime_error {
    public:
        explicit ReadException(const std::string& message)
            : std::runtime_error(message) {}
};



#endif // EXCEPTIONS_HPP
