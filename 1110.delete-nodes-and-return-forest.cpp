/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        del_node(root, to_delete);
        // if root is not deleted
        if (root)
            this->result.emplace_back(root);
        
        return this->result;
    }

private:
    vector<TreeNode*> result;
    
    void del_node(TreeNode* &node, vector<int>& to_delete)
    {
        // dfs
        if (node)
        {
            del_node(node->left, to_delete);
            del_node(node->right, to_delete);

            // if the node is in the deletion list
            if (find(to_delete.begin(), to_delete.end(), node->val) != to_delete.end())
            {
                // push the childs of the node as new roots
                if (node->left)
                    this->result.emplace_back(node->left);
                if (node->right)
                    this->result.emplace_back(node->right);
                node = nullptr;
            }
        }
    }
};
// @lc code=end

