/*
Problem:
Link:

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: Since the array is sorted, duplicate elements appear consecutively.
We are allowed to keep at most 2 occurences of each element. To decide whether 
the current element can be kept, compare it with the element placed 2 positions
before the current write position.

Approach:
1. If the array size is less than 2, return its size.
2. Initialize l=2 because the first 2 elements can always remain.
3. Traverse the array from index 2 using r pointer.
4. If nums[r] is different from nums[l-2]:
    - Place nums[r] at nums[l].
    - Increment l.
5. Return l, whcih represents the length of the modified array.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();

        int l = 2;
        for(int r=2; r<nums.size(); r++){
            if(nums[l-2] != nums[r]){
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> nums = {1,1,1,2,2,3};

    OptimalSolution obj;

    int k = obj.removeDuplicates(nums);

    cout << "k = " << k << endl;

    cout << "Array: ";
    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    
    return 0;
}