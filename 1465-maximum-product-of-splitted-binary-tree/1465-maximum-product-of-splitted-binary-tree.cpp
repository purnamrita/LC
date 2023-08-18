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
    int totalSum(TreeNode* root){
        if(root == NULL){
           return 0;
        }
        return root -> val + totalSum(root -> left) + totalSum(root -> right);
    }

    int dfs(TreeNode* root, long long &ans, int &sum, int total){
        if(!root){
            return 0;
        }
        int subSum = root -> val + dfs(root -> left, ans, sum, total) + dfs(root -> right, ans, sum, total);
        ans = max(ans, (subSum * (long long)(total - subSum)));
        return subSum;
    }

    int maxProduct(TreeNode* root) {
        long long ans = INT_MIN;
        int sum = 0;
        int total = totalSum(root);
        dfs(root, ans, sum, total);
        return ans % 1000000007;
    }
};