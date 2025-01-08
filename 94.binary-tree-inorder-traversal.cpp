/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> inorder;
        stack<TreeNode*> temp;

        TreeNode* current = root;

        while (current != nullptr || !temp.empty())
        {
            while (current != nullptr)  // go left
            {
                temp.push(current);
                current = current->left;
            }
            current = temp.top();
            temp.pop();
            inorder.emplace_back(current->val);
            current = current->right;
            
        }

        return inorder;
        

    }
};
// @lc code=end

