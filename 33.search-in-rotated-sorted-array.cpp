/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int middle = (left + right) / 2;
            
            if (target == nums.at(middle))
                return middle;

            // left sorted portion
            if (nums.at(left) <= nums.at(middle))
            {
                if (target > nums.at(middle) || target < nums.at(left)) //target is in the right part
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle - 1;  //target is in the left part
                }  
            }

            // right sorted portion
            else    //if (nums.at(middle) < nums.at(right))
            {
                if (target < nums.at(middle) || target > nums.at(right))    //target is in the left part
                {
                    right = middle - 1;
                }
                else    //target is in the right part
                {
                    left = middle + 1;
                }
            }            
        }
        
        return -1;  //target not found
    }
};
// @lc code=end