/*
Problem: Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:
1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

Link: https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: The length of the last word is unaffected by any words before it.
Starting from the end of the string, first skip all trailing spaces. Then count
consecutive non-space characters until a space or the beginning of the string is 
reached.

Approach:
1. Start from the last index of the string.
2. Skip all trailing spaces.
3. Count characters while they are not spaces.
4. Return the count.

Time Complexity: O(n) in the worst case.

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1;
        int cnt = 0;

        while(n>=0 && s[n] == ' ') n--;

        while(n>=0 && s[n] != ' '){
            cnt++;
            n--;
        }

        return cnt;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    OptimalSolution sol;

    string s1 = "Hello World";
    string s2 = "   fly me   to   the moon  ";
    string s3 = "luffy is still joyboy";
    string s4 = "a";

    cout << sol.lengthOfLastWord(s1) << endl; // 5
    cout << sol.lengthOfLastWord(s2) << endl; // 4
    cout << sol.lengthOfLastWord(s3) << endl; // 6
    cout << sol.lengthOfLastWord(s4) << endl; // 1
    
    return 0;
}