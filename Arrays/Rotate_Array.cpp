/*
Problem: Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 
Constraints:
1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105

Link: https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: To rotate the array to the right by k positions, the last k elements
must come to the front while maintaining their order. Instead of shifting elements
one by one, we can use array reversal to achieve the desired arrangement efficiently.

Approach:
1. Compute k = k5n to handle cases when k>n.
2. Reverse the entire array.
3. Reverse the first k elements.
4. Reverse the remaining n-k elements.
5. The array is now rotated k positions to the right.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    OptimalSolution obj;
    obj.rotate(nums, k);

    for(int num : nums) {
        cout << num << " ";
    }

    return 0;
}