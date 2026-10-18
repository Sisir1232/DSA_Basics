// Problem: Next Greater Element
// Approach 1: Brute force            -> Time O(n^2), Space O(1) extra
// Approach 2: Stack, right to left   -> Time O(n),   Space O(n)
//           : from left , check the greater element from top of stack 
#include <iostream>
#include <stack>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// Approach 1: brute force
void nextGreaterBrute(int nums[], int n) {
    int result[100];

    for (int i = 0; i < n; i++) {
        result[i] = -1;                         // default: no greater element found
        for (int j = i + 1; j < n; j++) {
            if (nums[j] > nums[i]) {
                result[i] = nums[j];            // first greater element to the right
                break;                   
            }
        }
    }
    printArray(result, n);
}

// Approach 2: walk from the right; the stack holds VALUES that are still candidates
void nextGreaterStack(int nums[], int n) {
    int result[100];
    stack<int> st;                              // candidates for "next greater", nearest on top

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();                           // too small (or equal): can never be the answer
        }

        if (st.empty()) result[i] = -1;         // nothing greater to the right
        else result[i] = st.top();              // nearest greater element

        st.push(nums[i]);                       // nums[i] is a candidate for the elements on its left
    }
    printArray(result, n);
}

int main() {
    int nums[] = {4, 5, 2, 25};
    int n = sizeof(nums) / sizeof(nums[0]);

    cout << "Brute force: ";
    nextGreaterBrute(nums, n);

    cout << "Stack:       ";
    nextGreaterStack(nums, n);

    return 0;
}