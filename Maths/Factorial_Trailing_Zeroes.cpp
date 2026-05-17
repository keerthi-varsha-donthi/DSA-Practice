/*
Problem: Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

Example 1:
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Example 3:
Input: n = 0
Output: 0 
 

Constraints:
0 <= n <= 104

Link: https://leetcode.com/problems/factorial-trailing-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Better Approach ----------------

/*
Intuition: A trailing zero is created with multiples of 10, and 10 is made of 2 and 5. In n!, there are usually more factors of 2 than 5, so we can count the number of times 5 is a factor in the numbers from 1 to n.

Approach: 
- Traverse through all numbers from 1 to n
- Check whether a number is divisible by 5
- If yes, repeatedly divide it by 5
- Count how many times division by 5 is possible
- The final count gives the number of trailing zeroes

Time Complexity: O(nlogn)

Space Complexity: O(1)
*/

class BetterSolution {
public:
    int trailingZeroes(int n){
        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(i%5 == 0){
                int num = i;
                while(num%5 == 0){
                    cnt++;
                    num /= 5;
                }
            }
        }
        return cnt;
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: Instead of checking every number individually, we can directly count how many multiples of 5, 25, 125, etc. are present in n!.
Each multiple of 5 contributes at least one factor of 5.
Multiples of 25 contribute one extra factor of 5.
Multiples of 125 contribute another extra factor of 5, and so on.

Approach:
- Count multiples of 5 using n/5
- Count extra factors of 5 usign n/25
- Continue similarly for powers of 5
- Add all counts together

Time Complexity: O(log5(n))

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int trailingZeroes(int n){
        int cnt = 0;
        for(int i=5; i<=n; i*=5){
            cnt += n/i;
        }
        return cnt;
    }
};

// ========================================================
//                         Main
// ========================================================

int main() {
    int n;
    cin>>n;

    BetterSolution better;
    int betterResult = better.trailingZeroes(n);

    OptimalSolution optimal;
    int optimalResult = optimal.trailingZeroes(n);

    return 0;
}