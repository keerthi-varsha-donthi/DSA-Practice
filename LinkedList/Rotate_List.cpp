/*
Problem: Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
 
Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9

Link: https://leetcode.com/problems/rotate-list/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ========================================================
//                     ListNode Definition
// ========================================================

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = nullptr;
    }
};

// ========================================================
//                    Helper Functions
// ========================================================

// Create Linked List from vector
ListNode* createLinkedList(vector<int>& arr) {
    if(arr.empty()) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;

    for(int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print Linked List
void printLinkedList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}




// ---------------- Brute Force ----------------

/*
Intuition:

Approach:

Time Complexity:

Space Complexity:
*/

class BruteForceSolution {
public:

};




// ---------------- Better Approach ----------------

/*
Intuition:

Approach:

Time Complexity:

Space Complexity:
*/

class BetterSolution {
public:

};




// ---------------- Optimal Approach ----------------

/*
Intuition:

Approach:

Time Complexity:

Space Complexity:
*/

class OptimalSolution {
public:

};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};

    ListNode* head = createLinkedList(arr);

    cout << "Original Linked List: ";
    printLinkedList(head);

    return 0;
}