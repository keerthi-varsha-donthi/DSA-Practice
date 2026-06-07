/*
Problem: Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list. 

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
 
Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

Link: https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=study-plan-v2&envId=top-interview-150

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
Intuition: Store all nodes between positions left and right in a stack. Since stack follows LIFO order, popping nodes from the stack naturally gives them in reverse order. Reconnect the reversed nodes back into the linked list.

Approach:
1. Create a dummy node to handle edge cases.
2. Move to the node just before position left.
3. Push all nodes from left to right into a stack.
4. Pop nodes one by one and reconnect them.
5. Connect the last reversed node to the remaining part of the list.
6. Return dummy.next.

Time Complexity: O(n)

Space Complexity: O(right-left+1)
*/

class BetterSolution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* start = &dummy;

        for(int i=1; i<left; i++){
            start = start->next;
        }

        ListNode* curr = start->next;
        stack<ListNode*> nodes;

        for(int i=left; i<=right; i++){
            nodes.push(curr);
            curr = curr->next;
        }

        while(!nodes.empty()){
            start->next = nodes.top();
            nodes.pop();
            start = start->next;
        }
        start->next = curr;
        return dummy.next;
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: Instead of storing nodes, reverse the sublist in-place by repeatedly taking the node after curr and moving it to the front of the reversing section. This gradually builds the reversed sublist without extra space.

Approach:
1. Create a dummy node before head.
2. Move prev to the node just before position left.
3. Let curr be the first node of the sublist.
4. Repeatedly:
    - Take the node after curr.
    - Remove it from its current position.
    - Insert it immediately after prev.
5. Continue for(right-left) iterations.
6. Return dummy.next.

Time Complexity: O(n)

Space Complexity:O(1)
*/

class OptimalSolution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        for(int i=1; i<left; i++){
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        ListNode* tail = curr->next;

        for(int i=left; i<right; i++){
            ListNode* front = prev->next;
            prev->next = tail;
            curr->next = tail->next;
            tail->next = front;
            tail = curr->next;
        }
        return dummy.next;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    //vector<int> arr = {1, 2, 3, 4, 5};

    ListNode* head = createLinkedList(arr);

    cout << "Original List: ";
    printLinkedList(head);

    BetterSolution better;
    OptimalSolution optimal;

    ListNode* result1 = better.reverseBetween(
        createLinkedList(arr), 2, 4
    );

    cout << "Better: ";
    printLinkedList(result1);

    ListNode* result2 = optimal.reverseBetween(
        createLinkedList(arr), 2, 4
    );

    cout << "Optimal: ";
    printLinkedList(result2);

    return 0;
}