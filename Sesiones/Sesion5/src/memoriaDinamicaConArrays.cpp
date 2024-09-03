#include <iostream> 

using namespace std;

int main() {

    
    int num;
    cout<<"Enter total number of students: ";
    cin >> num; 
    float* ptr;
    
    // memory allocation of num number of floats 
    ptr = new float[num];       // Asigno el puntero de manera dinámica a un arreglo de flotantes de tamaño num

    cout<<"Enter GPA of students." << endl;
    for (int i = 0; i < num; ++i) {
        cout<<"Student" << i + 1 << ": ";
        cin >> *(ptr + i);
    }

    cout << "\nDisplaying GPA of students." << endl;
    for (int i = 0; i < num; ++i) {
        cout << "Student" << i + 1 << ": " << *(ptr + i) << endl;
    }
  
    // ptr memory is released
    delete[] ptr;

    return 0;

}