/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int>& nums, int target) //binary search
    {
        if (target < nums.at(0))    //if target less than the first element
            return 0;
        
        if (target > *(nums.end() - 1)) //if target greater than the first element
            return nums.size();
        
        int left = 0;
        int right = nums.size() -1;

        while (left <= right)
        {
            int middle = (left + right) / 2;

            if (target == nums.at(middle))
                return middle;

            if (target < nums.at(middle))
                right = middle - 1;

            if (target > nums.at(middle))
                left = middle + 1;
        }
        
        return left;    //left is always less than the target (target not found)
    }
};
// @lc code=end

