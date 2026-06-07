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


// ---------------- Optimal Approach ----------------

/*
Intuition: Instead of using extra space to store nodes, reverse each complete
group of k nodes directly by changing the links between nodes.
After reversing a group, reconnect it to the previous and next 
parts of the list. Any remaining nodes fewer than k are left unchanged.

Approach:
1. Create a dummy node before the head.
2. Use groupPrev to track the node before the current group.
3. Find the kth node from groupPrev.
4. If fewer than k nodes reamin, stop.
5. Store the node after the kth node as groupNext.
6. Reverse the current group using the standard linked-list reversal technique.
7. Connect the reversed group back to the list.
8. Move groupPrev to the tail of the newly reversed group.
9. Repeat until all complete groups are processed.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    ListNode* getKthNode(ListNode* curr, int k){
        while(curr && k--) curr = curr->next;
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while(true){
            ListNode* kth = getKthNode(groupPrev, k);

            if(!kth) break;

            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while(curr != groupNext){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }
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

    OptimalSolution obj;

    int k = 2;

    ListNode* result = obj.reverseKGroup(head, k);

    cout << "After Reversing in Groups of " << k << ": ";
    printLinkedList(result);


    return 0;
}