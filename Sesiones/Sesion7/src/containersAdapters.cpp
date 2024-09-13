#include <iostream>
#include <stack>
using namespace std;

/*
Se muestra el uso de la biblioteca 'stack' para crear una pila, que funciona con politica LIFO con push y pop
*/
int main() {
    // create a stack of ints
    stack<int> numbers;

    // push into stack
    numbers.push(1);
    numbers.push(100);
    numbers.push(10);

    cout << "Numbers are: ";

    // we can access the element by getting the top and popping
    // until the stack is empty
    while (!numbers.empty()) {
        // print top element
        cout << numbers.top() << ", ";

        // pop top element from stack
        numbers.pop();
    }

    return 0;
}
