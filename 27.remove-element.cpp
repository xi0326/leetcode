/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        if (nums.size() == 0)   //return when nums.size() is equal to 0
            return 0;

        vector<int>::iterator current = nums.begin();
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums.at(i) != val)  //current only moves when the value of cursor is not equal to val
                *current++ = nums.at(i);
        }
        
        return current - nums.begin();
    }
};
// @lc code=end