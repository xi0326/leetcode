/*
 * @lc app=leetcode id=2096 lang=cpp
 *
 * [2096] Step-By-Step Directions From a Binary Tree Node to Another
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool find(TreeNode* node, int value, string& path)
    {
        if (node->val == value)
            return true;
        else if (node->left && find(node->left, value, path))
            path.push_back('L');
        else if (node->right && find(node->right, value, path))
            path.push_back('R');
        // return found or not found
        return !path.empty();
    }

    string getDirections(TreeNode* root, int startValue, int destValue)
    {
        string start_path, dest_path;

        find(root, startValue, start_path);
        find(root, destValue, dest_path);

        while (!start_path.empty() && !dest_path.empty() && (start_path.back() == dest_path.back()))
        {
            start_path.pop_back();
            dest_path.pop_back();
        }

        // reverse the path and generate 'U'
        return string(start_path.size(), 'U') + string(dest_path.rbegin(), dest_path.rend());
    }

};
// @lc code=end

