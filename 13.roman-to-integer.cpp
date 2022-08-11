/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string str) 
    {
        unordered_map<char, int> table = { {'I', 1},
                                           {'V', 5},
                                           {'X', 10},
                                           {'L', 50},
                                           {'C', 100},
                                           {'D', 500},
                                           {'M', 1000} };

        int sum = 0;

        for (int i = 0; i <= str.length() - 1; i++) //count from front (roman)
        {
            if (i == str.length() - 1 || table[str.at(i + 1)] <= table[str.at(i)])  //add the last roman digit without preconditions
            {
                sum += table[str.at(i)];
            }
            else
            {
                sum -= table[str.at(i)];
            }
            
        }
        

        return sum;

    }
};
// @lc code=end

