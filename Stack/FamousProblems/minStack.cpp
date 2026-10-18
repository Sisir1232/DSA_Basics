// Problem: Min Stack (push, pop, top, getMin)
// Approach 1: Brute force (not implemented)
//             Keep a normal stack and, in getMin(), traverse the whole stack to find the smallest.
//             push/pop/top O(1), getMin O(n), Space O(1) 

// Approach 2: Stack of pairs (value, minimum so far)
//             all operations O(1), Space O(n)

#include <iostream>
#include <stack>
using namespace std;

// Approach 2: one stack of pairs
class MinStack {
    stack<pair<int, int>> st;               // first = value, second = min of the stack up to here

public:
    void push(int x) {
        if (st.empty() || x < st.top().second) {   //second for second stack of a pair 
            st.push({x, x});
        }
        else {
            st.push({x, st.top().second});  // keep the old minimum
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

int main() {
    MinStack s;

    s.push(5);
    s.push(3);
    s.push(7);
    cout << "getMin: " << s.getMin() << endl;             // 3

    s.pop();                                              // removes 7
    cout << "getMin after pop: " << s.getMin() << endl;   // 3

    s.pop();                                              // removes 3
    cout << "getMin after pop: " << s.getMin() << endl;   // 5
    cout << "top: " << s.top() << endl;                   // 5

    return 0;
}