/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */

// @lc code=start
class Solution
{
public:

    bool bfs(int vertex, vector<vector<int>>& graph, vector<int>& colours, int colour)
    {
        colours[vertex] = colour;
        queue<int> q;
        q.push(vertex);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto it : graph[front])
            {
                if (colours[it] == -1)
                {
                    q.push(it);
                    colours[it] = !colours[front];
                }
                else
                {
                    if (colours[it] == colours[front])
                        return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        vector<int> colours(n, -1);
        vector<vector<int>> graph(n);

        // create adjacency list
        for (auto dislike : dislikes)
        {
            graph[dislike[0] - 1].emplace_back(dislike[1] - 1);
            graph[dislike[1] - 1].emplace_back(dislike[0] - 1);
        }

        for (int i = 0; i < n; ++i)
        {
            if (colours[i] == -1)
            {
                if (bfs(i, graph, colours, 0) == false)
                    return false;
            }
        }
        
        return true;
    }
};
// @lc code=end

