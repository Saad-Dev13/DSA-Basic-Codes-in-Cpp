#include <iostream>
using namespace std;

class PizzaOrder{
    private:

    int* arr;
    int rear;
    int front;
    int size;
    public:

    PizzaOrder(){
        front=-1;
        rear=-1;
        size=100;
        arr=new int[size];
    }

    PizzaOrder(int si){
        front=-1;
        rear=-1;
        size=si;
        arr=new int [size];
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

    void Enque(int order){
        if (front==-1)
        {
            front=rear=0;
            arr[rear]=order;
        }
        else
        {
            rear=(rear+1)%size;
            arr[rear]=order;
        } 
    }

    int Deque() {
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
    
    int getFront(){
        if (isEmpty())
        {
            cout<<"Queue Underflow\n";
            return -1;
        }
        else
        {
            return arr[front];
        }   
    }

    void display(){
        if (isEmpty())
        {
            cout<<"Queue Underflow\n";
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout<<arr[i]<<" ";
            }    
        }    
    }
};

PizzaOrder que;

void order(){
    if (que.isFull())
    {
        cout<<"Queue Overflow";
    }
    else
    {
        int o_no;
        cout<<"\nEnter Order No: ";
        cin>>o_no;
        que.Enque(o_no);   
    }
}

void getOrder(){
    if (que.isEmpty())
    {
        cout << "Queue Underflow\n";
    }
    else
    {
        cout<<"\nCurrent Order No: ";
        cout<<que.Deque();  
    }  
}

int main(){
    int choice; 
    do
    {
        cout<<"\n1.Place Order";
        cout<<"\n2.Get Order";
        cout<<"\n3.Check all placed orders;";
        cout<<"\n4.Exit\n";
        cin>>choice;

        switch (choice)
        {
        case 1:
            order();
            break;
        case 2:
            getOrder();
            break;
        case 3:
            cout<<"\nAll placed orders are: ";
            que.display();
            break;
        default:
            break;
        }
    } while (choice!=4);
    
}