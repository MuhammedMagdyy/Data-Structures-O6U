/*
    In the name of Allah
    MeGzz *_*
    Next Step? ACPC Insha'Allah
    <I CAN DO IT/>
*/
#include <bits/stdc++.h>

using namespace std;
#define read(FILE)  freopen(FILE, "r", stdin);
#define write(FILE) freopen(FILE, "w", stdout);
#define PY puts("YES")
#define PN puts("NO")
#define P puts("")
#define sf scanf
#define pf printf
#define all(v) (v).begin(), (v).end()
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAX_SIZE = 10;

class Stack {
private:
    int data[MAX_SIZE];
    int top;
public:
    Stack() {top = -1;}
    bool isEmpty() {return top == -1;}
    bool isFull() {return top >= MAX_SIZE - 1;}
    void push(int value) {
        if (isFull()) {
            puts("Stack is Full"); //You can use cout << " " << endl; the same don't worry.
            return;
        }
        top++;
        data[top] = value;
    }
    void pop() {
        if (isEmpty()) {
            puts("Stack is Empty"); //You can use cout << " " << endl; the same don't worry.
            return;
        }
        top--;
    }
    int getTop() {
        if (isEmpty()) {
            puts("Stack is Empty"); //You can use cout << " " << endl; the same don't worry.
            return -1;
        }
        return data[top];
    }
    void printStack() {
        if(isEmpty()) {
            puts("Stack is Empty"); //You can use cout << " " << endl; the same don't worry.
            return;
        }
        for (int i = top; i >= 0; --i) {
            printf("%d\n", data[i]); // You can use cout << data[i] << endl; the same don't worry.
        }
    }
};

int main(){
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);
    stk.printStack();
    stk.pop();
    stk.printStack();
    return 0;
}
