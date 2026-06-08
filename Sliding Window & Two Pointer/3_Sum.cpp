/*
Problem: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:
3 <= nums.length <= 3000
-105 <= nums[i] <= 105

Link: https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Optimal Approach ----------------

/*
Intuition: A triplet sums to zero if, after fixing one element, we can find 2
other elements whose sum equals the negative of the fixed element. After sorting
the array, we can efficiently find such pairs using the 2-pointer technique
while avoiding duplicate triplets.

Approach:
1. Sort the array.
2. Iterate through the array and fix nums[i] as the first element of the triplets.
3. Skip duplicate values of nums[i] to avoid repeated triplets.
4. Use 2 pointers: left=i+1, right=n-1
5. Calculate the sum of nums[i], nums[left] and nums[right].
    - If sum==0, store the triplet and move both pointers.
    - Skip duplicate values at left and right.
    - If sum<0, move left to increase the sum.
    - if sum>0, move right to decrease the sum.
6. Continue until left>=right.
7. Return all unique triplets.

Time Complexity: O(n log n) + O(n²) = O(n^2)

Space Complexity: O91
*/

class OptimalSolution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for(int i=0; i<n-2; i++){
            if(nums[i] > 0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;

            int left = i+1;
            int right = n-1;
            while(left<right){
                long long sum = (long long)nums[i]+nums[left]+nums[right];
                if(sum == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }else if(sum<0) left++;
                else right--;
            }
        }
        return ans;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    OptimalSolution obj;
    vector<vector<int>> ans = obj.threeSum(nums);

    for (auto &triplet : ans) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i != triplet.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}