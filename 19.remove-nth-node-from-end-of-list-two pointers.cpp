/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* previous = head;
        ListNode* behind = head;

        for (int i = 0; i < n; i++)
            previous = previous->next;
        
        if (previous == nullptr)    //previous == nullptr equals removing head
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        else
        {
            while (previous->next != nullptr)   //the distance between previous and behind equals n
            {
                previous = previous->next;
                behind = behind->next;
            }
            ListNode* tmp = behind->next;   //behind precedes the target
            behind->next = behind->next->next;
            delete tmp;
        }

        return head;
    }
};
// @lc code=end

