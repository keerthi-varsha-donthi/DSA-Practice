/*
Problem: You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity. 

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

Link: https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: The matrix can be treated as a sirted 1D array because each row is sorted and the first element of a row is greater than the last element of the previous row. Therefore, binary search can be applied directly on the entire matrix. 

Approach: 
1. Consider the matrix as a flattened sorted array of size m*n.
2. Apply binary search on indices [0, m*n-1].
3. Convert the middle index into row and column: row=mid/n
                                                 col=mid%n
4. Compare matrix[row][col] with target.
5. Return true if found, otherwise false.

Time Complexity: O(log(m*n))

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m*n-1;

        while(left<=right){
            int mid = ((right-left)/2)+left;
            int row = mid/n;
            int col = mid%n;

            if(matrix[row][col]==target) return true;
            if(matrix[row][col]>target) right = mid-1;
            else left = mid+1;
        }
        return false;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    OptimalSolution obj;

    if (obj.searchMatrix(matrix, target))
        cout << "Target found" << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}