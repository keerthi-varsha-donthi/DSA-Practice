/*
Problem: Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
 
Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
The input is generated such that a majority element will exist in the array.

Link: https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;



// ---------------- Better Approach ----------------

/*
Intuition: After sorting the array, all occurences of the same element become
adjacent. We can then count the frequency of each element and return the one 
whose frequency exceeds n/2.

Approach:
1. Sort the array.
2. Traverse the sorted array.
3. Count consecutive occurences of each element.
4. If the frequency of an element is greater than n/2, return that element.

Time Complexity: O(n log n)

Space Complexity: O(1)
*/

class BetterSolution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = nums.size()/2;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            int maxi = 0;
            int num = nums[i];
            while(i<nums.size() && nums[i]==num){
                i++;
                maxi++;
            } 
            if(maxi>cnt) return num;
            i--;
        }
        return -1;
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: If an element appears more than n/2 times, it cannot be completely 
cancelled out by all other elements combined. We maintain a candidate and a 
count. Whenever we encounter the same element as the candidate, we increment
the count; otherwise we decrement it. The remaining candidate at the end will
be majority element.

Approach:
1. Initialize count = 0.
2. Traverse the array:
    - If count becomes 0, choose the current element as the new candidate.
    - If the current element equals the candidate, increment count.
    - Otherwise, decrement count.
3. Return the final candidate.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for(int i=0; i<nums.size(); i++){
            if(count == 0) candidate = nums[i];

            if(nums[i] == candidate) count++;
            else count--;
        }

        return candidate;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    OptimalSolution obj;
    cout << "Majority Element: " << obj.majorityElement(nums) << endl;
    
    return 0;
}