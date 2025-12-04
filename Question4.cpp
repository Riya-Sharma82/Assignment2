#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

class Stack {
    char arr[SIZE];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) {
        if (top < SIZE - 1)
            arr[++top] = c;
    }
    char pop() {
        if (top == -1)
            return '\0';
        return arr[top--];
    }
    char peek() {
        if (top == -1)
            return '\0';
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            postfix += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(')
                postfix += st.pop();
            st.pop();
        }
        else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c))
                postfix += st.pop();
            st.push(c);
        }
    }
    while (!st.isEmpty())
        postfix += st.pop();
    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}
