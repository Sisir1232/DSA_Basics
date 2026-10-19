// Tower of Hannoi
// Key insight: Divide and Conquer Approach
           //  : Assume n-1 stacks can be moved from one stack to another 
           //  : our assumption holds true because if we recursively decrease n , when it becomes 1 it is fundamentally true

#include <iostream>
using namespace std;

// Time: O(2^n), Space: O(n) due to recursive call stack
void towerOfHanoi(int n, char source, char auxiliary, char destination, int& steps) {
    if (n == 1) {
        cout << "Move disk 1 from " << source
             << " to " << destination << endl;
        steps++;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary, steps);

    cout << "Move disk " << n << " from " << source
         << " to " << destination << endl;
    steps;

    towerOfHanoi(n - 1, auxiliary, source, destination, steps);
}

int main() {
    int n = 3;  // Number of disks
    int steps = 0;

    towerOfHanoi(n, 'A', 'B', 'C', steps);

    cout << "Total steps = " << steps<< endl;   // 2^n -1

    return 0;
}
