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
    TreeNode* create_parent_mapping_and_find_start_node(TreeNode* root, map<TreeNode*, TreeNode*> &parent, int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr -> val == start){
                res = curr;
            }

            if(curr -> left){
                parent[curr -> left] = curr;
                q.push(curr -> left);
            }
            if(curr -> right){
                parent[curr -> right] = curr;
                q.push(curr -> right);
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> parent; // (node, parent)
        TreeNode* start_node = create_parent_mapping_and_find_start_node(root, parent, start);
        int time = 0;
        map<TreeNode*, bool> visited;
        visited[start_node] = 1;

        queue<TreeNode*> q;
        q.push(start_node);

        while(!q.empty()){
            int flag = 0;
            int n = q.size();

            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left && !visited[curr -> left]){
                    visited[curr -> left] = 1;
                    q.push(curr -> left);
                    flag = 1;
                }
                if(curr -> right && !visited[curr -> right]){
                    visited[curr -> right] = 1;
                    q.push(curr -> right);
                    flag = 1;
                }
                if(parent.find(curr)!=parent.end() && !visited[parent[curr]]){
                    visited[parent[curr]] = 1;
                    q.push(parent[curr]);
                    flag = 1;
                }
            }

            if(flag){
                time++;
            }

        }

        return time;
    }
};