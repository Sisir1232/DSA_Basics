
#include <iostream>
using namespace std;

// Using loop
// Time: O(n), Space: O(1)
int sumLoop(int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    return sum;
}

// Using recursion
// Time: O(n), Space: O(n) due to recursive call stack
int sumRecursion(int n) {
    if (n == 0) {
        return 0;
    }

    return n + sumRecursion(n - 1);
}

// Using tail recursion
// Time: O(n), Space: O(n) normally
int sumTail(int n, int sum = 0) {
    if (n == 0) {
        return sum;
    }

    return sumTail(n - 1, sum + n);
}

int main() {
    int n = 5;  // Initialize the number here

    cout << "Sum using loop = " << sumLoop(n) << endl;
    cout << "Sum using recursion = " << sumRecursion(n) << endl;
    cout << "Sum using tail recursion = " << sumTail(n) << endl;

    return 0;
}
