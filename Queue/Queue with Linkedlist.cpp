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
#define pb push_back
#define all(v) (v).begin(), (v).end()
typedef long long ll;
const int MOD = 1e9 + 7;

class Node{
public:
    int data;
    Node* next;
};

class Queue{
private:
    Node* front, *rear;
public:
    Queue(){
        front = rear = nullptr;
    }
    bool isEmpty(){
        return front == nullptr && rear == nullptr;
    }
    void enqueue(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()){
            front = rear = newNode;
        } else{
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue(){
        if (isEmpty()){
            puts("Queue is Empty"); //You can use cout << " " endl; the same.
            return;
        }
        Node* tempNode = front;
        if (front == rear){
            front = rear = nullptr;
        } else{
            front = front->next;
        }
        delete tempNode;
    }
    int getFront(){
        if (isEmpty()){
            puts("Queue is Empty"); //You can use cout << " " endl; the same.
            return -1;
        }
        return front->data;
    }
    int getRear(){
        if (isEmpty()){
            puts("Queue is Empty"); //You can use cout << " " endl; the same.
            return -1;
        }
        return rear->data;
    }
    void printQueue(){
        if (isEmpty()){
            puts("Queue is Empty"); //You can use cout << " " endl; the same.
            return;
        }
        while (!isEmpty()){
            printf("%d ", getFront()); //You can use cout << " " endl; the same.
            dequeue();
        }
    }
};

int main(){
    Queue que;
    que.enqueue(10);
    que.enqueue(20);
    que.enqueue(30);
    printf("front is: %d\n", que.getFront()); //You can use cout << " " endl; the same.
    printf("rear is: %d\n", que.getRear()); //You can use cout << " " endl; the same.
    que.printQueue();
    return 0;
}