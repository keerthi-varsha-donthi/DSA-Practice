/*
Problem: Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 
Constraints:
1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.

Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;



// ---------------- Optimal Approach ----------------

/*
Intuition: Since the array is sorted, duplicates always appear consecutively.
Keep only the first occurence of each element and overwrite duplicate positions
with the next unique element.

Approach:
1. Initialize l = 1 since the first element is always unique.
2. Traverse the array using r from index 1.
3. If nums[r] differs from nums[r-1], it is a new unique element:
    - Place it at nums[i].
    - Increment l.
4. Return l, which represents the number of unique elements.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1;
        for(int r=1; r<nums.size(); r++){
            if(nums[r-1] != nums[r]){
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    OptimalSolution obj;

    int k = obj.removeDuplicates(nums);

    cout << "k = " << k << endl;

    cout << "Array: ";
    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    
    return 0;
}