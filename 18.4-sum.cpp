/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        if (nums.size() < 4)    //return when there's less 4 number input
            return {};

        vector<vector<int>> resultSet;
        
        sort(nums.begin(), nums.end());

        if (long(target) < long(nums.at(0)) + long(nums.at(1)) + long(nums.at(2)) + long(nums.at(3)) || long(target) > long(nums.at(nums.size() - 1)) + long(nums.at(nums.size() - 2)) + long(nums.at(nums.size() - 3)) + long(nums.at(nums.size() - 4)))
            return {};
        
        for (auto it = nums.begin(); it != nums.end() - 3; it++)
        {
            if (it != nums.begin() && *it == *(it - 1))  //skip if the current value == the pervious one. prevent the duplicate vector.
                continue;
            int remain3sum = target - *it;

            for (auto it2 = it + 1; it2 != nums.end() - 2; it2++)
            {
                if (it2 != it + 1 && *it2 == *(it2 - 1))  //skip if the current value == the pervious one. prevent the duplicate vector.
                    continue;
                auto left = it2 + 1;
                auto right = nums.end() - 1;
                int remain2sum = remain3sum - *it2;
                
                while (left < right)    //find from left and right
                {
                    //int sum = *it + *it2 + *left + *right;
                    if (remain2sum == *left + *right)
                    {
                        resultSet.push_back({*it, *it2, *left, *right});
                        while (left < right && *right == *(right - 1))    //skip if the current right value == the next right value. prevent the duplicate vector.
                            right--;
                        while (left < right && *left == *(left + 1))  //skip if the current left value == the next left value. prevent the duplicate vector.
                            left++;
                        left++;
                        right--;
                    }

                    else if (remain2sum < *left + *right)   //remain3sum < 2sum(*left + *right), so the 4th value should be smaller
                        right--;

                    else    //remain2sum < 2sum(*left + *right), so the 3rd value should be bigger
                        left++;                
                }
            }
        }
        return resultSet;
    }        

};
// @lc code=end

