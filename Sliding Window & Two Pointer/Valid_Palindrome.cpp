/*
Problem: A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

Link: https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: A palindrome reads the same forward and backward. Since the problem
requires ignoring non-alphanumeric characters and treating uppercase and 
lowercase letters as the same, we can use 2 pointers from both ends of the string. 
We skip invalid characters and compare remaining characters after converting them 
to lowercase.

Approach:
1. Initialize two pointers:
    - left at the beginning of the string.
    - right at the end of the string.
2. Move left forward until it points to an alphanumeric character.
3. Move right backward until it points to an alphanumeric character.
4. Compare the lowercase versions of the characters at left and right.
    - If they differ, return false.
5. Move both pointers inwards and continue.
6. If all valid characters match, return true.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        int left = 0;
        int right = n-1;

        while(left < right){
            while(left<right && !isalnum(s[left])) left++;
            while(left<right && !isalnum(s[right])) right--;

            if(tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    OptimalSolution obj;

    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";

    cout << boolalpha;
    cout << obj.isPalindrome(s1) << endl; // true
    cout << obj.isPalindrome(s2) << endl; // false
    cout << obj.isPalindrome(s3) << endl; // true
    
    return 0;
}