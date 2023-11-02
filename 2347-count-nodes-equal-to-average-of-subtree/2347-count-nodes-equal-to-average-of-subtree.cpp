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
    pair<int, int> helper(TreeNode* root, int &match){
        if(root == NULL){
            return {0, 0};
        }

        pair<int, int> left = helper(root -> left, match);
        pair<int, int> right = helper(root -> right, match);

        int sum = left.first + right.first + root -> val;
        int cnt = left.second + right.second + 1;

        if(round((sum) / cnt) == root -> val){
            match++;
        }
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        int match = 0;
        helper(root, match);
        return match;
    }
};