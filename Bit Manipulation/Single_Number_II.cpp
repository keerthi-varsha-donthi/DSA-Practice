/*
Problem: Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.

Link: https://leetcode.com/problems/single-number-ii/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------

/*
Intuition: Since every element appears three times except one, we check each element and count how many times it occurs in the array. The element with frequency 1 is the required answer.

Approach:
1. Traverse the array.
2. For each element, count its occurences using another loop.
3. If the count is 1, return that element.

Time Complexity: O(n^2)

Space Complexity:O(1)
*/

class BruteForceSolution {
public:
    int singleNumber(vector<int>& nums){
        int ans = 0;
        for (int i=0; i<nums.size(); i++){
            int count = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[i]==nums[j]) count++;
            }
            if(count==1) ans = nums[i];
        }
        return ans;
    }
};




// ---------------- Better Approach ----------------

/*
Intuition: Store the frequency of each element in a hashmap. Since every element appears 3 times except one, the element with frequency 1 is the answer.

Approach:
1. Traverse the array and store the frequencies in an unordered_map.
2. Traverse the map to find the element with frequency 1.
3. Retuen that element.

Time Complexity: O(n)

Space Complexity: O(n)
*/

class BetterSolution {
public:
    int singleNumber(vector<int>& nums){
        unordered_map<int, int> mp;
        for(auto num:nums) mp[num]++;
        for(auto it:mp){
            if(it.second==1) return it.first;
        }
        return -1;
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: Every repeated element contributes its bits exactly 3 times. By counting set bits at each position and taking modulo 3, the contribution from triplets are eliminated. The remaining bits form the number that appears exactly once.

Approach:
1. Iterate through all 32 bit positions.
2. For each bit position, count how many numbers have that bit set.
3. Compute count%3.
4. If the remainder is 1, set that bit in the answer.
5. Return the reconstructed number.

Time Complexity: O(32*nn) = O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int singleNumber(vector<int>& nums){
        int ans=0;
        for(int bits=0; bits<32; bits++){
            int count=0;
            for(auto num:nums){
                if((num>>bits)&1) count++;
            }
            if(count%3) ans |= 1<<bits;
        }
        return ans;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {2, 2, 3, 2};

    BruteForceSolution brute;
    BetterSolution better;
    OptimalSolution optimal;

    cout << "Brute Force: "<< brute.singleNumber(nums) << endl;

    cout << "Better: "<< better.singleNumber(nums) << endl;

    cout << "Optimal: "<< optimal.singleNumber(nums) << endl;

    return 0;
}