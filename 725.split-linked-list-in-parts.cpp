/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        ListNode* current = head;
        ListNode* prev = nullptr;
        vector<ListNode*> parts(k);
        int count = 0, quotient, remainder;

        // count the length of the linked list
        while (current != nullptr)
        {
            ++count;
            current = current->next;
        }

        quotient = count / k;
        remainder = count % k;
        current = head;

        // spilt the linked list to k parts
        for (int i = 0; i < k; ++i)
        {
            parts[i] = current;
            for (int j = 0; j < quotient; ++j)
            {
                prev = current;
                if (current)
                    current = current->next;
            }   
            if (remainder > 0)
            {
                prev = current;
                if (current)
                    current = current->next;
                --remainder;
            }

            // cut off the rest of linked list
            if (prev)
                prev->next = nullptr;
        }

        return parts;
    }
};
// @lc code=end