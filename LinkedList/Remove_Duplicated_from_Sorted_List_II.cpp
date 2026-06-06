/*
Problem: Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]
 
Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?envType=study-plan-v2&envId=top-interview-150

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




// ---------------- Optimal Approach ----------------

/*
Intuition: Since the linked list is sorted, duplicate values always appear consecutively. When a duplicate sequence is detected, skip all nodes having that value and connect the previous valid node directly to the next distinct node.

Approach:
1. Create a dummy node pointing to the head to handle edge cases where the head itself needs to be removed.
2. Use prev to track the last confirmed unique node.
3. Use curr to traverse the linked list.
4. If curr starts a duplicate sequence:
    - Store the duplicate value.
    - Skip all nodes having that value.
    - Connect prev->next to the first different node.
5. Otherwise, the current node is unique:
    -Move prev to curr.
    -Move curr forward.
6. Return dummy.next as the head of the modified list.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while(curr) {

            // Duplicate sequence found
            if(curr->next && curr->val == curr->next->val) {

                int value = curr->val;

                while(curr && curr->val == value) {
                    curr = curr->next;
                }

                prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> arr = {1, 2, 3, 3, 4, 4, 5};

    ListNode* head = createLinkedList(arr);

    cout << "Original List: ";
    printLinkedList(head);

    OptimalSolution obj;

    ListNode* result = obj.deleteDuplicates(head);

    cout << "After Removing Duplicates: ";
    printLinkedList(result);

    return 0;
}