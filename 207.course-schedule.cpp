/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> needs(numCourses, 0);

        for (auto req : prerequisites)
        {
            ++needs[req[0]];
            graph[req[1]].emplace_back(req[0]);
        }

        queue<int> q;

        // the courses has no prerequisites
        for (int i = 0; i < numCourses; ++i)
        {
            if (needs[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (int i = 0; i < graph[front].size(); ++i)
            {
                --needs[graph[front][i]];
                // check if the course can be selected
                if (needs[graph[front][i]] == 0)
                    q.push(graph[front][i]);
            }
        }
        
        // check if all of needs is 0
        for (auto need : needs)
        {
            if (need != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

