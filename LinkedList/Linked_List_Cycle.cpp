/*
Problem: Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 
Constraints:

The number of the nodes in the list is in the range [0, 104].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked-list.

Link: https://leetcode.com/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-interview-150

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
Intuition: If a cycle exists, a node will be visited more than once while traversing the linked list. By storing the address of each visited node in a hashmap, we can detect when a node is encountered again.

Approach:
1. Traverse the linked list from the head.
2. Store each visited node's address in a hashmap.
3. If a node is already present in the mao, a cycle exists.
4. Otherwise, continue traversing until reaching nullptr.
5. Return false if the traversal finishes without revisiting a node.

Time Complexity: O(n), where n is the number of nodes in the linked list.
Space Complexity: O(n), for storing the visited nodes in the hashmap.
*/

class BetterSolution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, int> mp;
        int cnt = 0;
        while(temp != nullptr){
            cnt++;
            if(mp.find(temp) != mp.end()) return true;
            else mp[temp] = cnt;
            temp = temp->next;
        }
        return false;
    }

};




// ---------------- Optimal Approach ----------------

/*
Intuition: Use 2 pointers moving at different speeds. If a cycle exists, thefast pointer will eventually catch up to the slow pointer inside the cycle. tf no cycle exists, the fast pointer will reach the end of the list. 

Approach:
1. Initialize slow and fast pointers at the head.
2. Move slow one step at a time.
3. Move fast two steps at a time.
4. If slow and fast meet, a cycle exists.
5. If fats reached nullptr, no cycle exists.

Time Complexity: O(n), where n is the number of nodes in the linked list.
Space Complexity: O(1), as only two pointers are used.
*/

class OptimalSolution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);

    //creating a cycle for testing
    head->next->next->next->next = head->next; // creating a cycle

    BetterSolution better;
    OptimalSolution optimal;

    cout << "Better: "
         << (better.hasCycle(head) ? "Cycle Found" : "No Cycle")
         << endl;

    cout << "Optimal: "
         << (optimal.hasCycle(head) ? "Cycle Found" : "No Cycle")
         << endl;

    return 0;
}