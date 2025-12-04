#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == SIZE - 1)
            return;
        arr[++rear] = x;
    }

    int dequeue() {
        if (isEmpty())
            return -1;
        return arr[front++];
    }

    bool isEmpty() {
        return front > rear;
    }

    int size() {
        return rear - front + 1;
    }

    void display() {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void interleaveQueue(Queue &q) {
    int n = q.size();
    if (n % 2 != 0)
        return;

    int half = n / 2;
    Queue firstHalf;

    for (int i = 0; i < half; i++)
        firstHalf.enqueue(q.dequeue());

    Queue result;

    while (!firstHalf.isEmpty()) {
        result.enqueue(firstHalf.dequeue());
        result.enqueue(q.dequeue());
    }

    while (!result.isEmpty())
        cout << result.dequeue() << " ";
    cout << endl;
}

int main() {
    Queue q;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.enqueue(val);
    }

    cout << "Interleaved output: ";
    interleaveQueue(q);

    return 0;
}
