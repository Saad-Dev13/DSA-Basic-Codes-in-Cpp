#include <iostream>
using namespace std;

class PizzaOrder {
private:
    int* s;
    int rear;
    int front;
    int size;
    int preAge;

public:
    PizzaOrder() {
        front = -1;
        rear = -1;
        size = 100;
        s = new int[size];
        preAge = 0;
    }

    PizzaOrder(int si) {
        front = -1;
        rear = -1;
        size = si;
        s = new int[size];
        preAge = 0;
    }

    bool isFull() {
        return ((rear + 1) % size) == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void Enque(int p_order, int c_age) {
        if (front == -1) {
            front = rear = 0;
            s[rear] = p_order;
        } else if (c_age > preAge) {
            front = (front - 1 + size) % size;
            s[front] = p_order;
        } else {
            rear = (rear + 1) % size;
            s[rear] = p_order;
        }
        preAge = c_age;
    }

    int Deque() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        } else {
            int value = s[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % size;
            }
            return value;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        } else {
            return s[front];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
        } else {
            int i = front;
            do {
                cout << s[i] << " ";
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
        }
    }
};

PizzaOrder que;

void placeOrder() {
    if (que.isFull()) {
        cout << "\nQueue Overflow\n";
    } else {
        int order;
        int age;
        cout << "\nEnter the Order: ";
        cin >> order;
        cout << "\nEnter the age: ";
        cin >> age;
        que.Enque(order, age);
    }
}

void getOrder() {
    if (que.isEmpty()) {
        cout << "Queue Underflow\n";
    } else {
        cout << "\nCurrent Order No: " << que.Deque();
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Place Order";
        cout << "\n2. Get Order";
        cout << "\n3. Check all placed orders;";
        cout << "\n4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                placeOrder();
                break;
            case 2:
                getOrder();
                break;
            case 3:
                cout << "\nAll placed orders are: ";
                que.display();
                break;
            default:
                break;
        }
    } while (choice != 4);

    return 0;
}
