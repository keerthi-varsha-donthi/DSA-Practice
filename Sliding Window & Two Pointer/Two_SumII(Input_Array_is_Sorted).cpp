/*
Problem: Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 
Constraints:
2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000

Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Optimal Approach ----------------

/*
Intuition: Since the array is sorted in non-decreasing order, we can use 2 pointers, 
onne at the beginning and one at the end. Based on the sum of the 2 elements, we can
decide which pointer to move to get closer to the target.

Approach:
1. Initialize 2 pointers: left at index 0, right at index n-1.
2. Compare the sum of numbers[left] and numbers[right].
3. If sum equals the target, return their 1-based indices.
4. If sum is greater than target, move right one step left to reduce the sum.
5. If sum is less than target, move left one step right to increase the sum.
6. Continue until the pair is found.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;

        while(left<right){
            int sum = numbers[left]+numbers[right];
            if(sum==target) break;
            else if(sum>target) right--;
            else left++;
        }
        return {left+1, right+1};
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    OptimalSolution obj;

    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = obj.twoSum(numbers, target);

    cout << ans[0] << " " << ans[1] << endl; // 1 2
    
    return 0;
}