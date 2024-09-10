/*
 * @lc app=leetcode id=2326 lang=cpp
 *
 * [2326] Spiral Matrix IV
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head)
    {
        vector<vector<int>> matrix(m, vector<int> (n, -1));
        // four boundaries
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (head != nullptr && top <= bottom && left <= right)
        {
            // fill top row
            for (int i = left; i <= right && head != nullptr; ++i)
            {
                matrix[top][i] = head->val;
                head = head->next;
            }
            // adjust the boundary of top
            ++top;

            // fill right column
            for (int i = top; i <= bottom && head != nullptr; ++i)
            {
                matrix[i][right] = head->val;
                head = head->next;
            }
            // adjust the boundary of right
            --right;

            // fill bottom row
            for (int i = right; i >= left && head != nullptr; --i)
            {
                matrix[bottom][i] = head->val;
                head = head->next;
            }
            // adjust the boundary of bottom
            --bottom;

            // fill left column
            for (int i = bottom; i >= top && head != nullptr; --i)
            {
                matrix[i][left] = head->val;
                head = head->next;
            }
            // adjust the boundary of left
            ++left;
        }

        return matrix;
    }
};
// @lc code=end

