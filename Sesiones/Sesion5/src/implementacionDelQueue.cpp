// Queue implementation in C++
#include <iostream>
#define SIZE 5

using namespace std;

class Queue {
    private:
        int items[SIZE], front, rear;
    public:
        Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if (front == 0 && rear == SIZE - 1) {
            return true;
        }
        return false;
    }
    
    bool isEmpty() {
        if (front == -1)
            return true;
        else
            return false;
    }

void enQueue(int element) {
    if (isFull()) {
    cout << "Queue is full";
    } else {
    if (front == -1) front = 0;
    rear++;
    items[rear] = element;  
    cout << endl << "Inserted " << element << endl;
}
}

int deQueue() {
    int element;
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return (-1);
    } else {
        element = items[front];
        if (front >= rear) {
            front = -1;
            rear = -1;
        }   /* Q solo tiene un elemento, por lo que podemos resetear la queue luego de borrarla */
        else {
            front++;
        }
        cout << endl << "Deleted -> " << element << endl;
        return (element);
    }
}
    
void display() {
    /* funcion para imrimir en pantalla los elmentos del queue*/
    int i;
    if(isEmpty()) {
        cout << endl << "Empty Queue" << endl;
    } else {
        cout << endl << "Front index -> " << front << endl;
        cout << endl << "Items -> ";
        for (i = front; i <= rear; i++)
            cout << items[i] << " ";
            cout << endl << "Rear index -> " << rear << endl;

        }
    }
};

int main() {
    Queue q;

    //deQueue no es posible con una queue vacia
    q.deQueue();

    //enQueue 5 elementos
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    // secto elemento no se puede añadir porque queue esta llena
    q.enQueue(6);

    q.display();

    //deQueue remueve el primer elemento entrado, siguiento la politica de reemplazo FIFO (First In First Out)
    q.deQueue();

    // quedamos con solo 4 elementos restantes
    q.display();

}
