/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() == 1)
            return 1;

       vector<int>::iterator cur = nums.begin();
       vector<int>::iterator next = nums.begin() + 1;

       while (next != nums.end())
       {
           if (*cur == *next)   //skip the duplicate
           {
               next++;
               continue;
           }
           if (*cur != *next)   //update the value
           {
               *(cur + 1) = *next;
           }
           cur++;
           next++;
       }

       return cur - nums.begin() + 1;
    }
};
// @lc code=end

