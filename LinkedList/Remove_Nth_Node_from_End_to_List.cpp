/*
Problem: Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-interview-150

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



// ---------------- Better Approach ----------------

/*
Intuition:  To remove the nth node from the end, first deterrmine the total length of the linked list. Once the lenght is known, the position of the node to be removed from the beginning can be calculated.

Approach:
1. Traverse the linked list to find its length.
2. If the head itself is need to be removed (length ==n), return head->next.
3. Find the node just before the target node: position = length - n - 1.
4. Update the links to skip the target node.
5. Delete the removed node and return the head.

Time Complexity: O(sz) where sz is the length of the linked list.
Space Complexity: O(1)
*/

class BetterSolution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }

        if(cnt==n) return head->next;

        int num = cnt-n-1;
        temp = head;
        while(num--) temp = temp->next;

        ListNode* rem = temp->next;
        temp->next = temp->next->next;
        delete rem;

        return head;
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: Maintain a gap of n nodes between 2 pointers. When the fast pointer reaches the end of the list, the slow pointer will be positioned just before the node that needs to be removed.

Approach:
1. Create a dummy node pointing to the head;
2. Initialize slow and fast pointers at the dummy node.
3. Move fast n steps ahead.
4. Move both pointers together until fast reaches the last node.
5. slow->next will be the node to be removed.
6. Update links, delete the node, and return dummy.next.

Time Complexity: O(sz) where sz is the length of the linked list.
Space Complexity: O(1)
*/

class OptimalSolution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        for(int i=0; i<n; i++) fast = fast->next;

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* rem = slow->next;
        slow->next = slow->next->next;

        delete rem;
        return dummy.next;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};

    ListNode* head = createLinkedList(arr);

    cout << "Original Linked List: ";
    printLinkedList(head);

    BetterSolution better;
    OptimalSolution optimal;

    ListNode* result1 = better.removeNthFromEnd(head, 2);

    cout << "Better: ";
    printLinkedList(result1);

    // Recreate list because it was modified
    head = createLinkedList(arr);

    ListNode* result2 = optimal.removeNthFromEnd(head, 2);

    cout << "Optimal: ";
    printLinkedList(result2);

    return 0;
}