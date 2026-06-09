/*
Problem: You are given a string s and an array of strings words. All the strings of words are of the same length.
A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

Example 1:
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation:
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation:
There is no concatenated substring.

Example 3:
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
Explanation:
The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

Constraints:
1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.

Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------

/*
Intuition: A valid substring must have length equal to the total length of all
words combined. For every possible starting index, extract the substring of 
length wordCount*wordLen and split it into word-sized chunks. Count the frequency
of each extracted word and compare it against the required frequency map built
from words.

Approach:
1. Build a frequency map of all words.
2. For every possible starting index:
    - Extract a substring of total required length.
    - Split it into chunks of size wordLen.
    - Build a frequency map for these chunks.
    - If any word is invalid or appears more times than required, stop checking
      the current position.
3. If all words match, add the starting index to the answer.

Time Complexity: O((n - totalLen + 1) * wordCount * wordLen)
≈ O(n * wordCount * wordLen)

Space Complexity: O(wordCount)
*/

class BruteForceSolution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int strSize = s.size();
        int wLen = words[0].size();
        int noWords = words.size();

        int totalLen = wLen*noWords;

        unordered_map<string, int> wordMap;
        for(int i=0; i<noWords; i++) wordMap[words[i]]++;

        for(int i=0; i<=strSize-totalLen; i++){
            string str = s.substr(i, totalLen);

            unordered_map<string, int> mp;
            int j;
            for(j=0; j<noWords; j++){
                string word = str.substr(j*wLen, wLen);

                if(wordMap.find(word) == wordMap.end()) break;
                mp[word]++;

                if(mp[word]>wordMap[word]) break;
            }

            if(j==noWords) ans.push_back(i);
        }
        return ans;
    }
};



// ---------------- Optimal Approach ----------------

/*
Intuition: Since all the words have the same length, the string can be processed
in word-sized chunks rather than character by character. Instead of rebuilding
a frequency map for every starting position, maintain a sliding window of words.
As the window moves, add the new word entering the window and remove the old word 
leaving it. This avoids repeating work.

Approach:
1. Build the target frequency map from words.
2. For each possible offset from 0 to wordLen-1:
    - Use a sliding window where both left and right move in steps of wordLen.
    - Add words entering the window to a frequency map.
    - If a word appears more times than required, shrink the window from the left
      until it becomes valid.
    - Whenevr the window contains exactly wordCount words, record the starting index.
3. Continue until all alignments are processed.

Time Complexity: O(n * wordLen)

Space Complexity: O(number of distinct words)
*/

class OptimalSolution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = s.size();
        int wordCount = words.size();
        int wordLen = words[0].size();

        unordered_map<string, int> target;
        for(auto &word: words) target[word]++;

        //Process each possible alignment
        for(int offset=0; offset<wordLen; offset++){
            int left = offset;
            int count = 0;

            unordered_map<string, int> window;

            for(int right=offset; right+wordLen<=n; right+=wordLen){
                string word = s.substr(right, wordLen);

                //Invalid word encountered
                if(target.find(word) == target.end()){
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                window[word]++;
                count++;

                //Too many occurences of this word
                while(window[word]>target[word]){
                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    count--;
                    left += wordLen;
                }

                //Found a valid concatenation
                if(count == wordCount){
                    ans.push_back(left);

                    //move widnow forward
                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    count--;
                    left += wordLen;
                }
            }
        }
        return ans;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    
    return 0;
}