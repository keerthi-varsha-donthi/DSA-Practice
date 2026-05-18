/*
Problem: Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3

Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 

Constraints:
1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.

Link: https://leetcode.com/problems/max-points-on-a-line/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;


// ---------------- Optimal Approach ----------------

/*
Intuition: If multiple points have the same slope with respect to a fixed anchor point, then all those points lie on the same straight line.

Approach: 
- Take each point as an anchor point
- Compute slope with every other point
- Store slope frequency in hashmap
- Use reduced fraction (dx/gcd, dy/gcd) to avoid precision issues
- Maximum frequency + anchor point gives answer

Time Complexity: O(n^2)

Space Complexity: O(n)
*/

class OptimalSolution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {

            map<pair<int, int>, int> freq;
            int maxi = 0;

            for (int j = i + 1; j < n; j++) {

                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                int gcd_val = __gcd(dx, dy);

                dx /= gcd_val;
                dy /= gcd_val;

                // Normalize sign
                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                }

                // Vertical line
                if (dx == 0) dy = 1;

                // Horizontal line
                if (dy == 0) dx = 1;

                freq[{dx, dy}]++;
                maxi = max(maxi, freq[{dx, dy}]);
            }
            ans = max(ans, maxi + 1);
        }
        return ans;
    }
};

// ========================================================
//                         Main
// ========================================================

int main() {
    int n;
    cout<<"Enter number of points: ";
    cin>>n;

    vector<vector<int>> points(n, vector<int>(2));
    cout<<"Enter points (x y): "<<endl;
    for (int i = 0; i < n; i++) {
        cin>>points[i][0]>>points[i][1];
    }

    OptimalSolution solution;
    int result = solution.maxPoints(points);
    cout<<"Maximum number of points on a line: "<<result<<endl;

    return 0;
}