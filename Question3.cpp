#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

class Stack {
    char arr[SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }

    void push(char c) {
        if (top < SIZE - 1)
            arr[++top] = c;
    }

    char pop() {
        if (top == -1)
            return '\0';
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
    
    char peek() {
        if (top == -1)
            return '\0';
        return arr[top];
    }
};

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    if (open == '{' && close == '}') return true;
    return false;
}

bool isBalanced(string exp) {
    Stack st;
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (st.isEmpty())
                return false;
            char top = st.pop();
            if (!isMatchingPair(top, c))
                return false;
        }
    }
    return st.isEmpty();
}

int main() {
    string exp;
    cout << "Enter an expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
