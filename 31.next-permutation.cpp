/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.size() <= 2)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int k;  //the index which need to be swapped

        for (k = nums.size() - 2; k >= 0 ; k--) //find the number which need to be swapped
        {
            if (nums.at(k) < nums.at(k + 1))    //if it's not increasing from the bottom
                break;
        }
        
        if (k >= 0)
        {
            for (int i = nums.size() - 1; i > k; i--)   //traverse from the bottom to k+1
            {
                if (nums.at(i) > nums.at(k))    //search the number which is just bigger than nums[k]
                {
                    swap(nums.at(i), nums.at(k));
                    break;
                }
            }
            reverse(nums.begin() + k + 1, nums.end());  //reverse from k+1 to the end
        }
        else    //if k is not found(every number is incresing from the bottom)
            reverse(nums.begin(), nums.end());
           
    }
};
// @lc code=end

