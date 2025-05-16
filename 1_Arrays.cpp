#include <iostream>
using namespace std;
int SI = -1, LI = -1, size1 = 5, opt = -1;
int arr[5];

void InsertAtEnd() {
    if (SI == -1) {
        cout<<"List is Empty, Enter Your Value at End:\n";
        SI = LI = 0;
        cin >> arr[LI];
    } else if (SI == 0 && LI == size1 - 1) {
        cout << "List is Full, Cant Enter at Last";
    } else if (LI < size1 - 1) {
        cout<<"Space available at End, Enter Your Value:\n";
        LI++;
        cin >> arr[LI];
    } else if (SI != 0 && LI == size1 - 1) {
        cout<<"Space available in List but not at End\n";
        int temp = SI;
        while (temp <= LI) {
            arr[temp - 1] = arr[temp];
            temp++;
        }
        --SI;
        cout<<"Values Shifted to Left, Now Enter Your value at End:\n";
        cin >> arr[LI];
    }
}

void Display() {
    cout << "Your List is:";
    for (int i = SI; i <= LI; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void DeleteFromStart(){
    if (SI!=-1 && SI==LI)
    {
        SI=-1;
        LI=-1;
    }
    else
    {
        SI++;
    }
    
}
void DeleteFromEnd(){
    if (LI!=-1 && LI==SI)
    {
        SI=-1;
        LI=-1;
    }
    else
    {
        LI--;
    }
    
    
}
void InsertAtStart(){
    if (SI==-1)
    {
        cout<<"List is Empty, Enter Your Value at Start:\n";
        SI=LI=0;
        cin>>arr[SI];
    }
    else if (SI==0 && LI==size1-1)
    {
        cout<<"Array is Full, Cant Insert at Start\n";
    }
    else if (SI>0)
    {
        cout<<"Space available at Start, Enter Your Value:\n";
        SI--;
        cin>>arr[SI];
    }
    else if (LI<size1-1 && SI==0) 
    {
        cout<<"Space available but not at Start\n";
        int temp=LI;
        while (temp>=SI)
        {
            arr[temp+1]=arr[temp];
            temp--;
        }
        cout<< "Values Shifted to Right, Enter Your value at Start:\n";
        ++LI;
        cin>>arr[SI];
        

    }
    
}
void InsertAfterSpecific(){
    int SpVal,tempIn;
    bool check1=false;
    cout<<"Enter the Specific Value:\n";
    cin>>SpVal;
    if (SI==0 && LI==size1-1)
    {
        cout<<"List is Full, Cant Enter after " <<SpVal<<"\n";
    }
    else if (SI==-1 && LI==-1)
    {
        cout<<"List is empty, cant find " <<SpVal<<"\n";
    }
    else if (SI>0 && LI<size1-1)
    {
        for (int i = SI; i <= LI; i++){
            if (arr[i]==SpVal)
            {
                tempIn=i;
                check1=true;
                break;
            }
            else
            {
                cout<<"value Not Found in the list/n";
                break;
            }
            
        }
        if (check1==true){
            cout<<"Value found at Index:"<<tempIn<<"\n";
            if (SI>=0 && LI<size1-1)
            {
                cout<<"Shifting Values after specific Index to right\n";
                int temp=LI;
                while (temp>=tempIn)
                {
                    arr[temp+1]=arr[temp];
                    temp--;
                }
                cout<< "Values Shifted to Right, Enter Your value after"<<SpVal<<"\n";
                ++LI;
                cin>>arr[tempIn+1];
            }
            else if (SI>0 && tempIn==size1-1)
            {
                cout<<"Shifting Values before specific index to left\n";
                int temp = SI;
            while (temp <= tempIn) {
                arr[temp - 1] = arr[temp];
                temp++;
            }
            --SI;
            cout<<"Values Shifted to Left, Now Enter Your value at End:\n";
            cin >> arr[tempIn];
            }
            
            
        }


    }

    

}
void InsertBeforeSpecific(){
    cout << "Enter the Specific Value to insert before:\n";
    int SpVal, SpI;
    bool check1 = false;
    cin >> SpVal;

    if (SI == 0 && LI == size1 - 1) {
        cout << "List is Full, Can't Insert before " << SpVal << "\n";
    } else if (SI == -1 && LI == -1) {
        cout << "List is empty, can't find " << SpVal << "\n";
    } else if (SI > 0 && LI < size1 - 1) {
        for (int i = SI; i <= LI; i++) {
            if (arr[i] == SpVal) {
                SpI = i;
                check1 = true;
                break;
            }
        }

        if (check1) {
            cout << "Enter the value to insert before " << SpVal << ":\n";
            int newVal;
            cin >> newVal;

            //shift right
            for (int i = LI; i >= SpI; i--) {
                arr[i + 1] = arr[i];
            }

            arr[SpI] = newVal;
            LI++; 
        } else {
            cout << "Value not found in the list.\n";
        }
    }
    

}
void DeleteSpecific(){
    
    cout << "Enter the Specific Value to delete:\n";
    int SpVal;
    bool check1 = false;
    cin >> SpVal;

    if (SI == -1 && LI == -1) {
        cout << "List is empty, can't find " << SpVal << "\n";
    } else {
        for (int i = SI; i <= LI; i++) {
            if (arr[i] == SpVal) {
                // Shifting
                for (int j = i; j < LI; j++) {
                    arr[j] = arr[j + 1];
                }
                LI--; // Removal
                check1 = true;
                break;
            }
        }

        if (check1) {
            cout << "Value deleted from the list.\n";
        } else {
            cout << "Value not found in the list.\n";
        }
    }

}

int main() {
    do {
        cout << "Choose Your Choice to Perform Specific Function:\n";
        cout << "1 - Insert at End\n";
        cout << "2 - Display\n";
        cout << "3 - Delete From Start\n";
        cout << "4 - Delete from end\n";
        cout << "5 - Insert at Start\n";
        cout << "6 - Insert after specific value\n";
        cout << "7 - Insert before specific value\n";
        cout << "8 - Delete Specific value\n";
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
                InsertAfterSpecific();
                break;
            case 7:
                InsertBeforeSpecific();
                break;
            case 8:
                DeleteSpecific();

        }

    } while (opt != 0);
    return 0;
}
