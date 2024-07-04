/*
 * @lc app=leetcode id=2181 lang=cpp
 *
 * [2181] Merge Nodes in Between Zeros
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
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode* modiifed_head = nullptr;
        ListNode* current_ptr = nullptr;
        int sum = 0;

        // traverse the list
        while (head != nullptr)
        {
            if (head->val == 0) // meets 0
            {
                if (sum != 0)
                {
                    // create modidied linked list
                    if (modiifed_head == nullptr)
                    {
                        ListNode* new_node = new ListNode(sum);
                        modiifed_head = new_node;
                        current_ptr = modiifed_head;
                    }
                    else
                    {
                        ListNode* new_node = new ListNode(sum);
                        current_ptr->next = new_node;
                        current_ptr = current_ptr->next;
                    }
                }                    
                sum = 0;
            }
                
            else
                sum += head->val;
            head = head->next;  // traverse the list
        }
        
        return modiifed_head;
    }
};
// @lc code=end