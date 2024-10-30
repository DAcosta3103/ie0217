#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;


int contador = 0;

void incrementar() {
    for (int i = 0; i < 10000; i++) {
       lock_guard<mutex> lock(mtx);
       contador++;
    }
}

int main() {
    thread hilo1(incrementar);
    thread hilo2(incrementar);

    hilo1.join();
    hilo2.join();

    cout << "Valor final del contador: " << contador << endl;
    return 0;
}
