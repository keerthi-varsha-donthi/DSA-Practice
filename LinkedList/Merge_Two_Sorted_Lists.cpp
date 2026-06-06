/*
Problem: You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

Link: https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150

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
Intuition: Since both linked lists are already sorted, we can repeatedly choose the smaller node from the 2 lists and append it to the merged list. A dummy node is used to simplify handling of the head node.
 
Approach:
1. Create a dummy node and a tail pointer pointing to it.
2. Compare the current nodes of both lists.
3. Attach the smaller node to tail->next.
4. Move the corresponding list pointer forward.
5. Move tail forward.
6. Aftert one list is exhausted, attach the remaining nodes of the other list.
7. Return dummy.next as the head of the merged list.

Time Complexity: O(m+n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while(list1 && list2){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            }else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1) tail->next = list1;
        if(list2) tail->next = list2;

        return dummy.next;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> arr1 = {1, 2, 4};
    vector<int> arr2 = {1, 3, 4};

    ListNode* list1 = createLinkedList(arr1);
    ListNode* list2 = createLinkedList(arr2);

    cout << "List 1: ";
    printLinkedList(list1);

    cout << "List 2: ";
    printLinkedList(list2);

    OptimalSolution obj;

    ListNode* mergedHead = obj.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printLinkedList(mergedHead);

    return 0;
}