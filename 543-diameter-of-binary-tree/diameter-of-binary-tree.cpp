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
    int ans = 0;
    int height(TreeNode* root)
    {
        if(root == nullptr) return -1;

        int left_h = height(root->left);
        int right_h = height(root->right);

        ans =  max(left_h + right_h +2 ,ans);
        return max(left_h+1,right_h+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       height(root);
       return ans; 
    }
};