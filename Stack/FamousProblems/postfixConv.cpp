#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int inStack(char ch) {
    if (ch == '+' || ch == '-') return 2;
    if (ch == '*' || ch == '/') return 4;
    if (ch == '^') return 5;
    if (ch == '(') return 0;
    return -1;
}

int outStack(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 3;
    if (ch == '^') return 6;
    if (ch == '(') return 7;
    if (ch == ')') return 0;
    return -1;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        else {
            // Pop operators while their in-stack priority is >= incoming priority
            while (!s.empty() && inStack(s.top()) >= outStack(ch)) {

                // Equal priorities indicate the matching '(' and ')'
                if (inStack(s.top()) == outStack(ch)) {
                    s.pop(); // Discard '('
                    break;
                }

                postfix += s.top();
                s.pop();
            }

            // Never push the closing bracket ')'
            if (ch != ')') {
                s.push(ch);
            }
        }
    }

    // Pop remaining operators into postfix
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix = "A^B^C+(D*E)";

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;

    return 0;
}

// Postix expression is used in the compiler design since using posfix which puts operator after operands
// it can compiled in a single pass without the regards of rule of precedence and associativity
