/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start
class Solution
{
public:
    int getLucky(string s, int k)
    {
        string converted_string;

        for (char c : s)
            converted_string += to_string(c - 'a' + 1);

        for (int i = 0; i < k; ++i)
        {
            int converted_int = 0;
            for (char c : converted_string)
                converted_int += c - '0';

            converted_string = to_string(converted_int);
        }

        return stoi(converted_string);
    }
};
// @lc code=end

