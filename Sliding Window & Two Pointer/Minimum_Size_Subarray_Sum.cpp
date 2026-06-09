/*
Problem: Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 
Constraints:
1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104

Link: https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: Since all the elements are positive, we can use a sliding window.
Expand the window by moving the right pointer and keep adding elements to the 
current sum. Whenever the sum becomes greater than or equal to target,try to
shrink the window from the left while maintaining the condition. This helps 
us to find the minimum-length valid subarray.

Approach:
1. Initialize 2 pointers: left and right.
2. Expand the window by moving right and adding nums[right] to sum.
3. While sum>=target:
    - Update the minimum length.
    - Remove nums[left] from sum.
    - Move left forward to shrink the window.
4. If no valid subarray if found, return 0; otherwise return minimum length found.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int length = INT_MAX;

        for(int right=0; right<n; right++){
            sum += nums[right];
            
            while(sum >= target){
                length = min(length, right-left+1);
                sum -= nums[left];
                left++;
            }
        }

        return (length==INT_MAX) ? 0 : length;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    OptimalSolution obj;

    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << "Minimum Length Subarray = "
         << obj.minSubArrayLen(target, nums) << endl;
    
    return 0;
}