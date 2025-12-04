include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = x;
        cout << x << " enqueued" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << arr[front++] << " dequeued" << endl;
        if (front > rear)
            front = rear = -1;
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
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
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
