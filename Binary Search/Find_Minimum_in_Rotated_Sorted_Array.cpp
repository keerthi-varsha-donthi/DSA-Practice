/*
Problem: Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time. 

Example 1:
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Example 2:
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

Example 3:
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:
n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.

Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: In a rotated sorted array, the minimum element is the pivot point. Using binary search, we can determine whether the minimum lies in the left or right half by comparing nums[mid] with the last element of the array.

Approach:
1. Initialize 2 pointers: left=0 and right=n-1.
2. Compute mid.
3. If nums[mid]>nums[n-1], the minimum lies in the right half, so move left=mid+1.
4. Otherwise, the minimum lies at mid or in the left half, so move right=mid.
5. Continue until left==right.
6. Return nums[left], which is the minimum element.

Time Complexity: O(log n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]>nums[n-1]) left = mid+1;
            else right = mid;
        }
        return nums[left];
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    OptimalSolution obj;

    cout << "Minimum Element: "<< obj.findMin(nums) << endl;

    return 0;
}