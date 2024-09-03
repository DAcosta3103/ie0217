#include <iostream>
#include <stdlib.h>


using namespace std;

#define MAX 10

int stack_size = 0;  // Renombrar la variable global

// Creating a stack
struct stack {
    int items[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s) {
    s->top = -1;
}

// Check if the stack is full
int isfull(st *s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isempty(st *s) {
    return s->top == -1;
}

// Add elements into stack
void push(st *s, int newitem) {
    if (isfull(s)) {
        cout << "STACK FULL";
    } else {
        s->top++;
        s->items[s->top] = newitem;
        stack_size++;  // Actualiza stack_size
    }
}

// Remove element from stack
void pop(st *s) {
    if (isempty(s)) {
        cout << "\nSTACK EMPTY\n";
    } else {
        cout << "Item popped = " << s->items[s->top] << endl;
        s->top--;
        stack_size--;  // Actualiza stack_size
    }
}

// Print elements of stack
void printStack(st *s) {
    cout << "Stack: ";
    for (int i = 0; i < stack_size; i++) {  // Usa stack_size
        cout << s->items[i] << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    st *s = new st;

    createEmptyStack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    cout << "\nAfter popping out\n";
    printStack(s);

    delete s;

    return 0;
}
