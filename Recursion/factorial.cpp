//Factorial of a number 
#include <iostream>
using namespace std;

// Using loop
// Time: O(n), Space: O(1)
long long factorialLoop(int n) {      // long long takes 8 bytes 
    long long fact = 1;

    for (int i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}

// Using recursion
// Time: O(n), Space: O(n) due to recursive call stack
long long factorialRecursion(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorialRecursion(n - 1);
}

// Using tail recursion
// Time: O(n), Space: O(n) normally
// Space can be O(1) if the compiler performs tail-call optimization.
// C++ does not guarantee this optimization.
long long factorialTail(int n, long long fact = 1) { // parameter accumulates the result over the function call
    if (n == 0 || n == 1) {
        return fact;
    }

    return factorialTail(n - 1, fact * n);
}

int main() {
    int n = 5;  // Initialize the number here

    cout << "Factorial using loop = "
         << factorialLoop(n) << endl;

    cout << "Factorial using recursion = "
         << factorialRecursion(n) << endl;

    cout << "Factorial using tail recursion = "
         << factorialTail(n) << endl;

    return 0;
}