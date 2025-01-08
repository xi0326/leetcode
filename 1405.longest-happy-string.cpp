/*
 * @lc app=leetcode id=1405 lang=cpp
 *
 * [1405] Longest Happy String
 */

// @lc code=start
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> pq;
        string ans = "";

        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});
        
        while (!pq.empty())
        {
            // get the char with the most count
            auto [most_count, most_char] = pq.top();
            pq.pop();

            string consecutive(2, most_char); 
            // check if the last 2 chars in the ans are the same
            if (ans.length() >= 2 && ans.substr(ans.length() - 2) == consecutive)
            {
                // no valid chars left
                if (pq.empty())
                    break;
                
                // get the char with second most count
                auto [second_count, second_char] = pq.top();
                pq.pop();

                // add the char to avoid consecutive repetition
                ans += second_char;
                --second_count;

                if (second_count > 0)
                    pq.push({second_count, second_char});

                // push the most frequent char back
                pq.push({most_count, most_char});
            }
            else
            {
                ans += most_char;
                --most_count;

                if (most_count > 0)
                    pq.push({most_count, most_char});
            }
        }
        return ans;
    }
};
// @lc code=end

