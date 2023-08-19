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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp; //(x, y, val)
        queue<pair<int, pair<int, TreeNode*>>> q;
        q.push({0, {0, root}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second.first;
            TreeNode* curr = it.second.second;
            mp[x][y].insert(curr -> val);

            if(curr -> left){
                q.push({x - 1, {y + 1, curr -> left}});
            }
            if(curr -> right){
                q.push({x + 1, {y + 1, curr -> right}});
            }
        }

        vector<vector<int>> ans;

        for(auto it : mp){
            vector<int> cols;
            for(auto q : it.second){
                cols.insert(cols.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(cols);
        }

        return ans;
    }
};