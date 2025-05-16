#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int* arr;
    int rear;
    int front;
    int size;
    int preAge;

public:
    PriorityQueue(int si) {
        front = -1;
        rear = -1;
        size = si;
        arr = new int[size];
        preAge = 0;
    }

    bool isFull() {
        return ((rear + 1) % size) == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void Enqueue(int value, int age) {
        if (front == -1) {
            front = rear = 0;
            arr[rear] = value;
        } else if (age > preAge) {
            front = (front - 1 + size) % size;
            arr[front] = value;
        } else {
            rear = (rear + 1) % size;
            arr[rear] = value;
        }
        preAge = age;
    }

    int Dequeue() {
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

    int Front() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        } else {
            return arr[front];
        }
    }

    void Display() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
        } else {
            cout << "Queue Elements: ";
            int i = front;
            do {
                cout << arr[i] << " ";
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
            cout << endl;
        }
    }
};

PriorityQueue que(5); // Change the size of the queue as needed

void Enqueue() {
    int value, age;
    cout << "Enter the value to enqueue: ";
    cin >> value;
    cout << "Enter the age: ";
    cin >> age;
    que.Enqueue(value, age);
}

void Dequeue() {
    int value = que.Dequeue();
    if (value != -1) {
        cout << "Dequeued value: " << value << endl;
    }
}

void DisplayQueue() {
    que.Display();
}

int main() {
    int choice;
    do {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display Queue";
        cout << "\n4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                DisplayQueue();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
