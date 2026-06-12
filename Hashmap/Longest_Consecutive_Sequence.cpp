/*
Problem: Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3
 

Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109

Link: https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;



// ---------------- Better Approach ----------------

/*
Intuition: If the array is sorted, consecutive numbers will appear next to
each other. We can traverse the sorted array and count the length of each 
consecutive sequence. Duplicates are skipped since they do not contribute
to the sequence length.

Approach:
1. Sort the array.
2. Traverse the array from left to right.
3. If the current element is equal to the previous one, skip it.
4. If the current element is exactly one greater than the previosu element, 
   increment the current sequence length.
5. Otherwise, update the answer and start a new sequence.
6. Return the maximum sequence lenth found.

Time Complexity: O(n log n)
                 - Sorting takes O(n log n)
                 - Traversal takes O(n)

Space Complexity: O(1)
*/

class BetterSolution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return nums.size();

        sort(nums.begin(), nums.end());

        int ans = 1;
        int cnt = 1;

        for(int i=1; i<nums.size(); i++){
        
            if(nums[i]==nums[i-1]) continue;
            else if(nums[i]-1 == nums[i-1]) cnt++;
            else{
                ans = max(ans, cnt);
                cnt = 1;
            } 
        }

        return max(ans, cnt);
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: For every number, we only want to start counting a sequence if it is
the first element of that sequence. A number is the start of a sequence if (n-1)
is not present in the set.

Approach:
1. Insert all elements into an unordered_Set.
2. Iterate through each number in the set.
3. If (n-1) is not present, n is the start of a sequence.
4. Keep checking for (n+1), (n+2), ..... in the set and count the sequence length.
5. Update the longest sequence length.
6. Return the maximum length found.

Time Complexity: O(n)

Space Complexity: O(n)
*/

class OptimalSolution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num(nums.begin(), nums.end());
        int longest = 0;

        for(int n : num){

            if(!num.count(n-1)){
                int cnt = 1;
                int currNum = n;

                while(num.count(currNum+1)){
                    cnt++;
                    currNum++;
                }

                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {100, 4, 200, 1, 3, 2};

    OptimalSolution obj;
    cout << obj.longestConsecutive(nums) << endl;
    
    return 0;
}