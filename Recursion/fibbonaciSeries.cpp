
#include <iostream>
using namespace std;

// 1. Using loop
// Time: O(n), Space: O(1)
void fibonacciLoop(int n) {
    int first = 0, second = 1;

    for (int i = 0; i < n; i++) {
        cout << first << " ";

        int sum = first + second;
        first = second;
        second = sum;
    }

    cout << endl;
}

// 2. Using recursion
// Time: O(2^n) for calculating the largest term
// Space: O(n) due to recursive call stack
int fibonacciRecursion(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacciRecursion(n - 1)
         + fibonacciRecursion(n - 2);
}

void printRecursion(int n) {
    for (int i = 0; i < n; i++) {
        cout << fibonacciRecursion(i) << " ";
    }

    cout << endl;
}

// 3. Using tail recursion
// Time: O(n), Space: O(n) normally
void fibonacciTail(int n, int first = 0, int second = 1) {
    if (n == 0) {
        cout << endl;
        return;
    }

    cout << first << " ";

    int sum = first + second;
    fibonacciTail(n - 1, second, sum);
}

int main() {
    int n = 10;  // Number of terms

    cout << "Using loop: ";
    fibonacciLoop(n);

    cout << "Using recursion: ";
    printRecursion(n);

    cout << "Using tail recursion: ";
    fibonacciTail(n);

    return 0;
}
