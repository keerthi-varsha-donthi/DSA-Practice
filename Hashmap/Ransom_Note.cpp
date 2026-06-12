/*
Problem: Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:
1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.

Link: https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: To construct the ransom note, every character required in ransomNote
must be available in magazine with atleast the same frequency. Count the occurences
of each character in magazine and use those counts while traversing ransomNote.

Approach:
1. Store the frequency of each character from magazine in a hash map.
2. Traverse ransomNote character by character.
3. If the frequency of the current character is 0, it is not available in magazine, 
   so return false.
4. Otherwise, decrement its frequency,
5. If all characters are processed successfully, return true.

Time Complexity: O(n+m)

Space Complexity: O(k) 
where is the number of distinct characters stored in the hash map.
*/

class OptimalSolution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();

        unordered_map<char, int> freq;
        for(auto c : magazine) freq[c]++;

        for(auto c : ransomNote){
            if(freq[c]==0) return false;
            freq[c]--;
        }

        return true;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    OptimalSolution obj;

    string ransomNote = "aa";
    string magazine = "aab";

    if(obj.canConstruct(ransomNote, magazine))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    
    return 0;
}