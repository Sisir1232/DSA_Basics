// Problem: Generate Binary Numbers from 1 to N
// Approach 1: Convert each number separately (repeated division by 2)
//             Time O(N log N), Space O(log N) per number
// Approach 2: Queue, build each number from an earlier one
//             take the front, print it, then add front + "0" and front + "1" at the back
//             Time O(N * log N) for building the strings (O(N) queue operations), Space O(N)

#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Approach 1: brute force
void generateBrute(int n) {
    for (int i = 1; i <= n; i++) {
        int num = i;
        string bin = "";

        while (num > 0) {
            bin = char('0' + num % 2) + bin;    // remainder is the next bit, added at the front
            num = num / 2;                      // added '0' to convert the integer into asci string
        }

        cout << bin << " ";
    }
    cout << endl;
}

// Approach 2: queue
void generateQueue(int n) {
    queue<string> q;
    q.push("1");                                // the only number placed by hand

    for (int i = 0; i < n; i++) {
        string cur = q.front();
        q.pop();

        cout << cur << " ";

        q.push(cur + "0");                      // children wait behind everything already in line
        q.push(cur + "1");
    }
    cout << endl;
}

int main() {
    int n = 5;

    cout << "Brute force: ";
    generateBrute(n);

    cout << "Queue:       ";
    generateQueue(n);

    return 0;
}