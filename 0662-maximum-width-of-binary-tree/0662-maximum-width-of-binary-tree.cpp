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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int n = q.size();
            long long start_idx = q.front().second;
            long long end_idx = q.back().second;
            ans = max(ans, end_idx - start_idx + 1);
            
            for(int i = 0; i < n; i++){
                auto curr = q.front();
                TreeNode* node = curr.first;
                long long no = curr.second - start_idx;
                q.pop();
                if(node -> left){
                    q.push({node -> left, (2 * no + 1)});
                }
                if(node -> right){
                    q.push({node -> right, (2 * no + 2)});
                }
            }
        }

        return ans;
    }
};