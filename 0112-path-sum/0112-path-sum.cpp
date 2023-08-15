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
    bool helper(TreeNode* root, int targetSum, int sum){
        if(root == NULL){
            return false;
        }
        sum += root -> val;
        if(root -> left == NULL && root -> right == NULL && sum == targetSum){
            return true;
        }
        int left = helper(root -> left, targetSum, sum);
        if(left){
            return true;
        }
        int right = helper(root -> right, targetSum, sum);
        if(right){
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        return helper(root, targetSum, 0);
    }
};