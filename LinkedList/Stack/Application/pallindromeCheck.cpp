// Pallindrome checking using stack
// Key insight: When the string is inserted into stack char by char AND
            // : later stored the stack content using pop in another string , we get its reversal 
            // : similarly if we compare each of pop with the string characters , we establish pallindrome condition


#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    stack<char> s;

    for (char ch : str) {
        s.push(ch);              // stored string in stack
    }                         
                                  // Time complexity:O(n)             

    for (char ch : str) {
        if (ch != s.top()) {
            return false;          // pallindrome condition
        }
        s.pop();
    }                               // Time complexity:O(n)

    return true;
}                                 // Time complexity:O(n)

int main() {
    string str1 = "MADAM";
    string str2 = "HELLO";

    cout << str1 << ": "
         << (isPalindrome(str1) ? "Palindrome" : "Not Palindrome") << endl;

    cout << str2 << ": "
         << (isPalindrome(str2) ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}