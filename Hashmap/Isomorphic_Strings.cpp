/*
Problem: Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:
Mapping 'e' to 'a'.
Mapping 'g' to 'd'.

Example 2:
Input: s = "f11", t = "b23"
Output: false
Explanation:
The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.

Example 3:
Input: s = "paper", t = "title"
Output: true 

Constraints:
1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

Link: https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: Two strings are isomorphic if every character in the first string 
maps to exactly one character in the second string and vice versa. To ensure
a one-to-one correspodence, maintain mappings in both directions while traversing
the strings.

Approach:
1. Use 2 hashmaps:
    - map: stores mappings from characters in s to characters in t.
    - mmap: stores mappings from characters in t to characters in s.
2. Traverse both strings simultaneously.
3. If a character already has a mapping and it conflicts with the current character,
   return false.
4. Perform the same check in the reverse direction to prevent multiple characters
   from mapping to the same character.
5. If no conflicts are found, store the mappings and continue.
6. After processing all characters, return true.

Time Complexity: O(n) where n is length of the strings.

Space Complexity: O(k) where k is the number of distinct characters.
*/

class OptimalSolution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> map, mmap;

        for(int i=0; i<n; i++){
            if(map.count(s[i]) && map[s[i]] != t[i]) return false;
            if(mmap.count(t[i]) && mmap[t[i]] != s[i]) return false;

            map[s[i]]=t[i];
            mmap[t[i]]=s[i];
        }
        return true;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    OptimalSolution obj;

    string s = "egg";
    string t = "add";

    if(obj.isIsomorphic(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;
        
    return 0;
}