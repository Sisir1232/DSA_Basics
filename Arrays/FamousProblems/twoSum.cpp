// Problem: Two Sum
         // From the given array you need to find the two numbers whose sum is equal to the target 
         // input conditions : there is only one pair of indices that satisfies the target sum 
         // output: you need to find the two indices which solves the problem 

// Approach 1: Brute force  -> Time O(n^2), Space O(1)
// Approach 2: Hash map     -> Time O(n),   Space O(n)

#include <iostream>
#include <unordered_map>
using namespace std;

// Approach 1: brute force
void twoSumBrute(int nums[], int n, int target) {
    for (int i = 0; i < n; i++) {               //for a particular data of array 
        for (int j = i + 1; j < n; j++) {       // check whether the target sum is satisfied with other data members one by one 
            if (nums[i] + nums[j] == target) {
                cout << "Indices: " << i << " " << j << endl;
                return;
            }
        }
    }
    cout << "No pair found" << endl;
}

// Approach 2: hash map (number -> index)   
void twoSumHash(int nums[], int n, int target) {    // the key insight is hashmap gives the value  of given key in O(1)
    unordered_map<int, int> seen;
    for (int i = 0; i < n; i++) {     // so for  particular data members ,we can get the indices of data which satisfies target sum 
        int needed = target - nums[i];

        if (seen.count(needed) == 1) {       // count gives 1 if that unique key exist in the hashmap otherwise 0
            cout << "Indices: " << seen[needed] << " " << i << endl;
            return;
        }

        seen[nums[i]] = i;                      // insert AFTER the check
    }
    cout << "No pair found" << endl;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int n = sizeof(nums) / sizeof(nums[0]);     // array size, computed here
    int target = 9;

    cout << "Brute force: ";
    twoSumBrute(nums, n, target);

    cout << "Hash map:    ";
    twoSumHash(nums, n, target);

    return 0;
}