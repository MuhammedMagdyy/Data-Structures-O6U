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

//Function to check the precedence for the value
int precedence(char value){
    if(value == '+' || value == '-'){
        return 1;
    } else if(value == '*' || value == '/'){
        return 2;
    } else if(value == '^'){
        return 3;
    }
    return -1;
}

//Function to convert infix to postfix
string InfixToPostfix(string s){
    //Use built in stack ... faster than hand made stack
    stack<char> stk;
    string out;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        if(s[i] == ' '){
            continue;
        }
        if (isdigit(s[i]) || isalpha(s[i])){ //to check if the value is digit or alphabet
            out += s[i];
        } else if(s[i] == '('){
            stk.push('(');
        } else if(s[i] == ')'){
            while (stk.top() != '('){
                out += stk.top();
                stk.pop();
            }
            stk.pop();
        } else{
            while (!stk.empty() && precedence(s[i]) <= precedence(stk.top())){
                out += stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while (!stk.empty()){
        out += stk.top();
        stk.pop();
    }
    return out;
}

int main(){
    string str;
    cin >> str;
    cout << InfixToPostfix(str) << endl;
    return 0;
}
