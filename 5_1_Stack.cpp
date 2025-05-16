#include <iostream>
using namespace std;

int priority(char temp){
    int priority;
    if ((temp== '+') || (temp=='-')){
        priority=1;
    }
    else if ((temp == '*' || temp == '/')){
        priority=2;
    }
    else{
        priority=0;
    }
    return priority;
    
}

class stackk{
    public:
        char* c;
        int top, size;

        stackk(){
            top=-1;
            size=10;
            c=new char[size];
        }

        stackk(int s){
            top=-1;
            size=s;
            c=new char[size];
        }
 
        bool isEmpty(){
            return (top==-1);
        }

        bool isFull(){
            return (top==size-1);
        }

        void push(char entity){
            if (isFull()){
                cout<<"Stack is Full\n";
            }
            else{
                c[++top]=entity;
            }
        }

        char pop(){
            if (isEmpty()){
                cout<<"Stack is Empty\n";
                return '0';
            }
            else{
                return c[top--];
            }
        }
};

bool CheckBalance(string expression){
    bool balance=true;
    
    int length=expression.size();
    stackk s1(length);
    for (int i = 0; i < length; i++){
        if (expression[i]=='(' || expression[i]=='{' || expression[i]=='['){
//starting
            if (s1.c[s1.top]=='(' && (expression[i]=='{' || expression[i]=='[')){
                balance=false;
                break;
            }
            else if (s1.c[s1.top]=='{' && (expression[i]=='[')){
                balance=false;
                break;
            }
//ending

            s1.push(expression[i]);


        }
        else if (expression[i]==')' || expression[i]=='}' || expression[i]==']'){
            if (s1.isEmpty()){
                balance=false;
                break;
            }
            char topC=s1.pop();
            if ((expression[i]==')' && topC !='(') || (expression[i]=='}' && topC !='{') || (expression[i]==']' && topC !='[') ){
                balance=false;
                break;

            
            }
        }
    }
    if (balance && s1.isEmpty()){
        balance=true;
    }    
    else{
        balance=false;
    }
    return balance;
}

void CheckPalindrome(){
    string expression;
    cout<<"Enter Expression: ";
    cin>>expression;
    int length=expression.size();
    stackk s1(length);
    for (int i = 0; i < length; i++){
        s1.push(expression[i]);
    }
    for (int i = 0; i < length; i++){
        char topC=s1.pop();
        if (topC != expression[i]) {
            cout << "Expression is Not Palindrome\n";
            return;
        }
    }
    cout << "Expression is Palindrome\n";
}

string InfixToPostfix(){
    string expression;
    bool check;
    cout<<"Enter Expression: ";
    while (true){
        cin>>expression;
        check=CheckBalance(expression);
    //Main Logic from Here
        if (check){
            int length=expression.size();
            string outex=""; 
            stackk s1(length);
            for (int i = 0; i < length; i++){
                if (expression[i]=='-' || expression[i]=='+' || expression[i]=='*' || expression[i]=='/' || expression[i]=='(' || expression[i]==')'){
                    if (s1.isEmpty()){
                        s1.push(expression[i]);
                    }
                    else if (priority(expression[i]) <= priority(s1.c[s1.top])){
                        while(true){
                            outex +=s1.pop();
                            if (s1.isEmpty()){
                                s1.push(expression[i]);
                                break;
                            }
                            else if (priority(expression[i]) > priority(s1.c[s1.top])){
                                s1.push(expression[i]);
                                break;
                            }
                        }
                    }
                    else{
                        s1.push(expression[i]);
                    }
                    
                }
                else{
                    outex +=expression[i];
                    cout<<outex<<endl;
                }
            }
            //Stack Display Tester
            while (!(s1.isEmpty())){
                char topC=s1.pop();
                cout<<topC;
            }//Tester End Here

            return outex;

            break;
        }
        else{
            cout<<"Can't convert unbalanced Expression, Enter a valid expresion again:\n";
        }
        
    }
}

int main(){
    int opt;  

    do {
        cout << "\n";
        cout << "Choose Your Choice to Perform Specific Function:\n";
        cout << "1 - Check if Expression is Balanced\n";
        cout << "2 - Check if Expression is Palindrome\n";
        cout << "3 - Convert the infix expression to postfix expression\n";
        cout << "0 - Exit\n";

        string c1_exp;
        bool c1_check;
        string c3_line;
        cin >> opt;
        switch (opt) {
            case 0:
                cout<<"Exiting Program!\n";
                break;
            case 1:
                cout<<"Enter Expression: ";
                cin>>c1_exp;
                c1_check=CheckBalance(c1_exp);
                if (c1_check==true){
                    cout<<"Given Expression is Balanced\n";
                }
                else{
                    cout<<"Given Expression is not Balanced\n";
                }
                
                break;
            case 2:
                CheckPalindrome();
                break;
            case 3:
                c3_line=InfixToPostfix();
                cout<<"Your Expression after converting to Postfix is: "<<c3_line<<endl;
                break;
            default:
                cout << "Invalid Entry";
                break;
        }

    } while (opt != 0);
    return 0;
}