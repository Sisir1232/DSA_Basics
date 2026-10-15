// Postfix Evaluation: Given expression is posfix , you should find the answer of the exp 
// Key insight: Upon getting the each operator from left to right scan , use the operation upon recent two operands
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> s;

    for (char ch : exp) {
        if (isdigit(ch)) {
            // Digit characters have consecutive ASCII values.
            // Subtracting '0' converts the character into its integer value.
            // Example: '7' - '0' = 7
            s.push(ch - '0');
        }
        else {
            // First popped value is the RIGHT operand
            int b = s.top();
            s.pop();

            // Second popped value is the LEFT operand
            int a = s.top();
            s.pop();

            // Perform the operation and push the result
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }

    return s.top(); // Final stack value is the answer
}

int main() {
    string exp = "23+4*";

    cout << "Postfix: " << exp << endl;
    cout << "Result: " << evaluatePostfix(exp) << endl;

    return 0;
}

