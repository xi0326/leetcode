/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        //if (nums.size() < 3)  since the constraint "3 <= nums.length <= 10^3"
            //return {};

        sort(nums.begin(), nums.end());

        int closestDiff = __INT_MAX__;  //set a large closest diff between target

        for (auto it = nums.begin(); it != nums.end() - 2; it++)
        {
            auto left = it + 1;
            auto right = nums.end() - 1;

            while (left < right)
            {
                int sum = *it + *left + *right;

                if (sum == target)
                    return sum;

                else if (sum < target)
                    left++;

                else
                    right--;

                if (abs(sum - target) < abs(closestDiff))   //update the closest difference
                {
                    closestDiff = sum - target;
                }
            }            
        }

        return target + closestDiff;
    }
};
// @lc code=end

