/*
Problem: You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 
Constraints:
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

Link: https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------

/*
Intuition: nums1 already has enough space to hold all elements. Copy all 
elements of nums2 into nums1 and sort the entire array.

Approach:
1. Insert nums2 elements at the end of nums1.
2. Sort nums1.

Time Complexity: O((m+n)log(m+n))

Space Complexity: O(1)
*/

class BruteForceSolution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};




// ---------------- Better Approach ----------------

/*
Intuition: Both arrays are already sorted. Use the merge step of Merge sort 
to create a sorted array.

Approach:
1. Use 2 pointers i and j for nums1 and nums2.
2. Compare elements and push the smaller one into a temporary array.
3. Copy remaining elements from either array.
4. Copy the merged array back to nums1.

Time Complexity: O(m+n)

Space Complexity: O(m+n)
*/

class BetterSolution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i = 0;
        int j = 0;

        while(i<m && j<n){
            if(nums1[i]<=nums2[j]) ans.push_back(nums1[i++]);
            else ans.push_back(nums2[j++]);
        }
        while(i<m) ans.push_back(nums1[i++]);
        while(j<n) ans.push_back(nums2[j++]);

        for(int i=0; i<m+n; i++){
            nums1[i] = ans[i];
        }
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: The last n positions of nums1 are empty. Instead of shifting elements, 
fill num1 from the end and where space is available.

Approach:
1. left points to the last valid element of num1.
2. right points to the last valid element of nums2.
3. temp points to the last position of nums1.
4. Place the larger element at temp and move pointers backward.
5. Copy any remaining elements of nums2.

Time Complexity: O(m+n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1;
        int right = n-1;

        int temp = m+n-1;

        while(temp>=0 && left>=0 && right>=0){
            if(nums1[left]<=nums2[right]) nums1[temp--] = nums2[right--];
            else nums1[temp--] = nums1[left--];
        }
        while(temp>=0 && left>=0){
            nums1[temp--] = nums1[left--];
        }
        while(temp>=0 && right>=0){
            nums1[temp--] = nums2[right--];
        }
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

   vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int m = 3;
    int n = 3;

    OptimalSolution obj;
    obj.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for(int num : nums1){
        cout << num << " ";
    }
    cout << endl;
 
    return 0;
}