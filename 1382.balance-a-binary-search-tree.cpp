/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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
    TreeNode* balanceBST(TreeNode* root)
    {
        inorder_traversal(root);
        TreeNode* new_root = reconstruct(0, sorted_node_array.size() - 1);
        return new_root;
    }
private:
    vector<TreeNode*> sorted_node_array;

    // inorder traversal in BST can get the value ascending
    void inorder_traversal(TreeNode* node)
    {
        if (node != nullptr)
        {
            inorder_traversal(node->left);
            sorted_node_array.push_back(node);
            inorder_traversal(node->right);
        }
    }

    TreeNode* reconstruct(int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = this->sorted_node_array[mid];
        root->left = reconstruct(left, mid - 1);
        root->right = reconstruct(mid + 1, right);

        return root;
    }
};
// @lc code=end

