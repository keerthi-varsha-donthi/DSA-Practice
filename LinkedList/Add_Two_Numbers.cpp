/*
Problem: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

Link: https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150

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
Intuition: Each node represents a digit of a number in reverse order. We simulate the same addition process used in elementary arithmetic: add corresponding digits along with any carry from the previous step. The result digit is stored in a new node and the carry is propagated to the next position.

Approach:
1. Create a dummy node to simplify construction of the result list.
2. Traverse both lists simultaneously.
3. Add the current digits and the carry.
4. Store sum%10 in a new node.
5. Update carry=sum/10.
6. Continue until both lists and carry are exhausted.
7. Return dummy.next as the head of the result list.

Time Complexity: O(max(m, n)) where m and n are the lengths of the two linked lists.

Space Complexity: O(max(m, n)) for the result list.
*/

class OptimalSolution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        int carry = 0;
        while(l1 || l2 || carry){
            int sum = 0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            if(carry) sum += carry;
            
            carry = sum/10;

            tail->next = new ListNode(sum%10);
            tail = tail->next;
        }
        return dummy.next;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> arr1 = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};

    ListNode* l1 = createLinkedList(arr1);
    ListNode* l2 = createLinkedList(arr2);

    cout << "List 1: ";
    printLinkedList(l1);

    cout << "List 2: ";
    printLinkedList(l2);

    OptimalSolution obj;

    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printLinkedList(result);

    return 0;
}