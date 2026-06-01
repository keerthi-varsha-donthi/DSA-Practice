/*
Problem:Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0
 

Constraints: 0 <= left <= right <= 231 - 1

Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------

/*
Intuition: The problem asks for the bitwise AND of all numbers in the range [left, right]. A straightforward approach is to start with left and continously AND it with every number from left+1 to right. The final value obtained is the answer.

Approach:
1. Initialize ans = left.
2. Iterate from left+1 to right, and update ans = ans&current_number.
3. Return ans after the loop ends.

Time Complexity: O(right - left)
We perform one AND operation for every number in the range.

Space Complexity: O(1)
We only use a constant amount of extra space.
*/

class BruteForceSolution {
public:
    int rangeBitwiseAnd(int left, int right){
        int ans = left;
        for(int i=left+1; i<=right; i++){
            ans = ans&i;
        }
        return ans;
    }
};




// ---------------- Better Approach ----------------

/*
Intuition: Any bit that changes within the range [left, right] cannot remain 1 in the final AND result. We repeatedly remove the rightmost set bit from right, eliminating bits that are guaranteed to become 0 in the answer. This process continues until right is less than or equal to left, at which point all bits that could differ have been removed.

Approach: 
1. While left<right:
    - remove the rightmost set bit of right using right = right&(right-1).
2. Return right.

Time Complexity: O(number of set bits removed)
At most O(32) for a 32-bit integer, i.e., O(1).

Space Complexity: O(1)
*/

class BetterSolution {
public:
    int rangeBitwiseAnd(int left, int right){
        while(left<right){
            right = right&(right-1);
        }
        return right;
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: The AND of all numbers in a range keeps only the common leading bits of left and right. All bits after the differing bit become 0.

Approach:
1. Right-shift both left and right until they become equal.
2. Count the number of shifts performed.
3. Left-shift the common prefix back by the same count.
4. Return the result.

Time Complexity: O(32)=O(1)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int rangeBitwiseAnd(int left, int right){
        int shift= 0;
        while(left != right){
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }

};


// ========================================================
//                         Main
// ========================================================

int main() {

    int left, right;
    cin>>left>>right;

    BruteForceSolution brute;
    BetterSolution better;
    OptimalSolution optimal;

    cout << "Brute Force: "<< brute.rangeBitwiseAnd(left, right) << endl;
    cout << "Better: "<< better.rangeBitwiseAnd(left, right) << endl;
    cout << "Optimal: "<< optimal.rangeBitwiseAnd(left, right) << endl;

    return 0;
}