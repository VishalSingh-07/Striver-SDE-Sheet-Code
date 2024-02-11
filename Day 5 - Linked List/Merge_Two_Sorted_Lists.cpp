/*
21. Merge Two Sorted Lists
Easy

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

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
// Time complexity -> O(n+m) and Space -> O(n+m)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }

        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;

        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val>list2->val)
            {
                ListNode *newNode=new ListNode(list2->val);
                temp->next=newNode;
                list2=list2->next;
                temp=temp->next;
            }
            else
            {
                ListNode *newNode=new ListNode(list1->val);
                temp->next=newNode;
                list1=list1->next;
                temp=temp->next;
            }
        }
        while(list1!=NULL)
        {
            ListNode *newNode=new ListNode(list1->val);
            temp->next=newNode;
            list1=list1->next;
            temp=temp->next;
        }
        while(list2!=NULL)
        {
            ListNode *newNode=new ListNode(list2->val);
            temp->next=newNode;
            list2=list2->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};



// Optimized Approach
// Time complexity -> O(n+m) and Space -> O(1)
// where n=number of nodes in list1 and m=number of nodes in list2 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }

        if(list1->val>list2->val)
        {
            swap(list1,list2);
        }
        ListNode *res=list1;

        while(list1!=NULL && list2!=NULL)
        {
            ListNode *temp=NULL;
            while(list1!=NULL && list1->val<=list2->val)
            {
                temp=list1;
                list1=list1->next;
            }
            temp->next=list2;

            // swapping
            swap(list1,list2);
        }
        return res;

    }
};


/*
1. Question link -- https://leetcode.com/problems/merge-two-sorted-lists/

2. Solution link -- https://leetcode.com/problems/merge-two-sorted-lists/solutions/3381613/striver-solution-easy-c-solution-brute-force-and-optimized-approach-with-explanation

3. Video Link -- https://youtu.be/Xb4slcp1U38
*/