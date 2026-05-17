/*
Problem: Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:
-231 <= x <= 231 - 1

Link:https://leetcode.com/problems/palindrome-number/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: A palindrome number remains the same when reversed. So we reverse the given number mathematically and compare it with the original number.

Approach: 
- Negative numbers are never palindrome
- Store original number in another variable 
- Reverse the number by extracting digits and building the reversed number
- Compare reversed number with original number

Time Complexity: O(log10(x)) where x is the input number

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    bool isPalindrome(int x){
        if(x<0) return false;

        int num = x;
        long long rev = 0;

        while(num){
            rev = rev*10 + num%10;
            num /= 10;
        }
        return rev == x;
    }
};

// ========================================================
//                         Main
// ========================================================

int main() {
    int x;
    cin>>x;

    OptimalSolution optimal;
    bool result = optimal.isPalindrome(x);

    if(result) cout<<"true"<<endl;
    else cout<<"false"<<endl;

    return 0;
}