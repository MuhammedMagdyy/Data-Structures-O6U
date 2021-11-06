#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e2 + 5, M = 1e9 + 7;
const ll OO = LONG_LONG_MAX;
#define sz(v)  (int) (v).size()
#define all(v) (v).begin(), (v).end()

//Function to return the double from number
double doubleNum(unsigned char c) {
    int tmp = c;
    return double(tmp - '0');
}

//Function to check what is the operator
bool isOperator(char c) {
    if (c == '+' or c == '-' or c == '*' or c == '/') return true;
    return false;
}

//Function to check if it is operand or no
bool isOperand(char c) {
    if (c >= '0' and c <= '9') return true;
    return false;
}

//Function to make math operation
double math_operation(int a, int b, char c) {
    if (c == '+') return a + b;
    else if (c == '-') return abs(a - b);
    else if (c == '*') return a * b;
    else if (c == '/') return (b * 1.0) / a;
    else return -1e9;
}

//Function to evaluate postfix expression
double evaluation(string &str) {
    stack<double> st;
    int a, b;
    for (auto &it: str) {
        if (isOperator(it)) {
            a = (int) st.top(), st.pop();
            b = (int) st.top(), st.pop();
            st.push(math_operation(a, b, it));
        } else if (isOperand(it)) {
            st.push(doubleNum(it));
        }
    }
    return st.top();
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string s;
    cin >> s;
    cout << evaluation(s) << '\n';
    return 0;
}
