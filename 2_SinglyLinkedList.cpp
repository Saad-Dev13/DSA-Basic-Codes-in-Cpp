
#include <iostream>
using namespace std;
int opt=-1;

struct Stu {
    int num;
    struct Stu *next=NULL;
};

Stu *first=NULL;
Stu *last=NULL;

Stu *search(int key) {
    Stu* P = first;
    while (P != NULL && P->num != key) {
        P = P->next;
    }
    return P;
}

void InsertAtEnd(){
    Stu *curr=new Stu;

    cout<<"Enter Number:";
    cin>>curr->num;

    if (first==NULL){
        first=last=curr;
    }
    else {
        last->next=curr;
        last=curr;
    }

}

void Display(){
    if (first==NULL)
    {
        cout<<"The List is Empty. \n";
    }
    else{
        Stu *P;
        P=first;
        cout<<"Your numbers are: ";
        while (P!=NULL)
        {
            cout<< P->num <<" ";
            P=P->next;
        }
    }
    
}

void DeleteFromStart(){
    if (first==NULL){
        cout<<"Empty List, No Values to Delete.\n";
    }
    else{
        Stu *temp=first;
        first=first->next;
        delete temp;
        cout<<"Deleted from Start";
    }

}

void DeleteFromEnd(){
    if (first==NULL){
        cout<<"Empty List, No Values to Delete.\n";
    }
    else if(first->next==NULL){
        delete first;
        first=last=NULL;
    }
    else{
        Stu *temp=first;
        while (temp->next !=last)
        {
            temp=temp->next;
        }
        delete last;
        last=temp;
        last->next=NULL;
        //delete temp;
        cout<<"Value Deleted From End.\n";
        
    }
    
}

void InsertAtStart(){
    Stu *temp=new Stu;
    cout<<"Enter Number You want to Insert at Start: ";
    cin>>temp->num;
    if (first==NULL)
    {
        first=last=temp;
        first->next=NULL;
    }
    else{
        temp->next=first;
        first=temp;
        //delete temp;  Question: Why we not delete it?
    }
    
}

void InsertAfterSpecific(int key){
    Stu* temp = search(key);
    if (temp == NULL) {
        cout << "Not Found.\n";
    }
    else {
        Stu* curr = new Stu;
        cout << "Enter Number to Insert after " << key << ": ";
        cin >> curr->num;
        curr->next = temp->next;
        temp->next = curr;
    }


}

void InsertBeforeSpecific(int key){
    Stu* temp = search(key);
    if (temp == NULL) {
        cout << "Not Found.\n";
    }
    else {
        Stu* curr = new Stu;
        cout << "Enter Number to Insert before " << key << ": ";
        cin >> curr->num;

        if (temp == first) {
            curr->next = first;
            first = curr;
        }
        else {
            Stu* prev = first;
            while (prev->next != temp) {
                prev = prev->next;
            }
            curr->next = temp;
            prev->next = curr;
        }
    }
}

void DeleteSpecific(int key){
    if (first==NULL){
        cout<<"List is Empty, Cant find value";
    }
    else if ((first==last) && (first->num==key))
    {
        first=last=NULL;   
    }
    else {
        Stu *temp = search(key);
        if (temp==NULL) {
            cout<<"Value Not Found in List.";
        }
        else{
            Stu *prev = first;
            while (prev->next !=temp){
                prev=prev->next;
            }
            prev->next=temp->next;
            delete temp;
            cout<<"Specific Value Deleted.\n";
        }

    }
}

void DisplayReverse(){
    if (first == NULL) {
        cout << "List is Empty, Can't Reverse\n";
    } else if (first == last) {
        cout << "Displaying Your Reverse List as: " << first->num << endl;
    } else {
        cout << "Displaying Your Reverse List as: ";
        Stu* Ftemp = first;
        Stu* Ltemp = last;

        while (Ltemp != first) {
            while (Ftemp->next != Ltemp) {
                Ftemp = Ftemp->next;
            }
            cout << Ltemp->num << " ";
            Ltemp = Ftemp;
            Ftemp = first; 
        }
        cout << first->num << endl; //First element
    }
}

void ReverseList() {
    if (first == NULL || first == last) {
        cout<<"The list is empty or has only one element, no need to reverse.\n";
        return;
    } 
    else {
        Stu *curr = first;
        Stu *prev = NULL;
        Stu *next = curr->next;
        
        while (curr != NULL) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        last=first;
        first=prev;
    }
}

void ReverseDisplayRecursion(Stu *curr){
        if (first==last){
            cout<<"List only has one element, "<<first->num;
        }
        else if (first==NULL){
            cout<<"List is Empty, Nothing to display";
        }
        else{
            if (curr!=NULL){
                ReverseDisplayRecursion(curr->next);
                cout<<curr->num<<" ";
            }
        }
}

