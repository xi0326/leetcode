/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution
{
public:
    bool bfs(int vertex, vector<vector<int>>& graph, vector<int>& colours, int colour)
    {
        // draw the vertex
        colours[vertex] = colour;
        queue<int> q;
        q.push(vertex);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto it : graph[front])
            {
                // if the neighbour is not coloured
                if (colours[it] == -1)
                {
                    // draw the vertex with an opposite colour
                    colours[it] = !colours[front];
                    q.push(it);
                }
                else
                {
                    // same colour
                    if (colours[it] == colours[front])
                        return false;
                }
            }
        }
        return true;
    }

    bool dfs(int vertex, vector<vector<int>>& graph, vector<int>& colours, int colour)
    {
        // draw the vertex
        colours[vertex] = colour;
        stack<int> s;
        s.push(vertex);

        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            for (auto it : graph[top])
            {
                // if the neighbour is not coloured
                if (colours[it] == -1)
                {
                    // draw the vertex with an opposite colour
                    colours[it] = !colours[top];
                    s.push(it);
                }
                else
                {
                    // same colour
                    if (colours[it] == colours[top])
                        return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        // initialise
        vector<int> colours(graph.size(), -1);

        for (int i = 0; i < graph.size(); ++i)
        {
            if (colours[i] == -1)
            {
                if (dfs(i, graph, colours, 0) == false)
                    return false;
            }
        }

        return true;
    }
};
// @lc code=end

