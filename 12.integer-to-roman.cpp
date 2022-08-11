/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution 
{
public:
    string intToRoman(int num) 
    {
        
        string romanNums[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string romanResult;
        int digitalNums[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};


        for (int i = 0; num > 0; i++)
        {
            while (digitalNums[i] <= num)
            {
                num -= digitalNums[i];
                romanResult += romanNums[i];
            }
        }

        return romanResult;
    }
};
// @lc code=end
