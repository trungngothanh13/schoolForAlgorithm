#include <iostream>
using namespace std;

// Stack class
class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        arr = new int[size];
        top = -1;
        capacity = size;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    // Peek the top element
    int Top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Print the stack
    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Queue class
class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;

public:
    // Constructor
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Enqueue an element into the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    // Dequeue an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    // Peek the front element
    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Peek the rear element
    int Rear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Print the queue
    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.printStack();

    cout << "Top element: " << stack.Top() << endl;

    stack.pop();
    cout << "After popping, stack: ";
    stack.printStack();

    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.printQueue();

    cout << "Front element: " << queue.Front() << endl;
    cout << "Rear element: " << queue.Rear() << endl;

    queue.dequeue();
    cout << "After dequeue, queue: ";
    queue.printQueue();

    return 0;
}