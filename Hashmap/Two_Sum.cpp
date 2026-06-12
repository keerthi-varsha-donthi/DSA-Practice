/*
Problem: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

Link: https://leetcode.com/problems/two-sum/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: For each element, check whether its complement(target-current element)
has already been seen. If it has, the current element and the previously seen
element form the required pair.

Approach:
1. Create a hash map to store numbers and their indices.
2. Traverse the array.
3. For each element nums[i], calculate its complement: complement = target-nums[i]
4. Check if the complement exists in the hash map.
   - If yes, return the indices of the complement and the current element.
   - Otherwise, store nums[i] and its index in the map.
5. Since the problem guarantees exactly one solution, a valid pair will be found 
   during traversal.

Time Complexity: O(n)

Space Complexity: O(n)
*/

class OptimalSolution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()){
                return {i, mp[target-nums[i]]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    OptimalSolution obj;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = obj.twoSum(nums, target);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
    
    return 0;
}