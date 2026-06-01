/*
Problem: Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

Example 1:
Input: n = 11
Output: 3
Explanation: The input binary string 1011 has a total of three set bits.

Example 2:
Input: n = 128
Output: 1
Explanation: The input binary string 10000000 has a total of one set bit.

Example 3:
Input: n = 2147483645
Output: 30
Explanation: The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

Constraints: 1 <= n <= 2^31 - 1

Link: https://leetcode.com/problems/number-of-1-bits/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;



// ---------------- Optimal Approach ----------------

/*
Intuition: A number is represented using 32 bits. By checking each bit position, we can determine whether it is set or not. Counting all the set bits gives the Hamming Weight of the number.

Approach:
1. Initialize ans=0.
2. Iterate through all 32 bit positions.
3. For each position, right-shift the number and check the least significant bit using '& 1'.
4. If the bit is set, increment the counter.
5. Return the final count.

Time Complexity: O(32)=O(1)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int hammingWeight(int n){
        int ans =0;
        for(int bits=0; bits<32; bits++){
            if((n>>bits)&1) ans++;
        }
        return ans;
    }

};


// ========================================================
//                         Main
// ========================================================

int main() {

    
    return 0;
}