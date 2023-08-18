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
    void inorder(TreeNode* root, multiset<int> &mp){
        if(root == NULL){
            return;
        }
        inorder(root -> left, mp);
        mp.insert(root -> val);
        inorder(root -> right, mp);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        multiset<int> mp;
        inorder(root1, mp);
        inorder(root2, mp);
        vector<int> ans;
        for(auto ele : mp){
            ans.push_back(ele);
        }
        return ans;
    }
};