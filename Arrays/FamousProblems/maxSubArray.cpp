// Problem: Maximum Subarray
         // in a given array of integers , you have to find the contiguous subarray having maximum sum 
        // input: given array of +ve and -ve integers 
        // output: maximum contiguous sum and the subarray 

// Approach 1: Brute force      -> Time O(n2), Space O(1)
// Approach 2: Kadane's         -> Time O(n),   Space O(1)

#include <iostream>
using namespace std;

// Approach 1: brute force
void maxSubarrayBrute(int nums[], int n) {
    int best = nums[0];                 // initialize first element as maximum 
    int bestStart = 0, bestEnd = 0;

    for (int i = 0; i < n; i++) {       // i = start of subarray
        int sum = 0;
        for (int j = i; j < n; j++) {   // j = end of subarray
            sum += nums[j];             // extend by one element: in sub array starting from num
            if (sum > best) {           // add elements from right one by one 
                best = sum;
                bestStart = i;           // if it is greater than previous subarray , make it new best 
                bestEnd = j;
            }
        }
    }
    cout << "Max sum: " << best << endl;
    cout << "Subarray from index " << bestStart << " to " << bestEnd << endl;
}

// Approach 2: Kadane's algorithm
void maxSubarrayKadane(int nums[], int n) {
    int currentSum = nums[0];           // best sum of a subarray ending at index i
    int best = nums[0];                 // best sum seen anywhere so far
    int tempStart = 0;                  // where the current running subarray began
    int bestStart = 0, bestEnd = 0;

    for (int i = 1; i < n; i++) {
        if (currentSum < 0) {
            currentSum = nums[i];       // starting from -ve sum would reduce the maximum sum 
            tempStart = i;              // a new subarray begins at i
        } else {
            currentSum += nums[i];      // positive: extend the subarray
        }

        if (currentSum > best) {
            best = currentSum;
            bestStart = tempStart;
            bestEnd = i;
        }
    }
    cout << "Max sum: " << best << endl;
    cout << "Subarray from index " << bestStart << " to " << bestEnd << endl;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "Brute force:" << endl;
    maxSubarrayBrute(nums, n);

    cout << "Kadane's:" << endl;
    maxSubarrayKadane(nums, n);

    return 0;
}