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
const int MAX = 5;

class Queue{
private:
    int arr[MAX], front, rear;
public:
    Queue(){
        front = rear = -1;
    }
    bool isEmpty(){
        return front == -1 && rear == -1;
    }
    bool isFull(){
        return rear == MAX - 1;
    }
    void enqueue(int value){
        if(isFull()){
            puts("Queue is Full");
            return;
        } else if(isEmpty()){
            front = rear = 0;
        } else{
            rear++;
        }
        arr[rear] = value;
    }
    void dequeue(){
        if(isEmpty()){
            puts("Queue is Empty");
            return;
        } else if(front == rear){
            front = rear = -1;
        } else{
            front++;
        }
    }
    int getFront(){
        if(isEmpty()){
            puts("Queue is Empty");
            return -1;
        }
        return arr[front];
    }
    int getRear(){
        if(isEmpty()){
            puts("Queue is Empty"); //You can use cout << " " endl; the same.
            return -1;
        }
        return arr[rear];
    }
    void printQueue(){
        if(isEmpty()){
            puts("Queue is Empty"); //You can use cout << " " endl; the same.
            return;
        }
        //You can use one of them.
        /*for (int i = front; i <= rear; ++i) {
            printf("%d ", arr[i]);
        }*/
        while (!isEmpty()){
            printf("%d ", getFront()); //You can use cout << " " endl; the same.
            dequeue();
        }
    }
};

int main(){
    Queue que;
    que.enqueue(10);
    que.enqueue(30);
    que.enqueue(50);
    printf("front is: %d\n", que.getFront()); //You can use cout << " " endl; the same.
    printf("rear is: %d\n", que.getRear()); //You can use cout << " " endl; the same.
    que.printQueue();
    return 0;
}
