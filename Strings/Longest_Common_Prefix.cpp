/*
Problem: Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.

Link: https://leetcode.com/problems/longest-common-prefix/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: The longest common prefix of all strings must also be a prefix
of the first string. Start with the first index as the current answer and
compare it with every other string. After each comparison, keep only the
common prefix. The remaining prefix after all comparisons is the longest
common prefix.

Approach:
1. Initialize ans as the first string.
2. For each string in the vector:
    - Compare it character by character with ans.
    - Build a temporary string containing matching characters.
    - Update ans with this common prefix.
3. Return ans after processing all strings.

Time Complexity: O(N*M) where N is length of vector 
                              M is the length of shortest string

Space Complexity: O(M) for the temporary string used to store the answer
*/

class OptimalSolution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for(auto str : strs){
            string word;

            int i=0;      

            while(i<ans.size() && i<str.size() && ans[i]==str[i]){
                word += ans[i];
                i++;
            }

            ans = word;
        }

        return ans;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    OptimalSolution sol;

    vector<string> strs = {"flower", "flow", "flight"};

    cout << sol.longestCommonPrefix(strs) << endl;
    
    return 0;
}