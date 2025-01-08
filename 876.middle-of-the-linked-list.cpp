/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    // int length(ListNode* head)
    // {
    //     int len = 0;
    //     while (head != nullptr)
    //     {
    //         ++len;
    //         head = head->next;
    //     }
    //     return len;
    // }
    // ListNode* middleNode(ListNode* head)
    // {
    //     int list_length = length(head);
    //     int count = 0;
    //     int middle = list_length / 2;

    //     while (count < middle)
    //     {
    //         ++count;
    //         head = head->next;
    //     }

    //     return head;
    // }
    ListNode* middleNode(ListNode* head)
    {
        ListNode *slow = head, *fast = head;

        // when the fast reach the end, the slow is in the middle
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// @lc code=end

