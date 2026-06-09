/*
Problem: Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: Use a slinding window to maintain a substring with unique characters.
As we expand the window using the right pointer, we store the most recent index
of each character. If a character repeats within the current window, move the 
left pointer to one position after its previous occurrence. This ensures the 
window always contains unique characters.

Approach:
1. Use 2 pointers: left and right to represent the current window.
2. Store the last seen index of each character in hashmap.
3. For each character at right:
    - If it has appeared before, move left to max(left, lastSeenIndex+1).
    - Update the character's latest index.
    - Update the maximum window length.
4. Return the maximum length obtained.

Time Complexity: O(n)

Space Complexity: 
*/

class OptimalSolution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        unordered_map<char, int> mp;
        int length = 0;


        for(int right=0; right<n; right++){
            if(mp.find(s[right]) != mp.end()) 
                left = max(left,mp[s[right]]+1);

            mp[s[right]] = right;
            length = max(length, right-left+1);
        }
        return length;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    OptimalSolution obj;

    string s = "abcabcbb";

    cout << "Length of Longest Substring Without Repeating Characters = "
         << obj.lengthOfLongestSubstring(s) << endl;

    
    return 0;
}