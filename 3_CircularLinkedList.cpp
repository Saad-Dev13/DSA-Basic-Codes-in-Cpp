#include <iostream>
using namespace std;

int opt = -1;

struct Stu {
    int num;
    struct Stu* next;
};

Stu* first = NULL;
Stu* last = NULL;

Stu* first_odd = NULL;
Stu* last_odd = NULL;

Stu* first_even = NULL;
Stu* last_even = NULL;

Stu* search(int key) {
    Stu* P = first;
    while (P != NULL && P->num != key) {
        P = P->next;
    }
    return P;
}

void InsertAtEnd() {
    Stu* curr = new Stu;

    cout << "Enter Number:";
    cin >> curr->num;

    if (first == NULL) {
        first = last = curr;
    } else {
        last->next = curr;
        last = curr;
    }
    last->next = first;
}

void Display() {
    if (first == NULL) {
        cout << "The List is Empty. \n";
    } else {
        Stu* P = first;
        cout << "Your numbers are: ";
        do {
            cout << P->num << " ";
            P = P->next;
        } while (P != first);
        cout << endl;
    }
}

void DeleteFromStart() {
    if (first == NULL) {
        cout << "Empty List, No Values to Delete.\n";
    } else {
        Stu* temp = first;
        first = first->next;
        last->next = first;
        delete temp;
        cout << "Deleted from Start\n";
    }
}

void DeleteFromEnd() {
    if (first == NULL) {
        cout << "Empty List, No Values to Delete.\n";
    } else if (first->next == first) {
        delete first;
        first = last = NULL;
    } else {
        Stu* temp = first;
        while (temp->next != last) {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = first;
        cout << "Value Deleted From End.\n";
    }
}

void InsertAtStart() {
    Stu* temp = new Stu;
    cout << "Enter Number You want to Insert at Start: ";
    cin >> temp->num;
    if (first == NULL) {
        first = last = temp;
        first->next = last->next = NULL;
    } else {
        temp->next = first;
        first = temp;
        last->next = first;
    }
}

void InsertAfterSpecific(int key) {
    Stu* temp = search(key);
    if (temp == NULL) {
        cout << "Not Found.\n";
    } else {
        Stu* curr = new Stu;
        cout << "Enter Number to Insert after " << key << ": ";
        cin >> curr->num;
        curr->next = temp->next;
        temp->next = curr;
    }
}

void InsertBeforeSpecific(int key) {
    Stu* temp = search(key);
    if (temp == NULL) {
        cout << "Not Found.\n";
    } else {
        Stu* curr = new Stu;
        cout << "Enter Number to Insert before " << key << ": ";
        cin >> curr->num;

        if (temp == first) {
            curr->next = first;
            first = curr;
            last->next = first;
        } else {
            Stu* prev = first;
            while (prev->next != temp) {
                prev = prev->next;
            }
            curr->next = temp;
            prev->next = curr;
        }
    }
}

void DeleteSpecific(int key) {
    if (first == NULL) {
        cout << "List is Empty, Can't find value";
    } else if ((first == last) && (first->num == key)) {
        first = last = NULL;
    } else {
        Stu* temp = search(key);
        if (temp == NULL) {
            cout << "Value Not Found in List.";
        } else {
            Stu* check = first;
            while (check->next != temp) {
                check = check->next;
            }
            check->next = temp->next;
            if (temp == first) {
                first = first->next;
                last->next = first;
            }
            delete temp;
            cout << "Specific Value Deleted.\n";
        }
    }
}

void DisplayReverse() {
    if (first == NULL) {
        cout << "List is Empty, Can't Reverse\n";
    } else {
        cout << "Displaying Your Reverse List as: ";
        Stu* Ftemp = first;
        Stu* Ltemp = last;

        do {
            while (Ftemp->next != Ltemp) {
                Ftemp = Ftemp->next;
            }
            cout << Ltemp->num << " ";
            Ltemp = Ftemp;
            Ftemp = first;
        } while (Ltemp != first);

        cout << first->num << endl; // First element
    }
}

void ReverseList() {
    if (first == NULL || first->next == first) {
        cout << "The list is empty or has only one element, no need to reverse.\n";
        return;
    } else {
        Stu* curr = first;
        Stu* prev = NULL;
        Stu* next = curr->next;

        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != first);

        last = first;
        first = prev;
    }
}

void ReverseDisplayRecursion(Stu* curr) {
    if (first == last) {
        cout << "List only has one element, " << first->num;
    } else if (first == NULL) {
        cout << "List is Empty, Nothing to display";
    } else {
        if (curr != NULL) {
            ReverseDisplayRecursion(curr->next);
            cout << curr->num << " ";
        }
    }
}

void ReverseRecursion(Stu* curr) {
    if (first == last) {
        cout << "List only has one element, ";
        curr = first;
    } else if (first == NULL) {
        cout << "List is Empty, Nothing to Reverse";
    } else {
        if (curr->next == NULL) {
            first = curr;
            first->next = last->next = NULL;
            return;
        } else {
            ReverseRecursion(curr->next);
            Stu* y = curr->next;
            y->next = curr;
            curr->next = NULL;
        }
    }
}

void SwapSpecific() {
    if (first == NULL || first->next == first) {
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

void Split() {
    if (first == NULL) {
        cout << "The List is Empty";
        return;
    } else {
        Stu* temp = first;
        do {
            if (temp->num % 2 == 0) {
                Stu* curr_even = new Stu;
                curr_even->num = temp->num;
                if (first_even == NULL) {
                    first_even = last_even = curr_even;
                } else {
                    curr_even->next = first_even;
                    last_even->next = curr_even;
                    last_even = curr_even;
                }
            } else {
                Stu* curr_odd = new Stu;
                curr_odd->num = temp->num;
                if (first_odd == NULL) {
                    first_odd = last_odd = curr_odd;
                } else {
                    curr_odd->next = first_odd;
                    last_odd->next = curr_odd;
                    last_odd = curr_odd;        
                }
            }
            temp = temp->next;
        } while (temp != first);
    }
}

void DisplayEven() {
    if (first_even == NULL) {
        cout << "List is Empty, Split the List First before Displaying\n";
    } else {
        Stu* temp = first_even;
        cout << "Even List is: ";
        do {
            cout << temp->num << "  ";
            temp = temp->next;
        } while (temp != first_even);
        cout << endl;
    }
}

void DisplayOdd() {
    if (first_odd == NULL) {
        cout << "List is Empty, Split the List First before Displaying\n";
    } else {
        Stu* temp = first_odd;
        cout << "Odd List is: ";
        do {
            cout << temp->num << "  ";
            temp = temp->next;
        } while (temp != first_odd);
        cout << endl;
    }
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
        cout << "14 - Split node into even and odd Nodes\n";
        cout << "15 - Display Even\n";
        cout << "16 - Display Odd\n";
        cout << "0 - Exit\n";

        cin >> opt;
        switch (opt) {
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
                cout << "Enter the specific value You want to Delete:";
                cin >> key;
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
                Split();
                break;
            case 15:
                DisplayEven();
                break;
            case 16:
                DisplayOdd();
                break;
            default:
                cout << "Invalid Entry";
                break;
        }
    } while (opt != 0);
    return 0;
}
