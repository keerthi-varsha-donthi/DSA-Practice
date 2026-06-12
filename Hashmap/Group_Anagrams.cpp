/*
Problem: Given an array of strings strs, group the anagrams together. You can return the answer in any order.


Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

Link: https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Better Approach ----------------

/*
Intuition: Two strings are anagrams if they contain the same characters with
the same frequencies. Sorting anagrams produces the same string, which can be
used as a unique key.

Approach:
1. Traverse each string in the input.
2. Create a copy of the string and sort it.
3. Use the sorted string as a key in a hash map.
4. Store all original strings having the same sorted key in the same group.
5. Traverse the hash map and collect all groups into the answer vector.

Time Complexity: O(n * k log k)
where n = number of strings
      k = average length of a string

Space Complexity: O(n*k)
*/

class BetterSolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> mp;
        for(auto str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());

            mp[temp].push_back(str);
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: Instead of sorting each string, use the frequency of the 26 lowercase
English letters as a unique signature. Anagrams will always have the same 
frequency signature.

Approach:
1. Traverse each string.
2. Create a frequency array of size 26.
3. Count occurences of each character.
4. Convert the frequency array into a unique key string.
5. Use this key in a hash map to group anagrams.
6. Collect all groups from the hash map and return them.

Time Complexity: O(n*k)

Space Complexity: O(n*k)
*/

class OptimalSolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto str : strs){
            vector<int> freq(26, 0);
            
            for(auto c : str) freq[c-'a']++;

            string key;

            for(int count : freq){
                key += "#" + to_string(count);
            }

            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<string> strs = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };

    BetterSolution better;
    OptimalSolution optimal;

    auto ans1 = better.groupAnagrams(strs);
    auto ans2 = optimal.groupAnagrams(strs);

    cout << "Better Solution Groups: " << ans1.size() << endl;
    cout << "Optimal Solution Groups: " << ans2.size() << endl;

    return 0;
}