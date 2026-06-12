/*
Problem: Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false

Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

Link: https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;



// ---------------- Optimal Approach ----------------

/*
Intuition: If a duplicate numbers appears within a distance of k indices, 
then while traversing the array we only need to know the most recent index 
at which each number was seen.

Approach:
1. Use a hash map to store each number and its latest index.
2. Traverse the array.
3. For the current number:
   - If it already exists in the map, calculate the difference between the 
     current index and its previously stored index.
   - If the difference is less than or equal to k, return true.
4. Update the number's index in the map to the current index.
5. If no valid duplicate is found, return false.

Time Complexity: O(n)

Space Complexity: O(n)
*/

class OptimalSolution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            int num = nums[i];

            if(mp.count(num) && abs(i-mp[num]) <= k) return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    OptimalSolution obj;

    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    cout << (obj.containsNearbyDuplicate(nums, k) ? "true" : "false") << endl;
    
    return 0;
}