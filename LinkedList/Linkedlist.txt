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

class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head = nullptr;
    }
    bool isEmpty(){
        return head == nullptr;
    }
    void insertFirst(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()){
            head = newNode;
        } else{
            newNode->next = head;
            head = newNode;
        }
    }
    void deleteFirst(){
        if (isEmpty()){
            puts("List is Empty"); //You can use cout << " " << endl; the same.
            return;
        }
        Node* tempNode = head;
        head = head->next;
        delete tempNode;
    }
    void insertEnd(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()){
            head = newNode;
        } else{
            Node* tempNode = head;
            while (tempNode->next != nullptr){
                tempNode = tempNode->next;
            }
            tempNode->next = newNode;
        }
    }
    void deleteEnd(){
        if (isEmpty()){
            puts("List is Empty"); //You can use cout << " " << endl; the same.
            return;
        }
        if (head->next == nullptr){ //Just handling this case
            deleteFirst();
        } else{
            Node* tempNode = head;
            while (tempNode->next->next != nullptr){
                tempNode = tempNode->next;
            }
            delete tempNode->next;
            tempNode->next = nullptr;
        }
    }
    void insertAtPos(int pos, int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        Node* tempNode = head;
        int ctn = pos - 2;
        while (ctn--){
            tempNode = tempNode->next;
        }
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }
    void deleteAtPos(int pos){
        Node* tempNode = head;
        int ctn = pos - 2;
        while (ctn--){
            tempNode = tempNode->next;
            Node* newTempNode;
            newTempNode = tempNode->next;
            tempNode->next = tempNode->next->next;
            delete newTempNode;
        }
    }
    void reverseList(){
        if (isEmpty()){
            puts("List is Empty"); //You can use cout << " " << endl; the same.
            return;
        }
        Node* pre, *cur, *next;
        pre = next = nullptr;
        cur = head;
        while (cur->next != nullptr){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head = cur;
        head->next = pre;
    }
    int getMaxElement(){
       Node* tempNode = head;
       int value = INT_MIN;
        while (tempNode != nullptr){
            value = max(value, tempNode->data);
            tempNode = tempNode->next;
        }
        return value;
    }
    int getMinElement(){
        Node* tempNode = head;
        int value = INT_MAX;
        while (tempNode != nullptr){
            value = min(value, tempNode->data);
            tempNode = tempNode->next;
        }
        return value;
    }
    void PrintList() {
        Node* temp = head;
        while(temp != nullptr) {
            printf("%d ", temp->data); //You can use cout << " " << endl; the same.
            temp = temp->next;
        }
    }
    ~LinkedList(){
        Node* delTemp = head;
        while (delTemp != nullptr){
            delTemp = delTemp->next;
            delete head;
            head = delTemp;
        }
    }
};

int main(){
    LinkedList ll;
    ll.insertFirst(10);
    ll.insertAtPos(2, 20);
    ll.insertAtPos(3, 30);
    ll.insertEnd(40);
    printf("Max is: %d\n", ll.getMaxElement()); //You can use cout << " " << endl; the same.
    printf("Min is: %d\n", ll.getMinElement()); //You can use cout << " " << endl; the same.
    ll.reverseList();
    ll.PrintList();
    return 0;
}