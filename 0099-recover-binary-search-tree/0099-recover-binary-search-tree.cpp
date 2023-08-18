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
    void inorderTraversal(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        inorderTraversal(root -> left, ans);
        ans.push_back(root -> val);
        inorderTraversal(root -> right, ans);
    }
    void recover(TreeNode* root, vector<int> &inorder, int &idx){
        if(root == NULL){
            return;
        }
        recover(root -> left, inorder, idx);
        if(root -> val != inorder[idx]){
            root -> val = inorder[idx];
        }
        idx++;
        recover(root -> right, inorder, idx);
    }
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        sort(inorder.begin(), inorder.end());
        int idx = 0;
        recover(root, inorder, idx);
    }
};