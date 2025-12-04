#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (rear + 1 == front);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = x;
        cout << x << " enqueued" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << arr[front] << " dequeued" << endl;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, val;
    while (true) {
        cout << "\n1.Enqueue\n2.Dequeue\n3.isEmpty\n4.isFull\n5.Display\n6.Peek\n7.Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                if (q.isEmpty())
                    cout << "Queue is empty" << endl;
                else
                    cout << "Queue is not empty" << endl;
                break;
            case 4:
                if (q.isFull())
                    cout << "Queue is full" << endl;
                else
                    cout << "Queue is not full" << endl;
                break;
            case 5:
                q.display();
                break;
            case 6:
                q.peek();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
