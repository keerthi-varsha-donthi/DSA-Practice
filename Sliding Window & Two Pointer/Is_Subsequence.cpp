/*
Problem: Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:
0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.

Link: https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: A string s is a subsequence of t if all characters of s appear in the
in the same relative order. We can scan both strings simultaneously and try to
match characters of s with characters in t.

Approach:
1. Use 2 pointer:
    - i for string s.
    - j for string t.
2. Traverse t using j.
3. Whenever s[i] matches t[j], move i to the next character in s.
4. Always move j forward.
5. If i reaches the end of s, all characters of s have been matched in order, 
so return true.
6. Otherwise, return false.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]) i++;
            j++;
        }
        return i==s.size();
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    OptimalSolution obj;

    cout << boolalpha;

    cout << obj.isSubsequence("abc", "ahbgdc") << endl; // true
    cout << obj.isSubsequence("axc", "ahbgdc") << endl; // false
    
    return 0;
}