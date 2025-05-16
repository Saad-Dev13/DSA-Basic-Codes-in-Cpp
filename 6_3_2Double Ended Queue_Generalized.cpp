#include <iostream>
using namespace std;

class DoubleEndedQueue {
private:
    int* arr;
    int rear;
    int front;
    int size;

public:
    DoubleEndedQueue(int si) {
        front = -1;
        rear = -1;
        size = si;
        arr = new int[size];
    }

    bool isFull() {
        return ((rear + 1) % size) == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void EnqueueRear(int value) {
        if (front == -1) {
            front = rear = 0;
            arr[rear] = value;
        } else {
            rear = (rear + 1) % size;
            arr[rear] = value;
        }
    }

    void EnqueueFront(int value) {
        if (isFull()) {
            cout << "Queue Full\n";
        } else {
            if (front == -1) {
                front = rear = 0;
                arr[rear] = value;
            } else if (front == 0) {
                front = size - 1;
            } else {
                front = (front - 1 + size) % size;
            }
            arr[front] = value;
        }
    }

    int DequeueFront() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        } else {
            int value = arr[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
            return value;
        }
    }

    int DequeueRear() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        } else {
            int value = arr[rear];
            if (front == rear) {
                front = rear = -1;
            } else if (rear == 0) {
                rear = size - 1;
            } else {
                rear = (rear - 1 + size) % size;
            }
            return value;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        } else {
            return arr[front];
        }
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        } else {
            return arr[rear];
        }
    }
};

int main() {
    DoubleEndedQueue que(5); // Change the size of the queue as needed

    while (true) {
        int choice;
        cout << "\n1. Enqueue at Rear" << endl;
        cout << "2. Enqueue at Front" << endl;
        cout << "3. Dequeue from Front" << endl;
        cout << "4. Dequeue from Rear" << endl;
        cout << "5. Display Front" << endl;
        cout << "6. Display Rear" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to enqueue at Rear: ";
                cin >> value;
                que.EnqueueRear(value);
                break;
            }
            case 2: {
                int value;
                cout << "Enter the value to enqueue at Front: ";
                cin >> value;
                que.EnqueueFront(value);
                break;
            }
            case 3: {
                cout << "Dequeued from Front: " << que.DequeueFront() << endl;
                break;
            }
            case 4: {
                cout << "Dequeued from Rear: " << que.DequeueRear() << endl;
                break;
            }
            case 5: {
                cout << "Front: " << que.getFront() << endl;
                break;
            }
            case 6: {
                cout << "Rear: " << que.getRear() << endl;
                break;
            }
            case 7: {
                cout << "Exiting the program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    return 0;
}
