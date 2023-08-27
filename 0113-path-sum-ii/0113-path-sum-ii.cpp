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
    void pathSumHelper(TreeNode* root, int targetSum, int &sum, vector<int> &temp, vector<vector<int>> &ans){
        if(root == NULL){
            return;
        }
        sum += root -> val;
        temp.push_back(root -> val);
        if(root -> left == NULL && root -> right == NULL && sum == targetSum){
            ans.push_back(temp);
        }
        pathSumHelper(root -> left, targetSum, sum, temp, ans);
        pathSumHelper(root -> right, targetSum, sum , temp, ans);
        sum -= root -> val;
        temp.pop_back();
    } 
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;
        vector<vector<int>> ans;
        pathSumHelper(root, targetSum, sum, temp, ans);
        return ans;
    }
};