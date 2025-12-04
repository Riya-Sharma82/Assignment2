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
        if (top == SIZE - 1)
            return;
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
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Stack st;
    for (int i = 0; i < s.length(); i++)
        st.push(s[i]);

    string rev = "";
    while (!st.isEmpty())
        rev += st.pop();

    cout << "Reversed string: " << rev << endl;

    return 0;
}
