/*
Problem: Reverse bits of a given 32 bits signed integer.

Example 1:
Input: n = 43261596
Output: 964176192
Explanation:
Integer	    Binary
43261596	00000010100101000001111010011100
964176192	00111001011110000010100101000000

Example 2:
Input: n = 2147483644
Output: 1073741822
Explanation:
Integer	    Binary
2147483644	01111111111111111111111111111100
1073741822	00111111111111111111111111111110
 
Constraints:
0 <= n <= 231 - 2
n is even.

Link: https://leetcode.com/problems/reverse-bits/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: To reverse the bits of a number, we process its bits from right to left. At each step, we extract the least significant bit(LSB) of the original number and append it to the result. By repeatedly shifting the result left and the number right, we build the reversed bit sequence.

Approach:
1. Initialize ans = 0.
2. Repeat 32 times:
    - Shift ans left by 1 to make space for the next bit.
    - Extract the LSB of n using (n&1).
    - Add this bit to ans using OR.
    - Shift n right by 1.
3. Return ans.

Time Complexity: O(32)=O(1)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int reverseBits(int n){
        int ans=0; 
        for(int bits=0; bits<32; bits++){
            ans <<= 1;
            ans |= (n&1);
            n >>= 1;
        }
        return ans;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    int n; 
    cin>>n; 

    OptimalSolution obj;
    cout<<"Reversed Bits Value: "<<obj.reverseBits(n)<<endl;
    
    return 0;
}