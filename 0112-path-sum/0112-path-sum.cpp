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
    bool hasPathSumHelper(TreeNode* root, int targetSum, int &sum){
        if(root == NULL){
            return false;
        }
        sum += root -> val;
        if(root -> left == NULL && root -> right == NULL && sum == targetSum){
            return true;
        }
        if(hasPathSumHelper(root -> left, targetSum, sum) == true){
            return true;
        }
        if(hasPathSumHelper(root -> right, targetSum, sum) == true){
            return true;
        }
        sum -= root -> val;
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        int sum = 0;
        return hasPathSumHelper(root, targetSum, sum);
    }
};