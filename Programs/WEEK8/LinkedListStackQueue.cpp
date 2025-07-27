#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() : top(nullptr) {}

    // Push an element onto the stack
    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        cout << data << " pushed onto stack." << endl;
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1; // Indicate error
        }
        Node* temp = top;
        int poppedData = top->data;
        top = top->next;
        delete temp;
        return poppedData;
    }

    // Peek at the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1; // Indicate error
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Print the stack
    void print() {
        Node* temp = top;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Queue class
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue an element at the rear of the queue
    void enqueue(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        if (rear == nullptr) {
            front = rear = newNode;
            cout << data << " enqueued to queue." << endl;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        cout << data << " enqueued to queue." << endl;
    }

    // Dequeue an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicate error
        }
        Node* temp = front;
        int dequeuedData = front->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr; // If the queue is empty after dequeue
        }
        delete temp;
        return dequeuedData;
    }

    // Peek at the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Indicate error
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Print the queue
    void print() {
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function to test Stack and Queue
int main() {
    Stack s;
    Queue q;

    // Stack Operations
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    cout << "Top element is: " << s.peek() << endl;
    cout << "Popped element is: " << s.pop() << endl;
    s.print();
    cout<<"-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-"<<endl;
    // Queue Operations
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();
    cout << "Front element is: " << q.peek() << endl;
    cout << "Dequeued element is: " << q.dequeue() << endl;
    q.print();

    return 0;
}
