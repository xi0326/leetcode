/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<string>& logs)
    {
        int operations = 0;

        for (string& command : logs)
        {
            if (command == "../")
                // if it is already in main folder, remain it in main folder
                operations = operations ? operations - 1 : 0;
            else if (command == "./")
                continue;
            else
                ++operations;
        }

        return operations;
    }
};
// @lc code=end

