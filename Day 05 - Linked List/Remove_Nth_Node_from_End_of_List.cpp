/*
19. Remove Nth Node From End of List
Medium

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]


Example 2:

Input: head = [1], n = 1
Output: []


Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
*/


#include <bits/stdc++.h>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute Force Approach
// Time complexity -> O(2n) ~ O(n) and Space -> O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *del, *temp=head;
        int count=0;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        if(count==n) // This condition will be true when they asked to delete head
        {
            del=head;
            head=head->next;
            delete del;
            return head;
        }
        del=head; 
        ListNode* prev=NULL;
        int pos=count-n;
        while(pos--)
        {
            prev=del;
            del=del->next;
        }
        prev->next=del->next;
        delete del;
        return head;

    }
};

// Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head,*slow,*del;
        while(n--)
        {
            fast=fast->next;
        }
        if(fast==NULL) // if deleted node is head node, then just return head->next
        {
            return head->next;
        }
        slow=head;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        del=slow->next;
        slow->next=del->next;
        delete del;
        return head;
    }
};

/*
1. Question link -- https://leetcode.com/problems/remove-nth-node-from-end-of-list/

2. Solution link -- https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/3390761/2-approach-easy-c-solution-brute-force-and-optimized-approach

3. Video link --https://youtu.be/3kMKYQ2wNIU
*/