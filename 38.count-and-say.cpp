/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        else
        {
            string ansInEachRound = "";
            string previous ="1";

            for (int i = 1; i < n; i++)
            {
                int left = 0;
                int right = 0;
                int count = 0;

                while (left < previous.size())
                {
                    if (right == previous.size() || previous[left] != previous[right]) //read to the end or find the string is not concatenate
                    {
                        ansInEachRound = ansInEachRound + to_string(count) + previous[left];
                        count = 0;
                        left = right;   //left pointer moves to the next number which is not concatenate
                    }

                    else
                    {
                        count++;
                        right++;
                    }
                }

                previous = ansInEachRound;
                ansInEachRound.clear();
            }

            return previous;
        }
    }
};
// @lc code=end