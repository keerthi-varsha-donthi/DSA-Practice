/*
Problem: You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.

Link: https://leetcode.com/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;



// ---------------- Better Approach ----------------

/*
Intuition:
We start checking digits from the last position because adding one
mainly affects the rightmost digit. If a digit becomes 10, we convert
it to 0 and continue carrying forward.

Approach:
- Traverse from right to left
- If digit is 9, make it 0
- Otherwise increment digit and stop
- If first digit becomes 0, it means all digits were 9
- Add an extra 0 at end and make first digit 1

Time Complexity: O(n)

Space Complexity: O(1)
*/

class BetterSolution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i=n-1; i>=0; i--){
            if(digits[i]==9) digits[i] = 0;
            else{
                digits[i] += 1;
                break;
            } 
        }

        if(digits[0] == 0) digits[0] = 1;
        digits.push_back(0);

        return digits;
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition:
Instead of traversing the whole array even after incrementing,
we can immediately return once carry handling is complete.

Approach:
- Traverse from right to left
- If current digit is less than 9:
    increment it and return answer immediately
- Otherwise make digit 0 and continue carry propagation
- If all digits were 9, insert 1 at beginning

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i=n-1; i>=0; i--){
            if(digits[i]==9) digits[i] = 0;
            else{
                digits[i] += 1;
                return digits;
            } 
        }

        digits.insert(digits.begin(), 1);

        return digits;
    }
};

// ========================================================
//                         Main
// ========================================================

int main() {
    int n;
    cin>>n; 

    vector<int> digits(n);
    for(int i=0; i<n; i++) cin>>digits[i];

    BetterSolution better;
    vector<int> result1 = better.plusOne(digits);

    OptimalSolution optimal;
    vector<int> result2 = optimal.plusOne(digits);

    return 0;
}