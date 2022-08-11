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
        ListNode* current = head;
        vector<ListNode*> pointerBox;

        while (current != nullptr)
        {
            pointerBox.push_back(current);
            current = current->next;
        }
        
        if (n == pointerBox.size())    //removing head
            head = head->next;
        
        else if (n == 1)    //removing tail
            pointerBox[pointerBox.size() - 2]->next = nullptr;
        
        else
            pointerBox[pointerBox.size() - n - 1]->next = pointerBox[pointerBox.size() - n + 1];
                
        return head;
    }
};
// @lc code=end

