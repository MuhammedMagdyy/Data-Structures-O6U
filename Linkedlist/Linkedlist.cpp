#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6 + 5, M = 1e9 + 7;
const ll OO = LONG_LONG_MAX;
#define sz(v)  (int) (v).size()
#define all(v) (v).begin(), (v).end()

class Node {
public:
    int data;
    Node *next;
};

class LinkedList {
private:
    Node *head;
public:
    LinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void insertFirst(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void deleteFirst() {
        if (isEmpty()) {
            cout << "List is Empty" << '\n';
            return;
        }
        Node *tempNode = head;
        head = head->next;
        delete tempNode;
    }

    void insertEnd(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()) {
            head = newNode;
        } else {
            Node *tempNode = head;
            while (tempNode->next != nullptr) {
                tempNode = tempNode->next;
            }
            tempNode->next = newNode;
        }
    }

    void deleteEnd() {
        if (isEmpty()) {
            cout << "List is Empty" << '\n';
            return;
        }
        if (head->next == nullptr) { //Just handling this case
            deleteFirst();
        } else {
            Node *tempNode = head;
            while (tempNode->next->next != nullptr) {
                tempNode = tempNode->next;
            }
            delete tempNode->next;
            tempNode->next = nullptr;
        }
    }

    void insertAtPos(int pos, int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        Node *tempNode = head;
        int cnt = pos - 2;
        if (cnt < 0) {
            insertFirst(value);
            return;
        }
        while (cnt--) {
            tempNode = tempNode->next;
        }
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }

    void deleteAtPos(int pos) {
        Node *tempNode = head;
        int cnt = pos - 2;
        if (cnt < 0) {
            deleteFirst();
            return;
        }
        while (cnt--) {
            tempNode = tempNode->next;
        }
        Node *newTempNode = tempNode->next;
        tempNode->next = tempNode->next->next;
        delete newTempNode;
    }

    void reverseList() {
        if (isEmpty()) {
            cout << "List is Empty" << '\n';
            return;
        }
        Node *pre, *cur, *next;
        cur = head;
        while (cur->next != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head = cur;
        head->next = pre;
    }

    int getMaxElement() {
        Node *tempNode = head;
        int value = INT_MIN;
        while (tempNode != nullptr) {
            value = max(value, tempNode->data);
            tempNode = tempNode->next;
        }
        return value;
    }

    int getMinElement() {
        Node *tempNode = head;
        int value = INT_MAX;
        while (tempNode != nullptr) {
            value = min(value, tempNode->data);
            tempNode = tempNode->next;
        }
        return value;
    }

    void PrintList() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
    }

    ~LinkedList() {
        Node *delTemp = head;
        while (delTemp != nullptr) {
            delTemp = delTemp->next;
            delete head;
            head = delTemp;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    LinkedList ll;
    ll.insertFirst(10);
    ll.insertFirst(20);
    ll.insertFirst(30);
    ll.insertAtPos(2, 40);
    ll.insertAtPos(3, 50);
    ll.insertEnd(60);
    ll.deleteAtPos(3);
    ll.deleteFirst();
    ll.deleteEnd();
    ll.PrintList();
    ll.reverseList();
    cout << '\n';
    ll.PrintList();
    cout << '\n';
    cout << "Max is -> " << ll.getMaxElement() << '\n';
    cout << "Min is -> " << ll.getMinElement() << '\n';
    return 0;
}