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
    void makeParentFindStart(TreeNode* root, int start, TreeNode* &startNode, unordered_map<TreeNode*, TreeNode*> &mparent){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr -> val == start){
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

    void timeTaken(TreeNode* startNode, unordered_map<TreeNode*, TreeNode*> &mparent, int &time, unordered_map<TreeNode*, bool> &vis){
        queue<TreeNode*> q;
        q.push(startNode);
        vis[startNode] = 1;

        while(!q.empty()){
            int qsize = q.size();

            for(int i = 0; i < qsize; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> left && !vis[curr -> left]){
                    vis[curr -> left] = 1;
                    q.push(curr -> left);
                }
                if(curr -> right && !vis[curr -> right]){
                    vis[curr -> right] = 1;
                    q.push(curr -> right);
                }
                if(mparent[curr] && !vis[mparent[curr]]){
                    vis[mparent[curr]] = 1;
                    q.push(mparent[curr]);
                }
            }

            time++;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        int time = 0;
        TreeNode* startNode = NULL;
        unordered_map<TreeNode*, TreeNode*> mparent;
        unordered_map<TreeNode*, bool> vis;
        makeParentFindStart(root, start, startNode, mparent);
        timeTaken(startNode, mparent, time, vis);
        return time - 1;
    }
};