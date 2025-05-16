#include <iostream>
using namespace std;

class PizzaOrder{
    private:

    int* s;
    int rear;
    int front;
    int size;
    public:

    PizzaOrder(){
        front=-1;
        rear=-1;
        size=100;
        s=new int[size];
    }

    PizzaOrder(int si){
        front=-1;
        rear=-1;
        size=si;
        s=new int [size];
    }

    bool isFull(){
        if (((rear+1)%size)==front)
        {
            return true;
        }
        else return false;
    }

    bool isEmpty(){
        if (front==-1)
        {
            return true;
        }
        else return false;
    }

    void EnqueRear(int order){
        if (front==-1)
        {
            front=rear=0;
            s[rear]=order;
        }
        else
        {
            rear=(rear+1)%size;
            s[rear]=order;
        } 
    }

    void EnqueFront(int order){
        if (isFull())
        {
            cout<<"Queue Full\n";
        }
        else
        {
            if (front==-1)
            {
                front=rear=0;
                s[rear]=order;
            }
            else if (front==0)
            {
                front=size-1;
            }  
            else
            {
                front=(front-1)%size;
            }
            s[front]=order;
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

    int dequeRear(){
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return -1;
        }
        else
        {
            if (front==rear)
            {
                return s[front];
                front=rear=-1;
            }
            else if (rear==0)
            {
                return s[rear];
                rear=size-1;
            }
            else
            {
                return s[rear];
                rear=(rear-1)%size;
            }
            
        }
        
    }
    
    int getFront(){
        if (isEmpty())
        {
            cout<<"Queue Underflow\n";
            return -1;
        }
        else
        {
            return s[front];
        }   
    }

    int getRear(){
       if (isEmpty())
        {
            cout<<"Queue Underflow\n";
            return -1;
        }
        else
        {
            return s[rear];
        }  
    }
};

int main() {
    PizzaOrder que;

    while (true) {
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
                cout << "Front counter serves: " << que.getFront() << endl;
                que.DequeFront();
                break;
            }
            case 4: {
                cout << "Rear counter serves: " << que.getRear() << endl;
                que.getRear();
                break;
            }
            case 5: {
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