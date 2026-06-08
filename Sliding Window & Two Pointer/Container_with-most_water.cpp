/*
Problem: You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1
 
Constraints:
n == height.length
2 <= n <= 105
0 <= height[i] <= 104

Link: https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Optimal Approach ----------------

/*
Intuition: The amount of water stored is determined by the shorter of the two
lines and the distance between them. Starting witht the widest possible container
(first and last lines), we calculate the area and then move the pointer pointing
to the shorter line. This is beacause the shorter line limits the height of the
container, and moving the taller line cannot increase the area while width is 
decreasing.

Approach:
1. Initialize 2 pointers: 
    - left at the beginning of the array.
    - right at the end of the array.
2. Compute the area formed by the 2 lines: min(height[left], height[right])*(right-left)
3. Update the maximum area found so far.
4. Move the pointer corresponding to the shorter line:
    - If height[left]<height[right], increment left.
    - Otherwise, decrement right.
5. Repeat until the 2 pointers meet.
6. Return the maximum area.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int left = 0;
        int right = height.size()-1;

        while(left<right){
            int mini = min(height[left], height[right]);
            int area = mini*(right-left);

            maxi = max(maxi, area);

            if(height[left]<height[right]) left++;
            else right--;
        }

        return maxi;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    OptimalSolution obj;
    cout<<obj.maxArea(height)<<endl; //49

    return 0;
}