void ReverseRecursion(Stu *curr){
        if (first==last){
            cout<<"List only has one element, ";
            curr=first;
        }
        else if (first==NULL){
            cout<<"List is Empty, Nothing to Reverse";
        }
        else{
            if ((curr->next)==NULL){
                first=curr;
                return;
            }
            else {
                ReverseRecursion(curr->next);
                Stu* temp=curr->next;
                temp->next=curr;
                curr->next=NULL;

            }
        }
}

void SwapSpecific(){
    if (first == NULL || first->next == NULL) {
        cout << "List has fewer than two elements, cannot perform swap.\n";
        return;
    }

    int a, b;
    cout << "Enter the first number to swap: ";
    cin >> a;
    cout << "Enter the second number to swap: ";
    cin >> b;

    Stu* nodeA = search(a);
    Stu* nodeB = search(b);

    if (nodeA == NULL || nodeB == NULL) {
        cout << "One or both of the specified values not found in the list.\n";
        return;
    }

    int temp = nodeA->num;
    nodeA->num = nodeB->num;
    nodeB->num = temp;

    cout << "Nodes with values " << a << " and " << b << " swapped successfully.\n";
}
/*void SwapSpecific(){
    if (first == NULL || first->next == NULL) {
        cout << "List has fewer than two elements, cannot perform swap.\n";
        return;
    }

    int a, b;
    cout << "Enter the first number to swap: ";
    cin >> a;
    cout << "Enter the second number to swap: ";
    cin >> b;

    Stu* nodeA = search(a);
    Stu* nodeB = search(b);

    if (nodeA == NULL || nodeB == NULL) {
        cout << "One or both of the specified values not found in the list.\n";
        return;
    }

    if (nodeA != first) {
        Stu* prevA = first;
        while (prevA->next != nodeA) {
            prevA = prevA->next;
        }
        prevA->next = nodeB;
    } else {
        first = nodeB;
    }

    if (nodeB != first) {
        Stu* prevB = first;
        while (prevB->next != nodeB) {
            prevB = prevB->next;
        }
        prevB->next = nodeA;
    } else {
        first = nodeA;
    }

    Stu* temp = nodeA->next;
    nodeA->next = nodeB->next;
    nodeB->next = temp;

    cout << "Nodes with values " << a << " and " << b << " swapped successfully.\n";
}
*/

Stu *FindMin(){
    Stu *min=first;
    Stu *temp=first;
    while (temp!=nullptr){
        if (temp->num<min->num){
            min=temp;
        }
        temp=temp->next;
    }
    return min;
}





int main() {
    do {
        cout << "\n";
        cout << "Choose Your Choice to Perform Specific Function:\n";
        cout << "1 - Insert at End\n";
        cout << "2 - Display\n";
        cout << "3 - Delete From Start\n";
        cout << "4 - Delete from end\n";
        cout << "5 - Insert at Start\n";
        cout << "6 - Insert after specific value\n";
        cout << "7 - Insert before specific value\n";
        cout << "8 - Delete Specific Value\n";
        cout << "9 - Display in Reverse\n";
        cout << "10 - Reverse List\n";
        cout << "11 - Reverse Display using Recursion\n";
        cout << "12 - Reverse List by Recursion\n";
        cout << "13 - Swap Specific Nodes\n";
        cout << "14 - Find Minimum\n";
        cout << "0 - Exit\n";

        cin >> opt;
        switch (opt) {
            case 0:
                cout<<"Exiting Program\n";
                break;
            case 1:
                InsertAtEnd();
                break;
            case 2:
                Display();
                break;
            case 3:
                DeleteFromStart();
                break; 
            case 4:
                DeleteFromEnd();
                break;

            case 5:
                InsertAtStart();
                break;
            case 6:
                int key;
                cout << "Enter the specific value after which you want to insert: ";
                cin >> key;
                InsertAfterSpecific(key);
                break;
            case 7:
                cout << "Enter the specific value before which you want to insert: ";
                cin >> key;            
                InsertBeforeSpecific(key);
                break; 
            case 8:
                cout<<"Enter the specific value You want to Delete:";
                cin>> key;
                DeleteSpecific(key);
                break;
            case 9:
                DisplayReverse();
                break;
            case 10:
                ReverseList();
                break;
            case 11:
                ReverseDisplayRecursion(first);
                break;
            case 12:
                ReverseRecursion(first);
                break;
            case 13:
                SwapSpecific();
                break;
            case 14:
                Stu* foundm;
                foundm=FindMin();
                cout<<"Minimum Value is: "<<foundm->num<<"\n";
                break;
            default:
                cout<<"Invalid Entry";
                break;

        }

    } while (opt != 0);
    return 0;
}
