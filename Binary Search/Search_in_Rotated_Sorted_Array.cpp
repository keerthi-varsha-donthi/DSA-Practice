/*
Problem: There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
 
Constraints:
1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104

Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Better Approach ----------------

/*
Intuition: A rotated sorted array consists of 2 individually sorted parts. By first finding the pivot(the index of the smallest element), we can determine which sorted half may contain the target and then apply a standard binary search on that half.

Approach:
1. Find the pivot(smallest element) using bianry search.
2. Determine whether the target lies in the left sorted half or the right sorted half.
3. Perform a standard binary search on the appropriate half.
4. Return the target index if found, otherwise return -1.

Time Complexity: O(log n)+O(log n) = O(log n)

Space Complexity: O(1)
*/

class BetterSolution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left=0;
        int right=nums.size()-1;
        int pivot = 0;
        
        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]>nums[right]) left = mid+1;
            else right = mid;
        }
        pivot = left;

        //right half
        if(nums[pivot]<=target && nums[n-1]>=target){
            left = pivot;
            right = n-1;
        }
        //left half
        else{
            left = 0;
            right = pivot-1;
        }
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: In a rotated sorted array, atleast one half of the current search space is always sorted. By identifying the sorted half and checking whether the target lies within its range, we can discard half of the search space in each iteration.

Approach:
1. Apply binary search on the entire array.
2. Check if the left half or right half is sorted.
3. If the target lies inside the sorted half, search there.
4. Otherwise, search in the other half.
5. Continue until the target is found or the search space becomes empty.

Time Complexity: O(log n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left<=right){
            int mid = left+(right-left)/2;

            if(nums[mid]==target) return mid;

            if(nums[left]<=nums[mid]){
                if(nums[mid]>target && target>=nums[left]) right=mid-1;
                else left=mid+1;
            }else{
                if(nums[mid]<target && target<=nums[right]) left=mid+1;
                else right=mid-1;
            }
        }
        return -1;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    BetterSolution better;
    OptimalSolution optimal;

    cout << "Better: "<< better.search(nums, target) << endl;

    cout << "Optimal: "<< optimal.search(nums, target) << endl;

    return 0;
}