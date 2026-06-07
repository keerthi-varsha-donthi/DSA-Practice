/*
Problem: Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:
Input: head = [2,1], x = 2
Output: [1,2]
 
Constraints:
The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200

Link: https://leetcode.com/problems/partition-list/description/?envType=study-plan-v2&envId=top-interview-150

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
Intuition: We need to rearrange the linked list such that all nodes with values less than x appear before nodes with values greater than or equal to x, while preserving the original relative order within each group.
To achieve this, we create 2 seperate lists:
1. A list containing nodes with values<x.
2. A list containing nodes with values>=x.
After traversing the original list, we connect the smaller list to the larger list and return the head of the combined list.

Approach:
1.Create 2 dummy nodes: smallDummy and largeDummy.
2. Traverse the original list:
    - If current node's value<x, append it to the small list.
    - Otherwise, append it to the large list.
3. Terminate the large list by setting largeList->next = nullptr.
4. Connect the end of the small list to the start of the large list.
5. Return smallDummy.next as the new head.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;

        ListNode smallDummy(0);
        ListNode largeDummy(0);

        ListNode* smallList = &smallDummy;
        ListNode* largeList = &largeDummy;

        ListNode* temp = head;
        while(temp){
            if(temp->val<x){
                smallList->next = temp;
                smallList = smallList->next;
            }else{
                largeList->next = temp;
                largeList = largeList->next;
            }
            temp = temp->next;
        }
        largeList->next = nullptr;
        smallList->next = largeDummy.next;

        return smallDummy.next;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> arr = {1, 4, 3, 2, 5, 2};

    ListNode* head = createLinkedList(arr);

    cout << "Original Linked List: ";
    printLinkedList(head);

    OptimalSolution obj;

    head = obj.partition(head, 3);

    cout << "Partitioned Linked List: ";
    printLinkedList(head);

    return 0;
}