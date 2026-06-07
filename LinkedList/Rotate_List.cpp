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



// ---------------- Optimal Approach ----------------

/*
Intuition: Rotating the list to the right by k positions means that the last k nodes become the new prefix of the list. Instead of moving nodes one by one, first connect the tail to the head to form a circular linked list, then break the circle at the correct position to obtain the rotated list.

Approach:
1. Find the length of the linked list and the last node. 
2. Compute the effective rotations: k = k%length
3. If k==0, return the original list.
4. Connect the tail to the head to form a circular linked list.
5. Move to the new tail, which is located at: length-k-1 steps from the head.
6. The node after the new tail becomes the new head.
7. Break the circular link and return the new head.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0) return head;
        
        int cnt = 1;
        ListNode* tail = head;
        while(tail->next){
            cnt++;
            tail=tail->next;
        }

        k = k%cnt;
        if(k==0) return head; 

        tail->next = head;
        ListNode* newTail = head;
        for(int i=0; i<cnt-k-1; i++){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
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

    ListNode* rotatedHead = obj.rotateRight(head, 2);

    cout << "Rotated Linked List: ";
    printLinkedList(rotatedHead);

    return 0;
}