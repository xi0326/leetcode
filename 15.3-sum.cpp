/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if (nums.size() < 3)    //return when there's less 3 number input
            return {};

        vector<vector<int>> resultSet;
        
        sort(nums.begin(), nums.end());
        
        for (int it = 0; it < nums.size() - 2; it++)
        {
            if (it != 0 && nums.at(it) == nums.at(it - 1))  //skip if the current value == the pervious one. prevent the duplicate vector.
                continue;
            
            int left = it + 1;
            int right = nums.size() - 1;
            
            while (left < right)    //find from left and right
            {
                int sum = nums.at(it) + nums.at(left) + nums.at(right);
                if (sum == 0)
                {
                    resultSet.push_back({nums.at(it), nums.at(left), nums.at(right)});
                    while (left < right && nums.at(right) == nums.at(right - 1))    //skip if the current right value == the next right value. prevent the duplicate vector.
                        right--;
                    while (left < right && nums.at(left) == nums.at(left + 1))  //skip if the current left value == the next left value. prevent the duplicate vector.
                        left++;
                    left++;
                    right--;
                }

                else if (sum > 0)   //sum > 0, so the 3rd value should be smaller
                    right--;

                else    //sum < 0, so the 2nd value should be bigger
                    left++;                
            }                      
        }

        return resultSet;
    }
};
// @lc code=end

