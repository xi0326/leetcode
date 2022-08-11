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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *ans = new ListNode(0);
        ListNode *ptr = ans;
        int carry = 0;
        while (l1 != NULL || l2 != NULL)
        {
            int a = (l1 == NULL) ? 0 : l1->val; //if current of first list is not null, get the value
            int b = (l2 == NULL) ? 0 : l2->val; //if current of first list is not null, get the value
            int value = a + b + carry;
            carry = 0;
            if (value < 10) //carry no needed
            {
                ptr->val = value;
            }
            else    //carry needed
            {
                carry = value / 10;
                ptr->val = value % 10;
            }
            
            if (l1) //if the current of first list is not null
            {
                if (l1->next)   //if the current has next
                    l1 = l1->next;
                else    //if the current has no next
                    l1 = NULL;
            }

            if (l2) //if the current of second list is not null
            {
                if (l2->next)   //if the current has next
                    l2 = l2->next;
                else    //if the current has no next
                    l2 = NULL;
            }
            
            if (l1 != NULL || l2 != NULL)   //if creating a new node is needed
            {
                ListNode *ptrNext = new ListNode(0);
                ptr->next = ptrNext;
                ptr = ptr->next;
            }
            
        }
        if (carry != 0) //if the final sum of nodes greater than 10, wee need to carry to next node
        {
            ListNode *ptrNext = new ListNode(carry);
            ptr->next = ptrNext;
            ptr = ptr->next;
        }
        return ans;
    }
};