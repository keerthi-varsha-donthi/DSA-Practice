/*
Problem: You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:
-> 0 <= j <= nums[i] and
-> i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2

Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].

Link: https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: Instead of deciding the next jump immediately, we explore all
indices that can be reached with the current number of jumps. While 
exploring this range, we keep track of the farthest index that can be 
reached. Once we reach the end of the current range, we must take another 
jump and extend the range to the farthest reachable index.

Approach:
1. Maintain:
   - jumps: Number of jumps taken.
   - coverage: Farthest index reachable from the current range.
   - lastIdx: End of the current reachable range.
2. Traverse the array up to n-2 (no need to jump from the last index).
3. Update coverage = max(coverage, i + nums[i]).
4. If i reaches lastIdx:
   - Increment jumps.
   - Update lastIdx = coverage.
5. Return jumps.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int coverage = 0;
        int lastIdx = 0;

        for(int i=0; i<nums.size()-1; i++){

            coverage = max(coverage, i+nums[i]);

            if(i==lastIdx){
                jumps++;
                lastIdx = coverage;
            }
        }

        return jumps;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {2, 3, 1, 1, 4};

    OptimalSolution obj;

    cout << "Minimum Jumps: "
         << obj.jump(nums) << endl;
    
    return 0;
}