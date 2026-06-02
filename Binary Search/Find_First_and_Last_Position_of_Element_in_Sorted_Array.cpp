/*
Problem: Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: Since the array is sorted, bianry search can be used to efficiently find the first and last occurence of the target. Instead of stopping when the target is found, continue searching towards the left for the first occurence and to right for the last occurence.

Approach:
1. Use bianry search to find the first occurence: when target is found, store the index and continue searching left.
2. Use another bianry search to find the last occurence: when target is found, store the index and continue searching right.
3. Return both indices as the answer.
4. If the target is not present, both searches return -1.

Time Complexity: O(log n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int firstOccurence(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        int ans = -1;
        while(left<=right){
            int mid = left+(right-left)/2;

            if(nums[mid]==target){ 
                ans = mid;
                right = mid-1;
            }else if(nums[mid]>target) right = mid-1;
            else left = mid+1;
        }
        return ans;
    };
    int lastOccurence(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        int ans = -1;
        while(left<=right){
            int mid = left+(right-left)/2;

            if(nums[mid]==target){ 
                ans = mid;
                left = mid+1;
            }else if(nums[mid]>target) right = mid-1;
            else left = mid+1;
        }
        return ans;
    };

    vector<int> searchRange(vector<int>& nums, int target) {
        return{firstOccurence(nums, target), lastOccurence(nums, target)};
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    OptimalSolution obj;

    vector<int> ans = obj.searchRange(nums, target);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
    
    return 0;
}