/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return root;

        // swap left and right nodes
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // recursive
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
// @lc code=end

