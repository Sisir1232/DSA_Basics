#include <iostream>
using namespace std;
// three index pointers used : i for particular pass , j for visiting all other members and k for making the smallest element 
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int k= i;

        // Find the smallest element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[k]) {
                k = j;                 // if the value is smaller , k marks it so that it later can be swapped with i 
            }
        }

        // Swap it into position i
        if (k != i) {
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    selectionSort(arr, n);

    cout << "After:  ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}

// Algorithm Analysis
// Time complexity :O(n2) for all cases (not adaptive )
// Space compelxity:O(1) 
// NOT stable because members gets swapped in long jump which may violate the order