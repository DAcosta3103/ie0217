#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class DataProcessor {
public:
    DataProcessor(int size) : size(size), data(nullptr) {
        if (size > 0) {
            data = new int[size];
        } else {
            std::cout << "Error: invalid size\n";
        }
    }

    ~DataProcessor() {
        if (data != nullptr) {
            delete[] data;
        }
    }

    void populateData() {
        for (int i = 0; i < size; ++i) {        // se cambia el límite del for para que no ocurran problemas en memoria
            data[i] = i * 10;
        }
    }

    int calculateSum() {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += data[i];
        }
        return sum;
    }

    double calculateAverage() {
        if (size == 0) return 0.0;      // se evita la división entre cero
        return static_cast<double>(calculateSum()) / size; 
    }

    void concurrentProcess() {
        std::thread t1(&DataProcessor::processData, this);
        std::thread t2(&DataProcessor::processData, this);

        t1.join();
        t2.join();
    }

    void printData() {
        for (int i = 0; i < size; i++) {
            std::cout << "Data[" << i << "] = " << data[i] << std::endl;
        }
    }

private:
    int* data;
    int size;
    std::mutex mtx;

    void processData() {
        for (int i = 0; i < size; ++i) {
            std::lock_guard<std::mutex> lock(mtx);      // se añade un mutex para evitar condiciones de carrera
            data[i] *= 2;
        }
    }
};

int main() {
    int size;
    std::cout << "Enter size of data: ";
    std::cin >> size;

    auto processor = std::make_unique<DataProcessor>(size);  // usa std::unique_ptr

    processor->populateData();
    processor->concurrentProcess();
    std::cout << "Average: " << processor->calculateAverage() << std::endl;

    
    return 0;
}
