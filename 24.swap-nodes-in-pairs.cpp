/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        //initialise
        ListNode* pre = nullptr;
        ListNode* first = head;
        ListNode* second = head->next;

        head = second;


        while (first != nullptr && second != nullptr)
        {
            if (pre)
                pre->next = second;
            
            // swap the point
            first->next = second->next;
            second->next = first;
            pre = first;
            first = first->next;

            if (first)
                second = first->next;
        }
        
        return head;
    }
};
// @lc code=end

