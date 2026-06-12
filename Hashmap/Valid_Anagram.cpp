/*
Problem: Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 
Link: https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------

/*
Intuition: If 2 strings are anagrams, every character must appear the same 
number of times in both strings. Count the frequency of characters in each 
string separately and compare the frequencies.

Approach:
1. If the lenghts are different, return false.
2. Create 2 hash maps to store character frequencies.
3. Traverse both strings and update their respective frequency maps.
4. Compare the frequency of each character in both maps.
5. If any frequency differs, return false.
6. Otherwise, return true.

Time Complexity: O(n)

Space Complexity: O(k) where k is the number of distinct characters.
*/

class BruteForceSolution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;
        
        unordered_map<char, int> map, mmap;
        for(int i=0; i<n; i++){
            map[s[i]]++;
            mmap[t[i]]++;
        }

        if(map.size() != mmap.size()) return false;

        for(auto it : map){
            if(mmap[it.first] != it.second) return false;
        }

        return true;
    }
};




// ---------------- Better Approach ----------------

/*
Intuition: Instead of maintaining 2 seperate frequency maps, a single map can
track the difference in frequencies between the 2 strings.

Approach:
1. If the lengths are different, return false.
2. Traverse the first string and increment the frequency of each character.
3. Traverse the second string and decrement the frequency of each character.
4. If the strings are anagrams, all frequencies should become zero.
5. Check the map and return false if any frequency is non-zero.
6. Otherwise, return true.

Time Complexity: O(n)

Space Complexity: O(k) where k is the number of distinct characters.
*/

class BetterSolution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, int> map;
        for(char c : s) map[c]++;
        for(char c : t) map[c]--;

        for(auto it : map){
            if(it.second != 0) return false;
        }

        return true;
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: Since the string contain only lowercase English letters, a fixed-size
array of length 26 can be used instead of a hash map to store frequencies.

Approach:
1. If the lengths are different, return false.
2. Create a frequency array of size 26 initialized to zero.
3. Traverse the first string and increment the corresponding frequency.
4. Traverse the second string and decrement the corresponding frequency.
5. If the strings are anagrams, all frequencies will become zero.
6. Check the array and return false if any value is non-zero.
7. Otherwise, return true.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        vector<int> freq(26, 0);
        for(char c : s) freq[c-'a']++;
        for(char c : t) freq[c-'a']--;

        for(auto it : freq){
            if(it != 0) return false;
        }

        return true;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    string s = "anagram";
    string t = "nagaram";

    BruteForceSolution brute;
    BetterSolution better;
    OptimalSolution optimal;

    cout << "Brute Force: "
         << (brute.isAnagram(s, t) ? "true" : "false") << endl;

    cout << "Better: "
         << (better.isAnagram(s, t) ? "true" : "false") << endl;

    cout << "Optimal: "
         << (optimal.isAnagram(s, t) ? "true" : "false") << endl;
         
    return 0;
}