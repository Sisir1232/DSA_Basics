#include <iostream>
using namespace std;

// Find the maximum value to know the number of digits
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) mx = arr[i];
    }
    return mx;
}

// Stable counting sort on the digit at place value exp (1, 10, 100, ...)
void countingSortByDigit(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Convert counts to ending positions
    for (int d = 1; d < 10; d++) {
        count[d] += count[d - 1];
    }

    // Build output from right to left to keep the sort stable
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[--count[digit]] = arr[i];
    }

    // Copy back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int mx = getMax(arr, n);

    // Sort by each digit, starting from the least significant
    for (int exp = 1; mx / exp > 0; exp *= 10) {
        countingSortByDigit(arr, n, exp);
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    radixSort(arr, n);

    cout << "After:  ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}