/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution
{
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int count = 0;
        vector<bool> is_visited(isConnected.size(), false);
        queue<int> q;

        // bfs
        for (int i = 0; i < isConnected.size(); ++i)
        {
            if (!is_visited[i])
            {
                q.push(i);
                is_visited[i] = true;

                while (!q.empty())
                {
                    int x = q.front();
                    q.pop();

                    for (int j = 0; j < isConnected.size(); ++j)
                    {
                        if (!is_visited[j] && isConnected[x][j])
                        {
                            q.push(j);
                            is_visited[j] = true;
                        }
                    }
                }
                ++count;
            }
        }
        
        return count;
    }
};
// @lc code=end