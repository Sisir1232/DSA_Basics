// Problem: Sort 0s, 1s and 2s (Dutch National Flag)
          // in a given array of elements 0 ,1 and 2 ,in place sort the array with optimized solution 

// Approach 1: Counting       -> Time O(n), Space O(1), two passes
// Approach 2: Three pointers -> Time O(n), Space O(1), one pass

#include <iostream>
#include <algorithm>
using namespace std;

// Approach 1: counting
void sortCounting(int nums[], int n) {
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++) {           // pass 1: count the no of 0s, 1s and 2s in respective variable
        if (nums[i] == 0) count0++;
        else if (nums[i] == 1) count1++;
        else count2++;
    }

    int k = 0;                                     // pass 2:
    while (count0 > 0) { nums[k++] = 0; count0--; }// override the array values with 0's as per count variables
    while (count1 > 0) { nums[k++] = 1; count1--; }
    while (count2 > 0) { nums[k++] = 2; count2--; }
}

// Approach 2: Dutch National Flag (one pass)
// [0 .. low-1] = 0s, [low .. mid-1] = 1s, [mid .. high] = unknown, [high+1 .. n-1] = 2s
void sortDutchFlag(int nums[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);     // put the 0 in the 0 zone
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;                          // already in the right zone
        } else {                            // nums[mid] == 2
            swap(nums[mid], nums[high]);    // send the 2 to the 2 zone
            high--;                         // do not move mid: the swapped-in element is unchecked
        }
    }
}

void printArray(int nums[], int n) {
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {2, 0, 2, 1, 1, 0};
    int b[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(a) / sizeof(a[0]);

    sortCounting(a, n);
    cout << "Counting:  ";
    printArray(a, n);

    sortDutchFlag(b, n);
    cout << "Dutch flag: ";
    printArray(b, n);

    return 0;
}