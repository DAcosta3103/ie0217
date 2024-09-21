#ifndef TEXTPROCESSOR_HPP
#define TEXTPROCESSOR_HPP

#include <functional>

template <typename Container, typename Func>
void processText(Container& container, Func processFunc) {
    for (auto& element : container) {
        processFunc(element);
    }
}

#endif // TEXTPROCESSOR_HPP
