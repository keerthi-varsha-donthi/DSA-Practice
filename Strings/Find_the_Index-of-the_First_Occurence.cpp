/*
Problem: Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 
Constraints:
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
 
Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------

/*
Intuition: Check every possible starting position in the haystack and 
try to match the entire needle character by character. If all characters
match, return the starting index.

Approach:
1. Iterate through each index of the haystack.
2. Treat the current index as a potential starting position.
3. Compare characters of haystack and needle one by one.
4. If the entire needle matched, return the starting index.
5. If no match is found, return -1.

Time Complexity: O((n - m + 1) * m) ≈ O(n*m)

Space Complexity: O(1)
*/

class BruteForceSolution {
public:
    int strStr(string haystack, string needle) {
        
        for(int i=0; i<haystack.size(); i++){

            int j=0;
            int num = i;

            while(i<haystack.size() && j<needle.size() && haystack[i] == needle[j]){
                i++;
                j++;
                if(j==needle.size()) return num;
            }

            i = num;
        }

        return -1;
    }
};




// ---------------- Better Approach ----------------

/*
Intuition: Use the built-in string searching function provided by C++ STL
to find the first occurence of the needle in the haystack.

Approach:
1. Use haystack.find(needle).
2. If the substring exists, return its index.
3. Otherwise, find() returns string::npos, so return -1.

Time Complexity: O(n+m)

Space Complexity: O(1)
*/

class BetterSolution {
public:
    int strStr(string haystack, string needle) {
        int pos = haystack.find(needle);
        return pos==string::npos ? -1 : pos;
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: When a mismatch occurs after matching several characters, 
restarting from the next position wastes previous work. KMP uses the 
LPS(Longest Prefix Suffix) array to reuse information about previously
matched characters and avoid redundant comparisons.

Approach:
1. Build the LPS array for the needle:
    - lps[i] stores the length of the longest proper prefix which is
      also a suffix for the substring needle[0.....i].
2. Use two pointers:
    - i for haystack 
    - j for needle
3. If characters match, move both pointers.
4. If a mismatch occurs:
    - if j>0, jump j to lps[j-1].
    - otherwise move i forward.
5. If j reached needle.size(), a complete match is found.
6. Return the starting index of the match.
7. If no match exists, return -1.

Time Complexity: O(n+m)

Space Complexity: O(m)
*/

class OptimalSolution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();

        // Step 1: Build LPS
        vector<int> lps(m, 0);
        int prev = 0, i = 1;

        while (i < m) {
            if (needle[i] == needle[prev]) {
                lps[i++] = ++prev;
            } else if (prev == 0) {
                lps[i++] = 0;
            } else {
                prev = lps[prev - 1];
            }
        }

        // Step 2: Search
        i = 0;
        int j = 0;

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++; j++;
            } else {
                if (j == 0) i++;
                else j = lps[j - 1];
            }

            if (j == m) return i - m;
        }

        return -1;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    string haystack = "sadbutsad";
    string needle = "sad";

    BruteForceSolution brute;
    BetterSolution better;
    OptimalSolution optimal;

    cout << "Brute Force: "
         << brute.strStr(haystack, needle) << endl;

    cout << "Better: "
         << better.strStr(haystack, needle) << endl;

    cout << "Optimal (KMP): "
         << optimal.strStr(haystack, needle) << endl;
    
    return 0;
}