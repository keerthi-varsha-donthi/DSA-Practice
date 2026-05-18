/*
Problem: Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:
-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104

Link: https://leetcode.com/problems/powx-n/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- Brute Force ----------------

/*
Intuition: To calculate x raised to power n, we can multiply x by itself exactly n times.

Approach: We can initialize a variable ans to 1 and then multiply it by x in a loop that runs n times. If n is negative, we can take the reciprocal of x and make n positive before the loop.

Time Complexity: O(n) where n is the power to which x is raised.

Space Complexity: O(1).
*/

class BruteForceSolution {
public:
    double myPow(double x, int n){

        double ans = 1;
        long long power = abs((long long)n);
        for(int i=0; i<power; i++){
            ans *= x;
        }
        if(n < 0) ans = (double)(1.0) / ans;
        return ans;
    }
};




// ---------------- Better Approach ----------------

/*
Intuition: Negative powers can be handled beforehand by converting: x^(-n) = 1/(x^n). This way we can work with positive powers only.

Approach: 
- Store n in long long to handle INT_MIN safely
- If n is negative:
    - Take the reciprocal of x
    - Make n positive
- Multiply x repeatedly power times
- Return the result

Time Complexity: O(n) where n is the power to which x is raised.

Space Complexity: O(1).
*/

class BetterSolution {
public:
    double myPow(double x, int n){
        double ans = 1;
        long long power = n;

        if(power < 0){
            x = 1/x;
            power = -power;
        }
        for(int i=0; i<power; i++){
            ans *= x;
        }
        return ans;
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: Instead of multiplying x repeatedly, we can reduce computations using Bianry Exponentiation.
If power is even: x^n = (x*x)^(n/2)
If power is odd: x^n = x * (x)^(n-1)
This reduces the power by half in every step.

Approach:
- Convert negative power into positive
- Use Binary Exponentiation:
    - If power is odd, multiply ans by x
    - Square x and halve the power
- Continue until power becomes zero

Time Complexity: O(log n) where n is the power to which x is raised.

Space Complexity:
*/

class OptimalSolution {
public:
    double myPow(double x, int n){
        long long power = n;
        double ans = 1;

        if(power<0){
            x=1/x;
            power = -power;
        }

        while(power){
            if(power%2 == 1) ans = ans * x;
            x = x*x;
            power = power/2;
        }
        return ans;
    }
};

// ========================================================
//                         Main
// ========================================================

int main() {
    double x;
    int n;

    cin>>x>>n;

    BruteForceSolution bfs;
    BetterSolution bes;
    OptimalSolution ops;   
    cout<<"Brute Force Solution: "<<bfs.myPow(x, n)<<endl;
    cout<<"Better Solution: "<<bes.myPow(x, n)<<endl;
    cout<<"Optimal Solution: "<<ops.myPow(x, n)<<endl;
    

    return 0;
}