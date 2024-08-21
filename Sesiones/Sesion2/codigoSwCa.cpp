#include <iostream>

int main () {
    std::cout << "Hola mundo!\n";

    int var1 = 1;
    int var2 = 2;
    int var3 = 2;

    switch (var1)
    {
    case 5:
        std::cout << "Case 1!\n";    
        break;
    case 2:
    case 3:
        std::cout << "Case Final!\n";
        break;

    
    default:
        std::cout << "Case default!\n";
        break;
    }


    return 0;
}