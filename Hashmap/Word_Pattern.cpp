/*
Problem: Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
 

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Explanation:
The bijection can be established as:
'a' maps to "dog".
'b' maps to "cat".

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

Constraints:
1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.

Link: https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: A valid pattern requires a one-to-one mapping between pattern 
characters and words in the string. If a character has already been mapped, 
it must always map to the same word, and similarly, a word must always map 
back to the same character.

Approach:
1. Use 2 hash maps:
   - map: stores character -> word mapping.
   - mmap: stores word -> character mapping.
2. Traverse the pattern and extract words from string one by one.
3. If there are fewer words than pattern characters, return false.
4. For each pattern character and extracted word:
   - Check whether an existing mapping conflicts with the current pair.
   - If a conflict exists, return false.
   - Otherwise, store/update the mappings.
5. After processing the pattern, check if any extra words remain in the string.
   If so, return false.
6. If all mappings are consistent, return true.

Time Complexity: O(n+m)

Space Complexity: O(k) where k is the number of distinct pattern characters and words.
*/

class OptimalSolution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        unordered_map<char, string> map;
        unordered_map<string, char> mmap;

        int j =0;
        for(int i=0; i<n; i++){

            if(j>=s.size()) return false;

            string word;
            while(j<s.size() && s[j] != ' ') word += s[j++];
            j++;

            if(map.count(pattern[i]) && map[pattern[i]] != word) return false;
            if(mmap.count(word) && mmap[word] != pattern[i]) return false;

            map[pattern[i]] = word;
            mmap[word] = pattern[i];
        }

        if(j<s.size()) return false;

        return true;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    OptimalSolution obj;

    string pattern = "abba";
    string s = "dog cat cat dog";

    if(obj.wordPattern(pattern, s))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    
    return 0;
}