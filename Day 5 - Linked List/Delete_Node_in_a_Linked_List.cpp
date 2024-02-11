/*
237. Delete Node in a Linked List

There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

- The value of the given node should not exist in the linked list.
- The number of nodes in the linked list should decrease by one.
- All the values before node should be in the same order.
- All the values after node should be in the same order.

Custom testing:

- For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
- We will build the linked list and pass the node to your function.
- The output will be the entire list after calling your function.
 

Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.


Example 2:

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
 

Constraints:

- The number of the nodes in the given list is in the range [2, 1000].
- -1000 <= Node.val <= 1000
- The value of each node in the list is unique.
- The node to be deleted is in the list and is not a tail node.

*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


// ----------------------



// Optimized Approach
// Time complexity -> O(1) and Space -> O(1)
class Solution {
public:
    void deleteNode(ListNode* node) { 

        // Create a pointer to the next node after the one to be deleted
        ListNode* nextNode = node->next;

        // Copy the value of the next node into the node to be deleted
        node->val = nextNode->val;

        // Update the next pointer of the node to be deleted to skip over the next node
        node->next = nextNode->next;

        // Set the next pointer of the next node to null
        nextNode->next=nullptr;

        // Free the memory occupied by the next node
        delete nextNode;
    }
};

// OR

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};


/*
1. Question link -- https://leetcode.com/problems/delete-node-in-a-linked-list/

2. Solution link -- https://leetcode.com/problems/delete-node-in-a-linked-list/solutions/3361475/optimized-approach-easy-c-solution-t-c-o-1-and-s-c-o-1-with-comments

3. Video Link -- https://youtu.be/icnp4FJdZ_c
*/