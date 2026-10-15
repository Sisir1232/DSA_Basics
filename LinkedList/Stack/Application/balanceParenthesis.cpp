// Balanced parenthesis checking 
// key insight: almost like pallindrome checking, instead of comparing same characters , we check corresponding bracket 

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string str) {
    stack<char> s;

    for (char  ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return false;
            }

            if ((ch == ')' && s.top() != '(') ||
                (ch == '}' && s.top() != '{') ||
                (ch == ']' && s.top() != '[')) {
                return false;
            }

            s.pop();
        }
    }

    return s.empty();
}
//  char  | ASCII CODE 
//  (     | 40
//  )     | 41
//  {     | 91
//  }     | 93
//  [     | 123
//  ]     | 125

// the difference between corresponding brackets are always 1 or 2 

bool isBalancedAsci(string str) {
    stack<char> s;

    for (char  ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return false;
            }

            if (ch-s.top()==1||ch-s.top()==2) {       
                s.pop();
            }
            else{
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    string str1 = "{[()]}";
    string str2 = "{[(])}";

    cout << str1 << ": "
         << (isBalanced(str1) ? "Balanced" : "Not Balanced") << endl;

    cout << str2 << ": "
         << (isBalanced(str2) ? "Balanced" : "Not Balanced") << endl;
    cout << str1 << ": "
         << (isBalancedAsci(str1) ? "Balanced" : "Not Balanced") << endl;

    cout << str2 << ": "
         << (isBalancedAsci(str2) ? "Balanced" : "Not Balanced") << endl;
      

    return 0;
}