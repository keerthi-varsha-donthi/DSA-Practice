/*
Problem: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

Link: https://leetcode.com/problems/single-number/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------

/*
Intuition: since every element appears twice except one, we can check each element and count how many times it occurs in the array. The element with frequency 1 is the required answer.

Approach:
1. Traverse the array.
2. For each element, count its occurrences using another loop.
3. If the count is 1, return that element.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class BruteForceSolution {
public:
    int singleNumber(vector<int>& nums){
        for(int i=0; i<nums.size(); i++){
            int count = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[i]==nums[j]) count++;
            }
            if(count==1) return nums[i];
        }
        return -1;
    }
};




// ---------------- Better Approach ----------------

/*
Intuition: Instead of counting occurrences repeatedly, store the frequency of each element in a hash map. The element with frequency 1 is the answer.

Approach:
1. Traverse the array and store the frequencies in an unordered_map.
2. Tracerse the array again.
3. Return the element whose freqeuncy is 1.

Time Complexity: O(n)

Space Complexity: O(n)
*/

class BetterSolution {
public:
    int singleNumber(vector<int>& nums){
        unordered_map<int, int> freq;
        for(int num:nums) freq[num]++;
        for(int num:nums){
            if(freq[num]==1) return num;
        }
        return -1;
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: XOR of a number with itself is 0, and XOR of a number with a is the number itself. Since every element appears twice, all duplicate elements cancel each other out, leaving only the single element.

Approach:
1. Initialize ans=0.
2. XOR every element with ans.
3. All pairs cancel out and only the unique element remains.
4. Return ans.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int singleNumber(vector<int>& nums){
        int ans = 0;
        for(auto num:nums) ans = ans^num;
        return ans;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    int n;
    cin>>n; 

    vector<int> nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];

    BruteForceSolution brute;
    BetterSolution better;
    OptimalSolution optimal;

    cout << "Brute Force: "<< brute.singleNumber(nums) << endl;
    cout << "Better: "<< better.singleNumber(nums) << endl;
    cout << "Optimal: "<< optimal.singleNumber(nums) << endl;
    
    return 0;
}