/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        multiset<int> numberSet;
        ListNode* headNode = new ListNode(9999);    //dummy node
        ListNode* head = headNode;
        ListNode* current = headNode;

        for (int i = 0; i < lists.size(); i++)   //traverse all the lists
        {
            ListNode* temp = lists.at(i);

			while(temp != nullptr)
            {
				numberSet.insert(temp->val);    //store lists in multiset
				temp = temp->next;
            }
        }
        
        for (int i : numberSet) //create a new sorted list
        {
            ListNode* newNode = new ListNode(i);
            current->next = newNode;
            current = current->next;
        }
        
        current = head;
        head = head->next;  //skip dummy node
        delete current; //delete dummy node
        current = nullptr;

        return head;
        
    }
};
// @lc code=end

