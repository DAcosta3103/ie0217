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
        for (int i = 0; i <= size; ++i) {
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
            data[i] *= 2;
        }
    }
};

int main() {
    int size;
    std::cout << "Enter size of data: ";
    std::cin >> size;

    DataProcessor* processor = new DataProcessor(size);

    processor->populateData();
    processor->concurrentProcess();
    std::cout << "Average: " << processor->calculateAverage() << std::endl;

    delete processor;
    return 0;
}
