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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (k == 1)
            return head;
        
        const int N = getListLength(head);
        ListNode* cur = nullptr;
        ListNode* nxt = nullptr;
        ListNode* prev = nullptr;
        ListNode* tmp = nullptr;
        

        cur = head; //initalise
        nxt = head->next;
        
        for (int i = 0; i < N / k; i++)
        {
            ListNode* front = cur;
            for (int countdown = k; countdown > 1; countdown--)
            {
                tmp = nxt->next;
                nxt->next = cur;
                cur = nxt;
                nxt = tmp;
            }
            
            prev == nullptr ? head = cur : prev->next = cur;
            
            prev = front;
            cur = nxt;

            if (nxt == nullptr)
                break;
            
            nxt = nxt->next;
        }
        prev->next = cur;
        
        return head;
    }

private:
    const int getListLength(ListNode* ptr)    //get the length of linklist
    {
        int count = 0;

        while (ptr != nullptr)
        {
            ptr = ptr->next;
            count++;
        }

        return count;
    }
};
// @lc code=end

