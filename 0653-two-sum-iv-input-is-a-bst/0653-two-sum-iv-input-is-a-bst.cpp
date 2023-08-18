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
    bool dfs(TreeNode* root, unordered_set<int> &s, int k){
        if(root == NULL){
            return false;
        }
        int target = k - root -> val;
        if(s.find(target) != s.end()){
            return true;
        }
        s.insert(root -> val);
        return dfs(root -> left, s, k) || dfs(root -> right, s, k);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return dfs(root, s, k);
    }
};