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
    void helper(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> temp, int sum){
        if(root == NULL){
            return;
        }
        temp.push_back(root -> val);
        sum += root -> val;
        if(root -> left == NULL && root -> right == NULL && sum == targetSum){
            ans.push_back(temp);
        }
        helper(root -> left, targetSum, ans, temp, sum);
        helper(root -> right, targetSum, ans, temp, sum);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        helper(root, targetSum, ans, {}, 0);
        return ans;
    }
};