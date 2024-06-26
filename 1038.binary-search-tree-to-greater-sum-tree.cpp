/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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
    TreeNode* bstToGst(TreeNode* root)
    {
        update_node(root);
        return root;
    }

private:
    int sum = 0;
    void update_node(TreeNode* node)
    {
        if (node != nullptr)
        {
            // traverse to the biggest node
            update_node(node->right);
            this->sum += node->val;
            node->val = this->sum;
            update_node(node->left);
        }
        
    }
};
// @lc code=end

