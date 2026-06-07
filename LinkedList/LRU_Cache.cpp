/*
Problem: Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 
Constraints:
1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put.

Link: https://leetcode.com/problems/lru-cache/description/?envType=study-plan-v2&envId=top-interview-150

*/

#include <bits/stdc++.h>
using namespace std;

// ========================================================
//                     ListNode Definition
// ========================================================

class Node{
public:
    int key;
    int value; 
    Node* prev;
    Node* next;

    Node(int k, int v){
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void remove(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insert(Node* node){
       node->prev = tail->prev;
       node->next = tail;

       tail->prev->next = node;
       tail->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        Node* node = mp[key];
        remove(node);
        insert(node);

        return node->value; 
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;

            remove(node);
            insert(node);

            return;
        }
        Node* node = new Node(key, value);
        mp[key] = node;
        insert(node);

        if(mp.size()>cap){
            Node* lru = head->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};


// ========================================================
//                         Main
// ========================================================

int main() {

    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    cout << cache.get(1) << endl; // 1

    cache.put(3, 3);

    cout << cache.get(2) << endl; // -1

    cache.put(4, 4);

    cout << cache.get(1) << endl; // -1
    cout << cache.get(3) << endl; // 3
    cout << cache.get(4) << endl; // 4

    return 0;
}

