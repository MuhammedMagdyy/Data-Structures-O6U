#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e2 + 5, M = 1e9 + 7;
const ll OO = LONG_LONG_MAX;
#define sz(v)  (int) (v).size()
#define all(v) (v).begin(), (v).end()

//Function to check the precedence for the value
int precedence(char value) {
    if (value == '+' or value == '-') return 1;
    else if (value == '*' or value == '/') return 2;
    else if (value == '^') return 3;
    return -1;
}

//Function to convert infix to postfix
string InfixToPostfix(string &s) {
    //Use built in stack ... faster than hand made stack
    //You will find hand made stack in my repo, try it
    stack<char> stk;
    string out;
    int len = (int) s.size();
    for (int i = 0; i < len; ++i) {
        if (s[i] == ' ') {
            continue;
        }
        if (isdigit(s[i]) or isalpha(s[i])) {
            //to check if the value is digit or alphabet
            // alpha -> s[i] >= 'a' and s[i] <= 'z' or s[i] >= 'A' and s[i] <= 'Z'
            // digit -> s[i] >= '0' and s[i] <= '9'
            out += s[i];
        } else if (s[i] == '(') {
            stk.push('(');
        } else if (s[i] == ')') {
            while (stk.top() != '(') {
                out += stk.top();
                stk.pop();
            }
            stk.pop();
        } else {
            while (!stk.empty() and precedence(s[i]) <= precedence(stk.top())) {
                out += stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while (!stk.empty()) {
        out += stk.top();
        stk.pop();
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str;
    cin >> str;
    cout << InfixToPostfix(str) << '\n';
    return 0;
}
