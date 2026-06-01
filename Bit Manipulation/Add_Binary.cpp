/*
Problem: Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

Link: https://leetcode.com/problems/add-binary/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: Binary addition follows the same process as decimal addition. Startin from the LSBs, add corresponding bits along with any carry from the previous position. Store the result bit and propagate the carry forward.

Approach:
1. Use 2 pointers starting from the ends of both strings.
2. Maintain a carry variable.
3. Add the current bits and carry.
4. Append (sum%2) to the answer.
5. Update carry=sum/2.
6. Continue until both strings and carry are exhausted.
7. Reverse the constructed answer and return it.

Time Complexity: O(max(i, j))

Space Complexity: O(max(i, j))
*/

class OptimalSolution {
public:
    string addBinary(string a, string b){
        string ans = "";
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;

        while(i>=0 || j>=0 || carry){
            int sum = carry;

            if(i>=0) sum += a[i--]-'0';
            if(j>=0) sum += b[j--]-'0';

            ans.push_back((sum%2)+'0');
            carry = sum/2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    string a = "1010";
    string b = "1011";

    OptimalSolution obj;

    cout << obj.addBinary(a, b) << endl;

    return 0;
}