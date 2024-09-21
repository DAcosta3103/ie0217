#ifndef TEXTPROCESSOR_HPP
#define TEXTPROCESSOR_HPP

#include <functional>

/**
 * @brief Plantilla de función `processText` que puede procesar un contenedor de elementos de cualquier tipo.
 * 
 * @tparam Container 
 * @tparam Func 
 * @param container Un contenedor (para este caso será un vector) que contiene los elementos a procesar.
 * @param processFunc Una función que se aplicará a cada elemento del contenedor.
 */
template <typename Container, typename Func>
void processText(Container& container, Func processFunc) {

    // se recorre cada elemento del contenedor
    for (auto& element : container) {
        processFunc(element);   // se aplica processFunc al elemento actual
    }
}

#endif // TEXTPROCESSOR_HPP
