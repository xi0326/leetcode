/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 */

// @lc code=start
class Solution
{
public:
    long long dividePlayers(vector<int>& skill)
    {
        // sort the array
        sort(skill.begin(), skill.end());

        int total_skill = skill.front() + skill.back();
        long long chemistry = 0;

        for (int i = 0; i < skill.size() / 2; ++i)
        {
            // check if the sum of the current pair is equal total_skill or not
            if (skill[i] + skill[skill.size() - i - 1] != total_skill)
            return -1;
            
            chemistry += skill[i] * skill[skill.size() - i - 1];
        }

        return chemistry;
    }
};
// @lc code=end

