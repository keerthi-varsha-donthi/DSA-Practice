/*
Problem: Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000

Link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-interview-150

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