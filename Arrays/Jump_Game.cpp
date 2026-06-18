/*
Problem: You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 105

Link: https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: From each index, we can jump upto nums[i] positions ahead. Instead
of checking every possible path, we keep track of the farthest index that can
be reached so far. If we encounter an index beyond this reachable range, reaching
the end is impossible.

Approach:
1. Initialize 'farthest' as the maximum index reachable from the first position.
2. Traverse the array from index 1.
3. If the current index is greater that 'farthest', return false because the 
   current position cannot be reached.
4. Update 'farthest' as:
    max(farthest, i+nums[i])
5. If the traversal completes, return true.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = nums[0];

        for(int i=1; i<nums.size(); i++){
            if(i>farthest) return false;

            farthest = max(i + nums[i], farthest);
        }

        return true;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {2, 3, 1, 1, 4};

    OptimalSolution obj;

    cout << boolalpha << obj.canJump(nums) << endl;
    
    return 0;
}