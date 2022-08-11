/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int index = binarySearch(nums, target);

        if (index == -1)    // target not found
            return {-1, -1};

        return findTwoBound(nums, index);
    }

private:
    int binarySearch(const vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int middle = (left + right) / 2;

            if (nums.at(middle) == target)
                return middle;

            else if (nums.at(middle) < target)
                left = middle + 1;

            else    //mums.at(middle) > target
                right = middle - 1;
            
        }
        return -1;  //target not found
    }
    
    vector<int> findTwoBound(const vector<int>& nums, int index)
    {
        int start = index;
        int end = index;
        int target = nums.at(index);
        
        while (start > 0 && nums.at(start - 1) == target)   //search the left bound of target
            start--;

        while (end < nums.size() - 1 && nums.at(end + 1) == target) //search the right bound of target
            end++;
        
        return {start, end};
    }
};
// @lc code=end

