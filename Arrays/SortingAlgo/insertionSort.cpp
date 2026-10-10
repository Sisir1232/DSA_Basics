#include <iostream>
using namespace std;

// mimics the concept of inserting the data in a array while preserving the order 
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // during shifting the data are gonna change which corrupts the original i indexed value 
        int j = i - 1;

        // Shift larger elements one step to the right
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key in its correct position
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    insertionSort(arr, n);

    cout << "After:  ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
// Algorithm Analysis: 
// Time complexity: Bestcase:O(n) Averagecase:O(n2) WorstcaseO(n2)
// Space complexity: O(1) (inplace sorting)
// adaptive because once the condition  (j >= 0 && arr[j] > key) fails , it won't go further 
// stable because the swapping doesn't happen in equal condition and adjacent swap only unlike selection
// particular pass does not give any sorted element