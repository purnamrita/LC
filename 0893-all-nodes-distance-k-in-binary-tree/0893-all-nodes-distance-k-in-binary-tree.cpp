/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent_arr_formation(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr -> left){
                parent.insert({curr -> left, curr});
                q.push(curr -> left);
            }
            if(curr -> right){
                parent.insert({curr -> right, curr});
                q.push(curr -> right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        parent_arr_formation(root, parent);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;

        int dist = 0;
        queue<TreeNode*> q;
        q.push(target);
        while(!q.empty()){
            if(dist == k){
                break;
            }
            dist++;
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left && !visited[curr -> left]){
                    visited[curr -> left] = 1;
                    q.push(curr -> left);
                }
                if(curr -> right && !visited[curr -> right]){
                    visited[curr -> right] = 1;
                    q.push(curr -> right);
                }
                if(parent[curr] && !visited[parent[curr]]){
                    visited[parent[curr]] = 1;
                    q.push(parent[curr]);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr -> val);
        }
        return ans;
    }
};