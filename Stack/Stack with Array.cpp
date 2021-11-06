#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e2 + 5, M = 1e9 + 7;
const ll OO = LONG_LONG_MAX;
#define sz(v)  (int) (v).size()
#define all(v) (v).begin(), (v).end()

class Stack {
private:
    int data[N]{};
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() const { return top == -1; }

    bool isFull() const { return top >= N - 1; }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is Full" << '\n';
            return;
        }
        top++;
        data[top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << '\n';
            return;
        }
        top--;
    }

    int getTop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << '\n';
            return -1;
        }
        return data[top];
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack is Empty" << '\n';
            return;
        }
        for (int i = top; i >= 0; --i) {
            cout << data[i] << '\n';
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.printStack();
    stk.pop();
    stk.printStack();
    cout << "Top is: " << stk.getTop() << '\n';
    return 0;
}
