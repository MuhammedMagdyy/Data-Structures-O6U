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

class Node{
public:
    int data;
    Node* next;
};

class Stack{
private:
    Node* top;
public:
    Stack(){
        top = nullptr;
    }
    bool isEmpty(){
        return top == nullptr;
    }
    void push(int value){
        Node* newNode = new Node;
        newNode->data = value;
        if (isEmpty()){
            newNode->next = nullptr;
        } else{
            newNode->next = top;
        }
        top = newNode;
    }
    void pop(){
        if (isEmpty()){
            puts("Stack is Empty"); //You can use cout << " " << endl; the same.
            return;
        }
        Node* tempNode = top;
        top = top->next;
        delete tempNode;
    }
    int getTop(){
        if (isEmpty()){
            puts("Stack is Empty"); //You can use cout << " " << endl; the same.
            return -1;
        }
        return top->data;
    }
    void printStack(){
        if (isEmpty()){
            puts("Stack is Empty"); //You can use cout << " " << endl; the same.
            return;
        }
        while (!isEmpty()){
            printf("%d\n", top->data); //You can use cout << " " << endl; the same.
            pop();
        }
    }
};
int main(){
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.pop();
    printf("The top is: %d\n", stk.getTop()); //You can use cout << " " << endl; the same.
    stk.printStack();
    return 0;
}
