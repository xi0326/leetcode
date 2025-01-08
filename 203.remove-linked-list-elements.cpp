/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val)
    {
        while (head != nullptr && head->val == val)
            head = head->next;

        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr)
        {
            if (current->val == val)
            {
                prev->next = current->next;
                delete current;
            }
            else
                prev = current;

            current = prev->next;
        }
        return head;
        
    }
};
// @lc code=end

