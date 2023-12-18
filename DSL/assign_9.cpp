#include <iostream>
using namespace std;

class Node {
public:
    char opening;
    Node* prev;

    Node(char opening) {
        this->opening = opening;
        prev = NULL;
    }
};

class Stack {
public:
    Node* top;

    Stack() {
        top = NULL;
    }
    
    void push(char bracket) {               //giving input so parameter required,hence void data type
        Node *next = new Node(bracket);
        next->prev = top;
        top = next;
    }
    
    char pop() {                            // popping element does not require parameter
        if (top) {
            char popped = top->opening;     // if top exists, then the char popped is the opening  
            top = top->prev;
            return popped;
        } else {
            return 'X';
        }
    }
    
    char peek() {
        if (top) {
            return top->opening;        // peek func shows the top ele of stack,hence return top opening 
        } else {
            return 'X';
        }
    }
    
};

int main() {
    cout<<"Enter an expression: ";
    char exp[100];
    Stack stack;
    cin>>exp;
    int i = 0;
    while (exp[i]) {
        switch (exp[i]) {
        case '{':
            stack.push(exp[i]);
            break;
        case '(':
            stack.push(exp[i]);
            break;
        case '[':
            stack.push(exp[i]);
            break;
        case '}':
            if (stack.peek() == '{')
                stack.pop();
            else {
                cout<<"Invalid Expression\n";
                return 0;
            }
            break;
        case ')':
            if (stack.peek() == '(')
                stack.pop();
            else {
                cout<<"Invalid Expression\n";
                return 0;
            }
            break;
        case ']':
            if (stack.peek() == '[')
                stack.pop();
            else {
                cout<<"Invalid Expression\n";
                return 0;
            }
            break;
        default:
            cout<<"Invalid character\n";
            return 0;
        }
        i++;
    }
     if (stack.peek() == 'X')
        cout<<"Valid Expression\n";
    else
        cout<<"Invalid Expression\n";
    return 0;
}

