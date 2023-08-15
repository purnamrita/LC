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
    void countGoodNodes(TreeNode* root, int &ans, int maxTillHere){
        if(root == NULL){
            return;
        }
        if(root -> val >= maxTillHere){
            ans++;
            maxTillHere = root -> val;
        }
        countGoodNodes(root -> left, ans, maxTillHere);
        countGoodNodes(root -> right, ans, maxTillHere);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        countGoodNodes(root, ans, root -> val);
        return ans;
    }
};