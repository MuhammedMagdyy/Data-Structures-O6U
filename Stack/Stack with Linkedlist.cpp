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

class Stack {
private:
    Node *top;
public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        if (isEmpty()) {
            newNode->next = nullptr;
        } else {
            newNode->next = top;
        }
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << '\n';
            return;
        }
        Node *tempNode = top;
        top = top->next;
        delete tempNode;
    }

    int getTop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << '\n';
            return -1;
        }
        return top->data;
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack is Empty" << '\n';
            return;
        }
        while (!isEmpty()) {
            cout << top->data << '\n';
            pop();
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.pop();
    cout << "Top is: " << stk.getTop() << '\n';
    stk.printStack();
    return 0;
}
