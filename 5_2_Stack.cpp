#include <iostream>
#include <cctype>
using namespace std;

class Stack {
public:
    int* arr;
    int top, size;

    Stack(int s) : top(-1), size(s) {
        arr = new int[size];
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == size - 1);
    }

    void push(int entity) {
        if (!isFull()) {
            arr[++top] = entity;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return 0; // Return 0 for an empty stack (you can handle it differently if needed)
    }
};

int priority(char temp) {
    if (temp == '+' || temp == '-')
        return 1;
    else if (temp == '*' || temp == '/')
        return 2;
    else
        return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool CheckPalindrome(string expression) {
    int length = expression.size();
    Stack s1(length);

    for (int i = 0; i < length; i++) {
        s1.push(expression[i]);
    }

    for (int i = 0; i < length; i++) {
        char topC = s1.pop();
        if (topC != expression[i]) {
            return false;
        }
    }

    return true;
}

bool CheckBalance(string expression) {
    int length1;
    length1 = expression.size();
    Stack s1(length1);

    for (int i = 0; i < length1; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            s1.push(expression[i]);
        } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (s1.isEmpty() ||
                (expression[i] == ')' && s1.pop() != '(') ||
                (expression[i] == '}' && s1.pop() != '{') ||
                (expression[i] == ']' && s1.pop() != '[')) {
                return false;
            }
        }
    }

    return s1.isEmpty();
}

string InfixToPostfix(string expression) {
    if (!CheckBalance(expression)) {
        cout << "Invalid Expression: Unbalanced Expression can't be converted.\n";
        return "";
    }

    int length = expression.size();
    string outex = "";
    Stack s2(length);

    for (int i = 0; i < length; i++) {
        if (isdigit(expression[i])) {
            outex += expression[i];
        } else if (isOperator(expression[i])) {
            while (!s2.isEmpty() && priority(expression[i]) <= priority(s2.arr[s2.top])) {
                outex += s2.pop();
            }
            s2.push(expression[i]);
        } else if (expression[i] == '(') {
            s2.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!s2.isEmpty() && s2.arr[s2.top] != '(') {
                outex += s2.pop();
            }
            s2.pop(); // removes '('
        }
    }

    while (!s2.isEmpty()) {
        outex += s2.pop();
    }

    return outex;
}

void evaluation(string expression) {
    int str_length = expression.length();
    Stack exp_eval(str_length);
    for (int i = 0; i < str_length; i++) {
        int number = expression[i] - '0';
        if (isOperator(expression[i])) {
            int num2 = exp_eval.pop();
            int num1 = exp_eval.pop();
            int result;
            if (expression[i] == '+') {
                result = num1 + num2;
            } 
            else if (expression[i] == '-') {
                result = num1 - num2;
            } 
            else if (expression[i] == '*') {
                result = num1 * num2;
            } 
            else if (expression[i] == '/') {
                result = num1 / num2;
            }
            exp_eval.push(result);
        } else {
            exp_eval.push(number);
        }
    }
    cout << "\nThe result is : " << exp_eval.pop() << "\n";
}

int main() {
    int opt;

    do {
        cout << "\n";
        cout << "Choose Your Choice to Perform Specific Function:\n";
        cout << "1 - Check if Expression is Palindrome\n";
        cout << "2 - Check if Expression is Balanced\n";
        cout << "3 - Convert the infix expression to postfix expression\n";
        cout << "4 - Evaluate the postfix expression\n";
        cout << "0 - Exit\n";

        string line;
        cin >> opt;
        switch (opt) {
            case 0:
                cout << "Exiting Program!\n";
                break;
            case 1: {
                string c1_exp;
                cout << "Enter Expression: ";
                cin >> c1_exp;
                if (CheckPalindrome(c1_exp)) {
                    cout << "Given Expression is Palindrome\n";
                } else {
                    cout << "Given Expression is not Palindrome\n";
                }
                break;
            }
            case 2: {
                string c2_exp;
                cout << "Enter Expression: ";
                cin >> c2_exp;
                if (CheckBalance(c2_exp)) {
                    cout << "Given Expression is Balanced\n";
                } else {
                    cout << "Given Expression is not Balanced\n";
                }
                break;
            }
            case 3: {
                string c3_line;
                cout << "Enter Expression: ";
                cin >> c3_line;
                string result = InfixToPostfix(c3_line);
                if (!result.empty()) {
                    cout << "Your Expression after converting to Postfix is: " << result << endl;
                }
                break;
            }
            case 4: {
                string c4_eval;
                cout << "Enter Postfix Expression: ";
                cin >> c4_eval;
                evaluation(c4_eval);
                break;
            }
            default:
                cout << "Invalid Entry";
                break;
        }

    } while (opt != 0);
    return 0;
}
