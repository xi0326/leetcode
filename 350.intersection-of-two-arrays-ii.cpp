/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        // sort the arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> intersection;
        int index1 = 0, index2 = 0;

        // find intersection
        while (index1 < nums1.size() && index2 < nums2.size())
        {
            if (nums1[index1] == nums2[index2])
            {
                intersection.emplace_back(nums1[index1]);
                ++index1;
                ++index2;
            }
            else if (nums1[index1] < nums2[index2])
                ++index1;
            else    // nums1[index1] > nums2[index2]
                ++index2;
        }
        
        return intersection;
    }
};
// @lc code=end

