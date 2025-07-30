#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int cursize, cap;
    int f, r;

public:
    // Constructor
    CircularQueue(int size) {
        cap = size;
        arr = new int[cap];
        f = 0;
        r = -1;
        cursize = 0; // Fix: Initialize cursize
    }

    // Function to check if the queue is empty
    bool empty() {
        return cursize == 0;
    }

    // Function to push an element into the circular queue
    void push(int data) {
        if (cursize == cap) { // Fix: Check if queue is full
            cout << "Circular Queue is full" << endl;
            return;
        }
        r = (r + 1) % cap; // Circular increment
        arr[r] = data;
        cursize++;
        cout << data << " enqueued" << endl;
    }

    // Function to pop an element from the circular queue
    void pop() {
        if (empty()) {
            cout << "Circular Queue is Empty" << endl;
            return;
        }
        cout << arr[f] << " dequeued" << endl; // Print removed element
        f = (f + 1) % cap; // Circular increment
        cursize--;
    }

    // Function to get the front element
    void front() {
        if (empty()) {
            cout << "Circular Queue is Empty" << endl;
            return;
        }
        cout << "THE FRONT OF CQUEUE IS: " << arr[f] << endl;
    }

    // Function to display the queue elements
    void display() {
        if (empty()) {
            cout << "Circular Queue is Empty" << endl;
            return;
        }
        cout << "Queue: ";
        
        for (int i=0;i<cap;i++) {
            cout << arr[i] << " ";
            i = (i + 1) % cap;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5); // Create a queue of size 5

    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);
    cq.push(60); // Should print "Circular Queue is full"

    cq.display();

    cq.pop();
    cq.pop();
    cq.front();

    cq.push(60);
    cq.push(70);
    cq.display(); // Shows circular behavior

    return 0;
}
