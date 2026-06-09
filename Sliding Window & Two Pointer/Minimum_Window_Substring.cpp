/*
Problem: Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.

Link: https://leetcode.com/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: Use a sliding window to maintaina substring that contains all the 
characters required by t. Expand the window using the right pointer untill all
required characters are present with correct frequencies. Once the window 
becomes valid, shrink it from left as much as possible while maintaining validity
to obtain the minimum-length window.

Approach:
1. Build a frequency map(need) for characters in t.
2. Use another frequency map(window) to store frequencies of characters in 
   the current window. 
3. Expand the window bby moving the right pointer:
    - Add the current character to window.
    - If a character's required frequency is satisfied, increment formed.
4. When formed==required:
    - Update the minimum window length.
    - Shrink the window from the left.
    - If removing a character makes window invalid, decrement formed.
5. Return the smallest valid substring found.

Time Complexity: O(n)

Space Complexity: O(k)
*/

class OptimalSolution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for(char c: t) need[c]++;

        int required = need.size();
        int formed = 0;

        int left = 0;

        int minLen = INT_MAX;
        int startIdx = 0;

        for(int right=0; right<s.size(); right++){
            char ch = s[right];
            window[ch]++;

            if(need.count(ch) && window[ch]==need[ch]) formed++;

            while(formed == required){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    startIdx = left;
                }

                char leftChar = s[left];

                window[leftChar]--;

                if(need.count(leftChar) && window[leftChar]<need[leftChar]) formed--;

                left++;
            }
        }
        return minLen==INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    OptimalSolution obj;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << obj.minWindow(s, t) << endl;
    
    return 0;
}