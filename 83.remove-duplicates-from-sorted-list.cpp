/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* current = head->next;
        ListNode* prev = head;

        while (current != nullptr)
        {
            // duplicated
            if (prev->val == current->val)
            {
                prev->next = current->next;
                delete current;
            }
            // not duplicated
            else
                prev = prev->next;

            current = prev->next;
        }
        return head;
    }
};
// @lc code=end

