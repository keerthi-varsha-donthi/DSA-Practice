/*
Problem: Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:
0 <= x <= 231 - 1

Link: https://leetcode.com/problems/sqrtx/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------

/*
Intuition: The square root of a number x is the largest integer n such that n^2 <= x. We can iterate through all integers starting from 1 and check if their squares are less than or equal to x. The last integer that satisfies this condition will be our answer.

Approach: We can use a simple loop to check for each integer i starting from 1 until i^2 is greater than x. We will keep track of the last integer that satisfies the condition i^2 <= x.

Time Complexity: O(sqrt(x))

Space Complexity: O(1)
*/

class BruteForceSolution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;

        int num = 0;
        
        for(int i = 1; i <= x/2; i++) {
           if(x/i == i) num = i;
           else if(x/i < i){
               num = i-1;
               break;
           }
        }
        
        return num;
    }
};




// ---------------- Better Approach ----------------

/*
Intuition: The square root of a number x is the largest integer n such that n^2 <= x.

Approach: 
- Start from 1 and keep increasing the number
- Check whether i*i is less than or equal to x
- Continue until i*i becomes greater than x
- The previous number (i-1) will be the square root

Time Complexity: O(sqrt(x))

Space Complexity: O(1)
*/

class BetterSolution {
public:
    int mySqrt(int x){
        long long i = 1;
        while(i*i <= x) i++;
        return i-1;
    }

};




// ---------------- Optimal Approach ----------------

/*
Intuition: The square root of a number x is the largest integer n such that n^2 <= x. We can use binary search to find this integer efficiently. We will search for the square root in the range from 0 to x. For each mid value, we will check if mid*mid is equal to x, less than x, or greater than x, and adjust our search range accordingly.

Approach:
- Apply Binary Search on range [1, x]
- Find mid value
- If mid*mid <= x: move the low pointer to mid + 1 and update the answer to mid
- Else: move the high pointer to mid - 1
- Final stored answer will be the integer square root

Time Complexity: O(log x)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int mySqrt(int x){
        int ans = 0;
        if(x==0 || x==1) return x;

        int low = 0, high = x;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(mid*mid <= x){
                low = mid+1;
                ans = mid;
            }else{
                high = mid-1;
            }    
        }
        return ans;
    }
};

// ========================================================
//                         Main
// ========================================================

int main() {
    int x;
    cin>>x;

    BruteForceSolution brute;
    cout<<brute.mySqrt(x)<<endl;

    BetterSolution better;
    cout<<better.mySqrt(x)<<endl;

    OptimalSolution optimal;
    cout<<optimal.mySqrt(x)<<endl;

    return 0;
}