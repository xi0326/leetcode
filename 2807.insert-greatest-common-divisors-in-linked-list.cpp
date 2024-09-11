/*
 * @lc app=leetcode id=2807 lang=cpp
 *
 * [2807] Insert Greatest Common Divisors in Linked List
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
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        ListNode *first = nullptr;
        ListNode *second = nullptr;

        // no any node
        if (head != nullptr)
            first = head;
        else 
            return head;

        // only one node
        if (first->next != nullptr)
            second = first->next;
        else
            return head;

        while (first != nullptr && second != nullptr)
        {
            ListNode* temp = new ListNode();
            temp->val = gcd(first->val, second->val);

            // link the nodes
            first->next = temp;
            temp->next = second;

            // shift to next 2 nodes
            first = second;
            second = second->next;
        }

        return head;
    }
};
// @lc code=end

