// Problem: First Non-Repeating Character in a Stream
// Approach 1: Brute force
//             After every character, recount the prefix and scan it from the start.
//             Time O(n^2), Space O(1) (count array of 26)
// Approach 2: Queue of candidates + count array
//             The queue holds letters seen once so far, in arrival order.
//             A letter that repeats is removed lazily, only when it reaches the front.
//             Time O(n) (each letter is pushed once and popped at most once), Space O(1)

#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Approach 1: brute force
void firstNonRepeatingBrute(string stream) {
    int n = stream.length();

    for (int i = 0; i < n; i++) {
        int count[26] = {0};

        for (int j = 0; j <= i; j++) {
            count[stream[j] - 'a']++;
        }

        char answer = '#';
        for (int j = 0; j <= i; j++) {
            if (count[stream[j] - 'a'] == 1) {
                answer = stream[j];
                break;
            }
        }

        cout << answer << " ";
    }
    cout << endl;
}

// Approach 2: queue
void firstNonRepeatingQueue(string stream) {
    int count[26] = {0};
    queue<char> q;                              // letters seen exactly once so far, in arrival order

    for (int i = 0; i < (int)stream.length(); i++) {
        char ch = stream[i];
        count[ch - 'a']++;

        if (count[ch - 'a'] == 1) {
            q.push(ch);                         // first time we see this letter: it is a candidate
        }

        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();                            // the front has repeated: it can never be the answer
        }

        if (q.empty()) {
            cout << "# ";
        }
        else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string stream = "abcab";

    cout << "Brute force: ";
    firstNonRepeatingBrute(stream);

    cout << "Queue:       ";
    firstNonRepeatingQueue(stream);

    return 0;
}