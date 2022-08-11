/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits == "")
            return {};
        unordered_map <char, vector<char>> phoneButton = { {'2', {'a', 'b', 'c'}},
                                                           {'3', {'d', 'e', 'f'}},
                                                           {'4', {'g', 'h', 'i'}},
                                                           {'5', {'j', 'k', 'l'}},
                                                           {'6', {'m', 'n', 'o'}},
                                                           {'7', {'p', 'q', 'r', 's'}},
                                                           {'8', {'t', 'u', 'v'}},
                                                           {'9', {'w', 'x', 'y', 'z'}} };
        vector<string> ans;
        
        //bfs(digits, phoneButton, ans);
        dfs(digits, phoneButton, 0, ans);
        return ans;

    }
private:
    void bfs(const string& digits, unordered_map <char, vector<char>>& phoneButton, vector<string>& ans)
    {
        ans.push_back("");

        for (char digit : digits)
        {
            vector<string> tmp;
            for (string s : ans)
            {
                for (char c : phoneButton[digit])
                {
                    tmp.push_back(s + c);
                }           
            }
            ans.swap(tmp);
        }
    }

    void dfs(const string& digits, unordered_map <char, vector<char>>& phoneButton, int level, vector<string>& ans)
    {
        static string cur;
        if (level == digits.length())
        {
            ans.push_back(cur);
            return;
        }

        for (char c : phoneButton[digits[level]])
        {
            cur.push_back(c);
            dfs(digits, phoneButton, level + 1, ans);
            cur.pop_back();
        }
    }
};
// @lc code=end

