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
    void helper(TreeNode* root, int& ans, int sum){
        if(root == NULL){
            return;
        }
        sum = 10 * sum + root -> val;
        if(root -> left == NULL && root -> right == NULL){
            ans += sum;
        }
        helper(root -> left, ans, sum);
        helper(root -> right, ans, sum);
        sum = sum / 10;
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        helper(root, ans, 0);
        return ans;
    }
};