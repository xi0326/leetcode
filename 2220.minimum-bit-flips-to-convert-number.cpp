/*
 * @lc app=leetcode id=2220 lang=cpp
 *
 * [2220] Minimum Bit Flips to Convert Number
 */

// @lc code=start
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int count = 0;

        // utilizing XOR to get different bits
        int different_bits = start ^ goal;
    
        // Count the number of 1's in the XOR result
        while (different_bits > 0)
        {
            // check if the least significant bit is 1 with AND
            count += different_bits & 1;
            // right shift to check the next bit
            different_bits >>= 1;
        }

        return count;
    }
};
// @lc code=end

