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

//Function to return if the two braces are pair or not
bool isPair(char first, char second) {
    if (first == '(' && second == ')') {
        return true;
    }
    else if (first == '[' && second == ']') {
        return true;
    }
    else if (first == '{' && second == '}') {
        return true;
    }
    return false;
}

//Function to return if the string isBalanced or not
bool isBalanced(string s) {
    int len = s.size();
    //You can use built in Stack
    Stack stk_balance;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stk_balance.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (stk_balance.isEmpty()) {
                return false;
            }
            else if (!isPair((char)stk_balance.getTop(), s[i])) {
                return false;
            }
            stk_balance.pop();
        }
    }
    if (stk_balance.isEmpty()) {
        return true;
    }
    return false;
}
int main(){
    Stack stk;
    //You can use built in Stack
    string s;
    cin >> s;
    if(isBalanced(s)){
        PY; //You can use cout << "YES" << endl; the same don't worry
    } else{
        PN; //You can use cout << "NO" << endl; the same don't worry
    }
    return 0;
}
