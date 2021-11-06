#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e2 + 5, M = 1e9 + 7;
const ll OO = LONG_LONG_MAX;
#define sz(v)  (int) (v).size()
#define all(v) (v).begin(), (v).end()

class Stack {
private:
    char data[N]{};
    char top;
public:
    Stack() { top = -1; }

    bool isEmpty() const { return top == -1; }

    bool isFull() const { return top >= N - 1; }

    void push(char value) {
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
};

//Function to return if the string isBalanced or not
bool isBalanced(string &str) {
    Stack stk_balance;
    for (auto &i: str) {
        if (i == '(' or i == '{' or i == '[') {
            stk_balance.push(i);
        } else {
            if (!stk_balance.isEmpty()) {
                if (i == ')' and stk_balance.getTop() == '(' or i == '}' and
                    stk_balance.getTop() == '{' or i == ']' and
                    stk_balance.getTop() == '[') {
                    stk_balance.pop();
                } else {
                    stk_balance.push(i);
                }
            } else {
                stk_balance.push(i);
            }
        }
    }
    return stk_balance.isEmpty();
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string s;
    cin >> s;
    cout << (isBalanced(s) ? "YES" : "NO") << '\n';
    return 0;
}
