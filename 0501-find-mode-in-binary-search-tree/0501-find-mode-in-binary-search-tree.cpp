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
    void preorder(TreeNode* root, map<int, int> &mp){
        if(root == NULL){
            return;
        }
        mp[root -> val]++;
        preorder(root -> left, mp);
        preorder(root -> right, mp);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        map<int, int> mp;
        int maxi = 0;
        preorder(root, mp);
        for(auto it : mp){
            int num = it.first;
            int cnt = it.second;
            maxi = max(maxi, cnt);
        }
        for(auto it : mp){
            if(it.second == maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};