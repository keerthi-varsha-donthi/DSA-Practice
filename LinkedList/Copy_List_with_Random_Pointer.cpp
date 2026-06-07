/*
Problem: A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 
Constraints:
0 <= n <= 1000
-10^4 <= Node.val <= 10^4
Node.random is null or is pointing to some node in the linked list.

Link: https://leetcode.com/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ========================================================
//                     ListNode Definition
// ========================================================

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// ========================================================
//                    Helper Functions
// ========================================================

// Create Linked List from vector
Node* createLinkedList(vector<int>& arr) {
    if(arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i = 1; i < arr.size(); i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

// Print Linked List
void printLinkedList(Node* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}



// ---------------- Better Approach ----------------

/*
Intuition: Use a hashmap to maintain a mapping between each original node and its corresponding copied node. Once all copied nodes are created, the map allows direct access to assign next and random pointers.

Approach:
1. Traverse the original list and create a copy of every node.
2. Store the mapping: original node -> copied node
3. Traverse the list again.
4. Use map to connect:
    copy->next = copy of original->next
    copy->random = copy of original->random
5. Return the copy corresponding to the original head.

Time Complexity: O(N)

Space Complexity: O(n)
*/

class BetterSolution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while(temp){
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        
        return mp[head];
    }
};




// ---------------- Optimal Approach ----------------

/*
Intuition: Instead of storing the mapping in a hashmap, insert each copied node immediately after its original node. This makes the copy of any node accessible through original->next. Random pointers can then be assigned without extra space, and finally the original and copied lists are seperated.

Approach:
1. Insert a copied node after every original node.
2. Assign random pointers: copy->random = original->random->next.
3. Separate the interleaved list into: original list ans Copied list
4. Return the head of the copied list.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class OptimalSolution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        curr = head;
        while(curr){
            if(curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        Node* dummy = new Node(-1);
        Node* tail = dummy;
        curr = head;

        while(curr){
            Node* copy = curr->next;
            tail->next = copy;

            curr->next = curr->next->next;
            curr = curr->next;

            tail = tail->next;
        }

        return dummy->next;
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n1->random = nullptr;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    OptimalSolution obj;

    Node* copiedHead = obj.copyRandomList(n1);

    cout << "Copied List:\n";

    Node* temp = copiedHead;

    while(temp) {

        cout << "Value: " << temp->val << ", Random: ";

        if(temp->random)
            cout << temp->random->val;
        else
            cout << "NULL";

        cout << endl;

        temp = temp->next;
    }

    return 0;
}