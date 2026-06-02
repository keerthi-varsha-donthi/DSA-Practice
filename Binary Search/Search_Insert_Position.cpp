/*
Problem: Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
 
Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

Link: https://leetcode.com/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------

/*
Intuition: The insertion position is the first index where the element is greater than or equal to the target. We can find either target itself or the position where it should be inserted.

Approach:
1. Traverse the array from the beginning.
2. If nums[i]>=target, return i.
3. If no such element exists, the target should be inserted at the end of the array, so return nums.size().

Time Complexity: O(n)
Space Complexity: O(1)
*/

class BruteForceSolution {
public:
    int searchInsert(vector<int>& nums, int target){
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=target) return i;
        }
        return nums.size();
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: Since array is sorted, binary search can be used to efficiently locate the target or determine its correct insertion position. When the target is not found, the left pointer will indicate the index where the target should ne inserted.

Approach:
1. Initialize 2 pointers: left=0, and right = nums.size()-1.
2. Perform binary search:
   -If nums[mid]==target, return mid.
   -If target<nums[mid], move the right pointer to mid-1.
   -Else, move the left pointer to mid+1.
3. When the loop ends, left represents the insertion position.
4. Return left.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int searchInsert(vector<int>& nums, int target){
        int left=0;
        int right=nums.size()-1;

        while(left<=right){
            int mid = ((right-left)/2)+left;
            if(nums[mid]==target) return mid;
            if(target<nums[mid]) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    BruteForceSolution brute;
    OptimalSolution optimal;

    cout << "Brute Force: "<< brute.searchInsert(nums, target) << endl;

    cout << "Optimal: "<< optimal.searchInsert(nums, target) << endl;
    return 0;
}