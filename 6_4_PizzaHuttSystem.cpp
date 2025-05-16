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

    void EnqueRear(int order) {
        if (front == -1) {
            front = rear = 0;
            s[rear] = order;
        } else {
            rear = (rear + 1) % size;
            s[rear] = order;
        }
    }

    void EnqueFront(int order) {
        if (isFull()) {
            cout << "Queue Full\n";
        } else {
            if (front == -1) {
                front = rear = 0;
                s[rear] = order;
            } else if (front == 0) {
                front = size - 1;
            } else {
                front = (front - 1) % size;
            }
            s[front] = order;
        }
    }

    int DequeFront() {
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

    int dequeRear() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        } else {
            int value = s[rear];
            if (front == rear) {
                front = rear = -1;
            } else if (rear == 0) {
                rear = size - 1;
            } else {
                rear = (rear - 1) % size;
            }
            return value;
        }
    }

    void serveFront() {
        if (isEmpty()) {
            cout << "No customers in the front counter.\n";
        } else {
            cout << "Front counter serves: " << getFront() << endl;
            DequeFront();
        }
    }

    void serveRear() {
        if (isEmpty()) {
            cout << "No customers in the rear counter.\n";
        } else {
            cout << "Rear counter serves: " << dequeRear() << endl;
        }
    }

    void placeOrder() {
        int order, age;
        cout << "Enter the order number: ";
        cin >> order;
        cout << "Enter the customer's age: ";
        cin >> age;
        Enque(order, age);
        cout << "Order placed successfully!\n";
    }

    void getOrder() {
        if (isEmpty()) {
            cout << "No orders available.\n";
        } else {
            int order = Deque();
            cout << "Order number " << order << " served.\n";
        }
    }
};

PizzaOrder que;

void scenario1() {
    cout << "Scenario 1: Pizza Hutt serves orders in first come first served basis." << endl;
    do {
        int choice;
        cout << "\n1. Place Order";
        cout << "\n2. Get Order";
        cout << "\n3. Check all placed orders;";
        cout << "\n4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                que.placeOrder();
                break;
            case 2:
                que.getOrder();
                break;
            case 3:
                cout << "\nAll placed orders are: ";
                que.display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return;
            default:
                break;
        }
    } while (true);
}

void scenario2() {
    cout << "Scenario 2: Pizza Hutt serves orders based on customer age, elder customers served earlier." << endl;
    do {
        int choice;
        cout << "\n1. Place Order";
        cout << "\n2. Get Order";
        cout << "\n3. Check all placed orders;";
        cout << "\n4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                que.placeOrder();
                break;
            case 2:
                que.getOrder();
                break;
            case 3:
                cout << "\nAll placed orders are: ";
                que.display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return;
            default:
                break;
        }
    } while (true);
}

void scenario3() {
    cout << "Scenario 3: Pizza Hutt has two serving units with specific constraints." << endl;
    do {
        int choice;
        cout << "\n1. Customer arrives at the front." << endl;
        cout << "2. Customer arrives at the rear." << endl;
        cout << "3. Serve customer from the front counter." << endl;
        cout << "4. Serve customer from the rear counter." << endl;
        cout << "5. Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int customerId;
                cout << "Enter the customer's Id: ";
                cin >> customerId;
                que.EnqueFront(customerId);
                break;
            }
            case 2: {
                int customerId;
                cout << "Enter the customer's Id: ";
                cin >> customerId;
                que.EnqueRear(customerId); 
                break;
            }
            case 3: {
                que.serveFront();
                break;
            }
            case 4: {
                que.serveRear();
                break;
            }
            case 5: {
                cout << "Exiting the program." << endl;
                return;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    } while (true);
}

int main() {
    int scenarioChoice;

    do {
        cout << "\nChoose Pizza Hutt Scenario:";
        cout << "\n1. First come first served basis.";
        cout << "\n2. Serve customers based on age.";
        cout << "\n3. Two serving units with specific constraints.";
        cout << "\n4. Exit\n";
        cin >> scenarioChoice;

        switch (scenarioChoice) {
            case 1:
                scenario1();
                break;
            case 2:
                scenario2();
                break;
            case 3:
                scenario3();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (scenarioChoice != 4);

    return 0;
}
