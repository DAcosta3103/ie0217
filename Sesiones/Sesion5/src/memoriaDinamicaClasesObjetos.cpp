#include <iostream> 
using namespace std;

class Student { 

    private: 
        int age;

    public:

    // constructor initializes age to 12 
    Student(): age(12) {}
    void getAge() {
    cout << "Age = " << age << endl;
    }
};

int main() {

    // dynamically declare Student object 
    // cabe destacar que 'new' nos devuelve la dirección de memoria del objeto
    Student* ptr = new Student();

    // call getAge() function 
    ptr->getAge();

    // ptr memory is released
    delete ptr;

    return 0;
}