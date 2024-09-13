#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> languages = {"Python", "C++", "Java"};

    // create an iterator to a string vector
    vector<string>::iterator itr;

    // iterate over all elements
    for (itr = languages.begin(); itr != languages.end(); itr++) {
        cout << *itr << ", ";       // ya que iterador (itr) es un puntero, podemos dereferenciarlo para obtener el valor en esa dirección de memoria
    }

    return 0;
}