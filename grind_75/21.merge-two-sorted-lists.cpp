/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
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
class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode headNode(9999);  //dummy node
        ListNode* head = &headNode;
        ListNode* current = &headNode;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                current->next = l1;               
                l1 = l1->next;
            }
            else
            {
                current->next = l2;               
                l2 = l2->next;                
            }
            current = current->next;
        }

        if (l1 != nullptr)  //l2 has gone through already
            current->next = l1;
        else if (l2 != nullptr) //l1 has gone through already
            current->next = l2;

        head = head->next;  //skip dummy node
        return head;
    }
};
// @lc code=end

