/*
 * @lc app=leetcode id=2058 lang=cpp
 *
 * [2058] Find the Minimum and Maximum Number of Nodes Between Critical Points
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        if (head->next == nullptr || head->next->next == nullptr)
            return {-1, -1};

        ListNode* left = head;
        ListNode* middle = head->next;
        ListNode* right = head->next->next;
        int position = 2;
        int first_position = -1, previous_position = -1;
        vector<int> ans = {-1, -1};


        while (right != nullptr)
        {
            if ((left->val < middle->val && right->val < middle->val) || (left->val > middle->val && right->val > middle->val))
            {
                if (first_position == -1)
                    first_position = position;

                // at least 2 critical points
                if (previous_position != -1)
                {   
                    ans[1] = position - first_position; // max distance
                    // min distance
                    if (ans[0] == -1)
                        ans[0] = position - previous_position;
                    else
                        ans[0] = min(ans[0], position - previous_position);
                }
                previous_position = position;
            }
            
            ++position;
            left = middle;
            middle = right;
            right = right->next;
        }
        return ans;
        
    }
};
// @lc code=end