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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
        if(root -> right && root -> right -> right == root -> right -> left && root -> right -> val == targetSum - root -> val)
            return 1;
        else if(root -> left && root -> left -> right == root -> left -> left && root -> left -> val == targetSum - root -> val)
            return 1;
        else if(root -> left == root -> right && targetSum == root -> val)
            return 1;
        return std::max(hasPathSum(root -> right, targetSum - root -> val),hasPathSum(root -> left, targetSum - root -> val));
    }
};
