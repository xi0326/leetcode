/*
 * @lc app=leetcode id=2192 lang=cpp
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges)
    {
        // vector<vector<int>> ancestors(n), child(n);
        this->ancestors.resize(n);
        this->child.resize(n);

        for (vector<int>& edge : edges)
            this->child[edge[0]].push_back(edge[1]);

        // go through all vertices
        for (int i = 0; i < n; ++i)
            dfs(i, i);

        return this->ancestors;
    }

private:
    vector<vector<int>> ancestors, child;
    void dfs(int vertex, int curr)
    {
        for (int child : this->child[curr])
        {
            if (this->ancestors[child].empty() || this->ancestors[child].back() != vertex)
            {
                // add the vertex to child's ancestor
                this->ancestors[child].push_back(vertex);
                dfs(vertex, child);
            }
        }
    }
};
// @lc code=end

