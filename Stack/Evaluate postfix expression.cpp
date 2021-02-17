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

//Function to return the current value
double currentMathOperations(double first, double second, char op){
    switch (op) {
        case '+':
            return first + second;
        case '-':
            return first - second;
        case '*':
            return first * second;
        case '/':
            return first / second;
        default:
            return 0;
    }
}

//Function to evaluate postfix expression
double evaluateExpression(string str){
    stack<double> s;
    int len = str.size();
    for (int i = 0; i < len; ++i) {
        if (isdigit(str[i])){
            s.push(str[i] - '0');
        } else{
            double x, y;
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            s.push(currentMathOperations(x, y, str[i]));
        }
    }
    return s.top();
}

int main(){
    string s;
    cin >> s;
    printf("%d\n", evaluateExpression(s)); //You can use cout << " " << endl; the same.
    return 0;
}
