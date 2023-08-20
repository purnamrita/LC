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
    void helper(TreeNode* root, int targetSum, vector<int> &temp, vector<vector<int>> &ans, int &curr){
        if(root == NULL){
            return;
        }
        temp.push_back(root -> val);
        curr += root -> val;
        if(root -> left == NULL && root -> right == NULL && curr == targetSum){
            ans.push_back(temp);
        }
        helper(root -> left, targetSum, temp, ans, curr);
        helper(root -> right, targetSum, temp, ans, curr);
        curr -= root -> val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int curr = 0;
        helper(root, targetSum, temp, ans, curr);
        return ans;
    }
};