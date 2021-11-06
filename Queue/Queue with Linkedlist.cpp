#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e2 + 5, M = 1e9 + 7;
const ll OO = LONG_LONG_MAX;
#define sz(v)  (int) (v).size()
#define all(v) (v).begin(), (v).end()

class Node {
public:
    int data;
    Node *next;
};

class Queue {
private:
    Node *front, *rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr and rear == nullptr;
    }

    void enqueue(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << '\n';
            return;
        }
        Node *tempNode = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
        }
        delete tempNode;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty" << '\n';
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is Empty" << '\n';
            return -1;
        }
        return rear->data;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << '\n';
            return;
        }
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
    que.enqueue(20);
    que.enqueue(30);
    cout << "Front is : " << que.getFront() << '\n';
    cout << "Rear is : " << que.getRear() << '\n';
    que.printQueue();
    return 0;
}
