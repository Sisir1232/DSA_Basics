#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {    // only works when [left mid] and [mid+1 right] are sorted 
    int i = left, j = mid + 1, k = 0;
    int tempArr[right - left + 1];

    // Merge the two sorted halves into tempArr
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tempArr[k++] = arr[i++];
        } else {
            tempArr[k++] = arr[j++];
        }
    }

    // Copy any remaining elements
    while (i <= mid) tempArr[k++] = arr[i++];
    while (j <= right) tempArr[k++] = arr[j++];

    // Copy back to the original array at the correct offset
    for (int x = 0; x < k; x++) {
        arr[left + x] = tempArr[x];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);       // sort left half
    mergeSort(arr, mid + 1, right);  // sort right half
    merge(arr, left, mid, right);    // merge the two sorted halves
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "After:  ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
// Algorithm Analysis
   // Time complexity: O(n*log2n) All cases 
   // Space complexity:O(n) ( n for tempArr and log2n for stack tree)
   // not adaptive since in best case also there is no improvement in time 
   // stable and preserves the order of equal values element