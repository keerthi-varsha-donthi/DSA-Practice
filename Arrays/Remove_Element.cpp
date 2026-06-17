/*
Problem: Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.

Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
 
Constraints:
0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

Link: https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------

/*
Intuition: Whenever the target value is found, remove it from the vector. Since
vector elements are stored contiguously, removing an element causes all 
subsequent elements to shift left.

Approach:
1. Traverse the vector.
2. If nums[i] equals val, erase that element.
3. Decrement i to recheck the current position after shifting.
4. Keep track of the updated size.

Time Complexity: O(n^2)

Space Complexity: O(1)
*/

class BruteForceSolution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = nums.size();
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==val) {
                nums.erase(nums.begin()+i);
                ans--;
                i--;
            }
        }
        return ans;
    }
};




// ---------------- Better Approach ----------------

/*
Intuition: Store all elements that are not equal to val in a temporary vector.
Then copy them back to the original vector.

Approach:
1. Traverse nums.
2. Push every element not equal to val into temp.
3. Copy temp back into nums.
4. Return the size of temp.

Time Complexity: O(n)

Space Complexity: O(n)
*/

class BetterSolution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val) temp.push_back(nums[i]);
        }
        for(int i=0; i<temp.size(); i++){
            nums[i] = temp[i];
        }
        return temp.size();
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: Use 2 pointers to overwrite unwanted elements in-place. The left 
pointer tracks the position where the next valid element should be placed.

Approach:
1. Initialize l=0.
2. Traverse the array using r.
3. If nums[r] is not equal to val:
   - Place nums[r] at nums[l].
   - Increment l.
4. Return l, which represents the count of valid elements.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;

        for(int r = 0; r<nums.size(); r++){
            if(nums[r] != val){
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {3,2,2,3};
    int val = 3;

    OptimalSolution obj;

    int k = obj.removeElement(nums, val);

    cout << "k = " << k << endl;

    cout << "Array: ";
    for(int i = 0; i < k; i++){
        cout << nums[i] << " ";
    }
    
    return 0;
}