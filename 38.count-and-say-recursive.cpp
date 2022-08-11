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
            string str = countAndSay(n - 1);    //recursive

            string ans = "";
            int left = 0;
            int right = 0;
            int count = 0;

            while (left < str.size())
            {
                if (right == str.size() || str[left] != str[right]) //read to the end or find the string is not concatenate
                {
                    ans = ans + to_string(count) + str[left];
                    count = 0;
                    left = right;   //read to the end or find the string is not concatenate
                }

                else
                {
                    count++;
                    right++;
                }
            }
            
            return ans;
        }
        
    }
};
// @lc code=end

