#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e2 + 5, M = 1e9 + 7;
const ll OO = LONG_LONG_MAX;
#define sz(v)  (int) (v).size()
#define all(v) (v).begin(), (v).end()

class Queue {
private:
    int arr[N]{}, front, rear;
public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() const {
        return front == -1 and rear == -1;
    }

    bool isFull() const {
        return ((rear + 1) % N) == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full" << '\n';
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % N;
        }
        arr[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << '\n';
            return;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % N;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty" << '\n';
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is Empty" << '\n';
            return -1;
        }
        return arr[rear];
    }

    void PrintQueue() {
        while (!isEmpty()) {
            cout << getFront() << ' ';
            dequeue();
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    Queue que;
    que.enqueue(10);
    que.enqueue(30);
    que.enqueue(50);
    que.enqueue(40);
    que.enqueue(60);
    cout << "Front is : " << que.getFront() << '\n';
    cout << "Rear is : " << que.getRear() << '\n';
    que.PrintQueue();
    return 0;
}
