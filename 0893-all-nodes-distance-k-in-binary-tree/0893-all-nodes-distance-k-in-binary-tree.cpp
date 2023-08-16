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
    void makeParentFindTarget(TreeNode* root, TreeNode* target, TreeNode* &startNode, unordered_map<TreeNode*, TreeNode*> &mparent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == target){
                startNode = curr;
            }
            if(curr -> left){
                mparent[curr -> left] = curr;
                q.push(curr -> left);
            }
            if(curr -> right){
                mparent[curr -> right] = curr;
                q.push(curr -> right);
            }
        }
    }

    void findNodesAtDistK(TreeNode* startNode, int k, vector<int> &ans, unordered_map<TreeNode*, TreeNode*> &mparent, unordered_map<TreeNode*, bool> &vis){
        int curr = 0;
        queue<TreeNode*> q;
        q.push(startNode);
        vis[startNode] = 1;

        while(!q.empty()){
            if(curr == k){
                break;
            }
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left && vis[curr -> left] == 0){
                    vis[curr -> left] = 1;
                    q.push(curr -> left);
                }
                if(curr -> right && vis[curr -> right] == 0){
                    vis[curr -> right] = 1;
                    q.push(curr -> right);
                }
                if(mparent[curr] && vis[mparent[curr]] == 0){
                    vis[mparent[curr]] = 1;
                    q.push(mparent[curr]);
                }
            }
            curr++;
        }

        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        TreeNode* startNode;
        unordered_map<TreeNode*, TreeNode*> mparent;
        unordered_map<TreeNode*, bool> vis;
        makeParentFindTarget(root, target, startNode, mparent);
        findNodesAtDistK(startNode, k, ans, mparent, vis);
        return ans;
    }
};